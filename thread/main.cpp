#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <thread>
#include <vector>

using namespace cv;
using namespace std;

void grayscaleThread(const Mat& input, Mat& output, int startRow, int endRow) {

    for(int y = startRow; y < endRow; ++y) {
        for(int x = 0; x < input.cols; ++x) {

            Vec3b pixel = input.at<Vec3b>(y, x);
            uchar gray = 0.299*pixel[2] + 0.587*pixel[1] + 0.114*pixel[0];

            output.at<uchar>(y, x) = gray;
        }
    }
}

int main(int argc, char** argv) {

    // Validaciones omitidas por simplicidad

    Mat image = imread(argv[1], IMREAD_COLOR);
    Mat result(image.size(), CV_8UC1);

    vector<thread> threads;
    int rowsPerThread = image.rows / stoi(argv[3]);

    for(int i = 0; i < stoi(argv[3]); ++i) {

        int startRow = i * rowsPerThread;
        int endRow = (i+1 == stoi(argv[3])) ? image.rows : (i + 1) * rowsPerThread;
        
        threads.emplace_back(grayscaleThread, ref(image), ref(result), startRow, endRow);
    }

    for(auto &t : threads) {
        t.join(); 
    }

    imwrite(argv[2], result);

    return 0;
}
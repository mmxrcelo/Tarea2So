#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat grayscaleConversion(const Mat& input) {

    Mat output(input.size(), CV_8UC1);

    for(int y = 0; y < input.rows; y++) {
        for(int x = 0; x < input.cols; x++) {

            Vec3b pixel = input.at<Vec3b>(y, x);
            
            uchar gray = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];

            output.at<uchar>(y, x) = gray;
        }
    }

    return output;
}

int main(int argc, char** argv) {

    if(argc != 3) {
        cerr << "Usage: " << argv[0] << " <input> <output>" << endl;
        return -1;
    }

    Mat image = imread(argv[1], IMREAD_COLOR);

    if(image.empty()) {
        cerr << "Could not load image" << endl;
        return -1;
    }

    auto start = chrono::high_resolution_clock::now();

    Mat result = grayscaleConversion(image);

    auto end = chrono::high_resolution_clock::now();

    double elapsed = chrono::duration<double>(end - start).count();

    imwrite(argv[2], result);

    cout << "Elapsed time: " << elapsed << " seconds" << endl;

    return 0;
}
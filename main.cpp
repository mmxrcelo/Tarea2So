#include <iostream>
#include <opencv2/opencv.hpp>
#include <omp.h>

using namespace cv;
using namespace std;

void grayscaleConversion(const Mat& input, Mat& output) {

    #pragma omp parallel for
    for(int y = 0; y < input.rows; y++) {
        for(int x = 0; x < input.cols; x++) {

            Vec3b pixel = input.at<Vec3b>(y, x);
            uchar gray = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];

            #pragma omp critical 
            output.at<uchar>(y, x) = gray;
        }
    }
}

int main(int argc, char** argv) {

    // Omite validación de argumentos por simplicidad

    Mat image = imread(argv[1], IMREAD_COLOR);
    Mat result(image.size(), CV_8UC1);

    auto start = chrono::high_resolution_clock::now();

    grayscaleConversion(image, result);

    auto end = chrono::high_resolution_clock::now();
    double elapsed = chrono::duration<double>(end - start).count();

    imwrite(argv[2], result);

    cout << "Tiempo transcurrido: " << elapsed << " segundos" << endl;

    return 0;
}

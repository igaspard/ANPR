#include <cv.h>
#include <highgui.h>
#include <cvaux.h>

#include "OCR.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

/*const int numFilesChars[] = {
     7,  8, 15, 17,  1,  9, 18, 18, 25, 14,
     3,  4,  0,  5,  4,  1,  3,  1,  0,  2,
     2,  1,  1,  0,  0,  2,  4,  2,  1,  6,
     4,  1,  0,  0,  3,  2
};*/

const int numFilesChars[] = {
    10,  8, 12, 15,  1, 10, 16, 17, 21, 13, 
     4,  4,  0,  5,  4,  0,  3,  0,  0,  1,  
     3,  1,  1,  0,  0,  2,  3,  2,  1,  5,  
     4,  0,  0,  0,  4,  1,  5
};

int main ( int argc, char** argv )
{
    cout << "OpenCV Training OCR Automatic Number Plate Recognition\n";
    cout << "\n";

    char* path;
    
    //Check if user specify image to process
    if(argc >= 1) {
        path = argv[1];
    }
    else {
        cout << "Usage:\n" << argv[0] << " <path to chars folders files> \n";
        return 0;
    }        

    Mat classes;
    Mat trainingDataf5;
    Mat trainingDataf10;
    Mat trainingDataf15;
    Mat trainingDataf20;

    vector<int> trainingLabels;
    OCR ocr;

    for(int i = 0; i< OCR::numCharacters; i++)
    {
        int numFiles = numFilesChars[i];
        if (numFiles > 0) {
            for(int j = 0; j < numFiles; j++) {
                stringstream ss(stringstream::in | stringstream::out);
                ss << path << OCR::strCharacters[i] << "/" << j << ".jpg";
                cout << "Character "<< OCR::strCharacters[i] << " file: " << ss.str() << "\n";
                Mat img = imread(ss.str(), 0);
                Mat f5  = ocr.features(img, 5);
                Mat f10 = ocr.features(img, 10);
                Mat f15 = ocr.features(img, 15);
                Mat f20 = ocr.features(img, 20);

                trainingDataf5.push_back(f5);
                trainingDataf10.push_back(f10);
                trainingDataf15.push_back(f15);
                trainingDataf20.push_back(f20);
                trainingLabels.push_back(i);
            }
        }
    }
    
    trainingDataf5.convertTo(trainingDataf5, CV_32FC1);
    trainingDataf10.convertTo(trainingDataf10, CV_32FC1);
    trainingDataf15.convertTo(trainingDataf15, CV_32FC1);
    trainingDataf20.convertTo(trainingDataf20, CV_32FC1);
    Mat(trainingLabels).copyTo(classes);

    FileStorage fs("OCR_Ratio.xml", FileStorage::WRITE);
    fs << "TrainingDataF5" << trainingDataf5;
    fs << "TrainingDataF10" << trainingDataf10;
    fs << "TrainingDataF15" << trainingDataf15;
    fs << "TrainingDataF20" << trainingDataf20;
    fs << "classes" << classes;
    fs.release();

    return 0;
}

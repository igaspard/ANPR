******************************************************************************
*   Automatic Number Plate Recognition using SVM and Neural Networks
******************************************************************************
*   Author: Gaspard Shen
*   Mail:   syuyang@gmail.com
******************************************************************************
*   Start my version of ANPR.
*   Special for taiwan number plate.
******************************************************************************
----------------------------------------------------------
Building the project using CMake from the command-line:
----------------------------------------------------------
Linux:
    export OpenCV_DIR="~/OpenCV/build"
    mkdir build
    cd build
    cmake -D OpenCV_DIR=$OpenCV_DIR ..
    cmake -D CMAKE_BUILD_TYPE=DEBUG -D OpenCV_DIR=$OpenCV_DIR .. (debug mode)  
    make 

----------------------------------------------------------
Running the project:
----------------------------------------------------------
    ANPR test/2715DTZ.jpg

You can choose other images that are in the test folder or other images that contain a spanish license plate taken from 2 to 3 meters.
There are also some UNIX Bash scripts in the "utils" folder for Linux or Mac, that need Cygwin to run on Windows.

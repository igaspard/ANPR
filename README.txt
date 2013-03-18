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
    ANPR taiwan/6232-UY.jpg

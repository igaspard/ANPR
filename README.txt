******************************************************************************
*   Number Plate Recognition
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

----------------------------------------------------------
Training the SVM:
----------------------------------------------------------
    Prepare the character folder like this: 
    plate/0.jpg, plate/1.jpg, ..., no/0.jpg, no/1.jpg
    
    trainSVM <num Plate Files> <num Non Plate Files> <path to plate folder files> <path to non plate files>
    ex: trainSVM 34 52 Taiwan/plate Taiwan/no

----------------------------------------------------------
Training the OCR:
----------------------------------------------------------
    Prepare the character folder like this: 
    0/0.jpg, 0/1.jpg, 1/0.jpg, ..., 9/0.jpg, A/0.jpg, A/1.jpg, ... Z/0.jpg

    trainOCR TaiwanChars/

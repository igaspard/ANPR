#ifndef DetectRegions_h
#define DetectRegions_h

#include <string.h>
#include <vector>

#include "Plate.h"

#include <cv.h>
#include <highgui.h>
#include <cvaux.h>

using namespace std;
using namespace cv;

//There are 196 countries in the world.
typedef enum {
    Spain   = 0, 
    Taiwan  = 1,
} Country;

#define REGION_WIDTH    160
#define REGION_HEIGHT    75

class DetectRegions{
    public:
        DetectRegions();
        string filename;
        void setFilename(string f);
        bool saveRegions;
        bool showSteps;
        vector<Plate> run(Mat input);
        
        //method
        void setCountry(unsigned char index);
        void setAspectTolerance(float tolerance);

    private:
        vector<Plate> segment(Mat input);
        bool verifySizes(RotatedRect mr);
        Mat histeq(Mat in);
        
        unsigned char   m_country;
        float           m_aspect;
        float           m_aspect_tolerance;
};

#endif

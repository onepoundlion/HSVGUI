#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

Mat src;

void HSVGUI( int event, int x, int y, int f, void *param){
    if (event == EVENT_MOUSEMOVE) {
        cv::VideoCapture cap(0);
        if(!cap.isOpened())
            std::cout<<"check camera";
        namedWindow("HSV GUI", WINDOW_AUTOSIZE);
        // Change exposure accordingly
        int exposure=-7;
        cap.set(CV_CAP_PROP_EXPOSURE, exposure);
        cap>>src;
        Mat image=src.clone();
        Mat HSV;
        Mat RGB=image(Rect(x,y,1,1));
        cvtColor(RGB, HSV,CV_BGR2HSV);

        Vec3b hsv=HSV.at<Vec3b>(0,0);
        int H=hsv.val[0];
        int S=hsv.val[1];
        int V=hsv.val[2];

        char name[30];
        sprintf(name,"H=%d",H);
        putText(image,name, Point(25,40) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,255,0), 2,8,false );

        sprintf(name,"S=%d",S);
        putText(image,name, Point(25,80) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,255,0), 2,8,false );

        sprintf(name,"V=%d",V);
        putText(image,name, Point(25,120) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,255,0), 2,8,false );

        sprintf(name,"X=%d",x);
        putText(image,name, Point(25,300) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,0,255), 2,8,false );

        sprintf(name,"Y=%d",y);
        putText(image,name, Point(25,340) , FONT_HERSHEY_SIMPLEX, .7, Scalar(0,0,255), 2,8,false );

 //imwrite("hsv.jpg",image);
        cv::imshow( "HSV GUI", image );
    }
    else if(event != EVENT_MOUSEMOVE){
        cv::VideoCapture cap(0);
        if(!cap.isOpened())
            std::cout<<"check camera";
        namedWindow("HSV GUI", WINDOW_AUTOSIZE);
        cap>>src;
        cv::imshow( "HSV GUI", src );

    }
}

int main()
{
    /*
    cv::VideoCapture cap(0);
    if(!cap.isOpened())
        std::cout<<"check camera";
    */
    namedWindow("HSV GUI", WINDOW_AUTOSIZE);

    for (;;) {
        // cap>>src;
        setMouseCallback( "HSV GUI", HSVGUI);
        char c = cvWaitKey(50);
        if (c == 27)
            break;
	}
	return 0;
}

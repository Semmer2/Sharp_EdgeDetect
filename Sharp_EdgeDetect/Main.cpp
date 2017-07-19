#include"iostream"
#include<opencv2\opencv.hpp>
#include"EdgeDetect.h"

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("color.jpg",CV_LOAD_IMAGE_GRAYSCALE);

	imshow("Ori", image);
	Mat Result = MyRoberts(image);
	imshow("Roberts", Result);

	Mat SobelImage = MySobel(image);
	imshow("Sobel Image", SobelImage);



	waitKey();
	return 0;
}
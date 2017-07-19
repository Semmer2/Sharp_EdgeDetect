#include"iostream"
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

Mat MyRoberts(Mat image)
{
	Mat OutPut(image.rows - 1, image.cols - 1, image.type());

	for (int row = 0; row < image.rows-1; row++)
	{
		uchar* Result = (uchar*)(OutPut.data + OutPut.step*row);
		uchar* Current = (uchar*)(image.data + image.step*row);
		uchar* Next = (uchar*)(image.data + image.step*(row + 1));
		for (int col = 0; col < image.cols-1; col++)
		{
			Result[col] = abs(Current[col] - Next[col + 1]) + abs(Next[col] - Current[col + 1]);

		}
	}
	return OutPut;
}

Mat MySobel(Mat image)
{//加权平衡/微分/梯度

	int ddepth = CV_16S;

	GaussianBlur(image, image, Size(3, 3), 0, 0, BORDER_DEFAULT);
	Mat gradX, gradY;
	Mat AbsGradX, AbsGradY;
	Mat grad;
	Sobel(image, gradX, ddepth, 1, 0, 3);
	convertScaleAbs(gradX, AbsGradX);
	Sobel(image, gradY, ddepth, 0, 1, 3);
	convertScaleAbs(gradX, AbsGradY);

	addWeighted(AbsGradX, 0.5, AbsGradY, 0.5, 0, grad);

	return grad;


}
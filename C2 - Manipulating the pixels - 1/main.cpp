#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

//Prototypes
void salt(Mat& image, int n);

int main()
{
	//open image
	Mat image = imread("img.jpg");
	namedWindow("Image");
	imshow("Image", image);
	waitKey(5000);
	salt(image, 10000);
	namedWindow("Image2");
	imshow("Image2", image);
	waitKey(0);
	return 0;
}

//A function which adds a salt and pepper effect to an image
void salt(Mat& image, int n)
{
	for (auto k = 0; k < n; ++k)
	{
		int value;
		if (k % 2)
		{
			value = 0;
		}
		else
		{
			value = 255;
		}
		auto i = rand() % image.cols;
		auto j = rand() % image.rows;

		if (image.channels() == 1)
		{
			image.at<uchar>(j, i) = value;
		}
		else if (image.channels() == 3)
		{
			image.at<Vec3b>(j, i)[0] = value;
			image.at<Vec3b>(j, i)[1] = value;
			image.at<Vec3b>(j, i)[2] = value;
		}
	}
}

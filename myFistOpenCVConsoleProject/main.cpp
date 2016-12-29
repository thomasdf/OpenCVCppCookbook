#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	//read an image:
	// An object of class cv::Mat is defined. 
	//This definition creates an image of 0 by 0 pixels.
	// cv::imread reads, decodes and allocates memory based on the image in the path
	cv::Mat image = cv::imread("img.jpg");
	//create image window named "My Image"
	cv::namedWindow("My Image");
	//show the image on the window
	cv::imshow("My Image", image);
	//wait key for 5000 ms
	cv::waitKey(5000);

	//further: the image is flipped. This could be done in place, 
	//but for training purposes it is stored as another image.
	cv::Mat result;
	//flip code (third parameter: 0 = flip around x-axis, 
	//1 = flip around y-axis, -1 = flip around both axis
	cv::flip(image, result, 1);
	cv::namedWindow("Output Image");
	cv::imshow("Output Image", result);
	//wait until keypress
	cv::waitKey(0);
	//save result to file
	cv::imwrite("output.bmp", result);
}

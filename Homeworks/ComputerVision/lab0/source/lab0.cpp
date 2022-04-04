#include <opencv2/imgproc.hpp>
#include <opencv2./highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace cv;
using namespace std;

string source_img = "img.png";

int main(int argc, char** argv)
{
	Mat rot_mat(2, 3, CV_32FC1);
	Mat warp_mat(2, 3, CV_32FC1);
	
	Mat src = imread(source_img); //img 
	Mat warp_dst = Mat::zeros(src.rows, src.cols, src.type()); //img of dastination 
	Mat warp_rot_dst;// = Mat::zeros(warp_dst.rows, warp_dst.cols, warp_dst.type());
	
	Point2f srcTri[3]; //rapprest the an array of 3 point
	Point2f dstTri[3];

	srcTri[0] = Point2f(0.f, 0.f);
	srcTri[1] = Point2f(src.cols - 1.f, 0.f);
	srcTri[2] = Point2f(0.f, src.rows - 1.f);

	dstTri[0] = Point2f(0.f, src.rows*0.33f);
	dstTri[1] = Point2f(src.cols*0.85f, src.rows*0.25f);
	dstTri[2] = Point2f(src.cols*0.15f, src.rows*0.7f);
	
	
	warp_mat = getAffineTransform(srcTri, dstTri);//Get affine transform from point correspondence

	warpAffine(src, warp_dst, warp_mat, warp_dst.size());
    //warpAffine(mat_orgine, mat_destinazione, rotazione, destinazione.size())


	//dati rotazione
	Point center = Point(warp_dst.cols / 2, warp_dst.rows / 2);
	double angle = -45.0;
	double scale = 0.6;


	//rotazione
	rot_mat = getRotationMatrix2D(center, angle, scale);
	warpAffine(warp_dst, warp_rot_dst, rot_mat, warp_rot_dst.size());





	for(int i=0;i<3;i++)
		cout << srcTri[i];
	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << dstTri[i];


	cv::namedWindow("Example 1",WINDOW_AUTOSIZE);
	cv::imshow("Example 1", src);
	cv::namedWindow("Example 2",WINDOW_AUTOSIZE);
	cv::imshow("Example 2", warp_dst);
	cv::namedWindow("Example 3",WINDOW_AUTOSIZE);
	cv::imshow("Example 3", warp_rot_dst);
	cv::waitKey(0);
	return 0;
}
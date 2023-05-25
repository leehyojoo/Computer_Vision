#include <iostream>
#include <opencv2\opencv.hpp>

cv::Mat problem_a_rotate_forward(cv::Mat img, double angle) {
	cv::Mat output;
	//////////////////////////////////////////////////////////////////////////////
	//                         START OF YOUR CODE                               //
	//////////////////////////////////////////////////////////////////////////////
	///// hint : refer annotation /////
	// 
	//Calculate Rotation matrix
	cv::Mat rotation_matrix = cv::getRotationMatrix2D(cv::Point2f((img.cols - 1) / 2, (img.rows - 1 )/ 2), angle, 1);
	//Find (x,y)ranges of output
	cv::Rect2f bounding_box = cv::RotatedRect(cv::Point2f(), img.size(), angle).boundingRect2f();
	//Calculate 'output' size  from range of output
	rotation_matrix.at<double>(0, 2) += bounding_box.width / 2.0 - img.cols / 2.0;
	rotation_matrix.at<double>(1, 2) += bounding_box.height / 2.0 - img.rows / 2.0;
	//Calculate destination coordinates from origin
	cv::warpAffine(img, output, rotation_matrix, bounding_box.size());
	//////////////////////////////////////////////////////////////////////////////
	//                          END OF YOUR CODE                                //
	//////////////////////////////////////////////////////////////////////////////
	cv::imshow("a_output", output); cv::waitKey(0);
	return output;
}

cv::Mat problem_b_rotate_backward(cv::Mat img, double angle) {
	cv::Mat output;
	//////////////////////////////////////////////////////////////////////////////
	//                         START OF YOUR CODE                               //
	//////////////////////////////////////////////////////////////////////////////
	///// hint : refer annotation /////
	// 
	//Calculate Rotation matrix
	cv::Mat rotation_matrix = cv::getRotationMatrix2D(cv::Point2f((img.cols - 1) / 2, (img.rows - 1) / 2), -angle, 1);
	//Find (x,y)ranges of output
	cv::Rect2f bounding_box = cv::RotatedRect(cv::Point2f(), img.size(), angle).boundingRect2f();
	//Calculate 'output' size  from range of output
	rotation_matrix.at<double>(0, 2) += bounding_box.width / 2.0 - img.cols / 2.0;
	rotation_matrix.at<double>(1, 2) += bounding_box.height / 2.0 - img.rows / 2.0;
	//Calculate destination coordinates from origin
	cv::warpAffine(img, output, rotation_matrix, bounding_box.size());
	//////////////////////////////////////////////////////////////////////////////
	//                          END OF YOUR CODE                                //
	//////////////////////////////////////////////////////////////////////////////
	cv::imshow("b_output", output); cv::waitKey(0);
	return output;

	return output;
}

cv::Mat problem_c_rotate_backward_interarea(cv::Mat img, double angle) {
	cv::Mat output;

	//////////////////////////////////////////////////////////////////////////////
	//                         START OF YOUR CODE                               //
	//////////////////////////////////////////////////////////////////////////////
	///// hint : refer annotation /////
	// 
	//Calculate Rotation matrix
	cv::Mat rotation_matrix = cv::getRotationMatrix2D(cv::Point2f((img.cols - 1) / 2, (img.rows - 1) / 2), -angle, 1);
	//Calculate Inverse Rotation matrix
	cv::Mat inv_roation_matrix = cv::getRotationMatrix2D(cv::Point2f((img.cols - 1) / 2, (img.rows - 1) / 2), angle, 1);
	//Find (x,y)ranges of output
	cv::Rect2f bounding_box = cv::RotatedRect(cv::Point2f(), img.size(), angle).boundingRect2f();
	//Calculate 'output' size  from range of output
	rotation_matrix.at<double>(0, 2) += bounding_box.width / 2.0 - img.cols / 2.0;
	rotation_matrix.at<double>(1, 2) += bounding_box.height / 2.0 - img.rows / 2.0;
	//Calculate origin coordinates from destination coordinates
	cv::warpAffine(img, output, rotation_matrix, bounding_box.size());
	////////INTER_AREA
	cv::resize(output, output, bounding_box.size(), 0, 0, cv::INTER_LINEAR);
	//////////////////////////////////////////////////////////////////////////////
	//                          END OF YOUR CODE                                //
	//////////////////////////////////////////////////////////////////////////////

	cv::imshow("c_output", output); cv::waitKey(0);

	return output;
}

int main(void) {

	double angle = -15.0f;

	cv::Mat input = cv::imread("lena.jpg");
	//Fill problem_a_rotate_forward and show output
	problem_a_rotate_forward(input, angle);
	//Fill problem_b_rotate_backward and show output
	problem_b_rotate_backward(input, angle);
	//Fill problem_c_rotate_backward_interarea and show output
	problem_c_rotate_backward_interarea(input, angle);
}
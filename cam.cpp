#include <opencv2/opencv.hpp>
#include <iostream>

int main() {

	    cv::VideoCapture cap(0);
	        if (!cap.isOpened()) {
			        std::cerr << "Error: Could not open camera." << std::endl;
				        return -1;
					    }

		 
		    cv::namedWindow("Camera", cv::WINDOW_AUTOSIZE);

		        cv::Mat frame;
			    std::cout << "Press 'c' to capture an image or 'q' to quit." << std::endl;

			        while (true) {
					       
					        cap >> frame;

						  
						        if (frame.empty()) {
								            std::cerr << "Error: No captured frame." << std::endl;
									                break;
											        }

							      
							        cv::imshow("Camera", frame);

								       
								        char key = cv::waitKey(1);
									        if (key == 'c') {
											           
											            cv::imwrite("captured_image.jpg", frame);
									std::cout << "Image captured and saved as 'captured_image.jpg'." << std::endl;														        } else if (key == 'q') {
																  
																            break;
																	            }
										    }

				    cap.release();
				        cv::destroyAllWindows();
					    return 0;
}


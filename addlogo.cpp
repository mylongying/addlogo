// CMakeopencv.cpp: 定义应用程序的入口点。
//

#include "addlogo.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void alogo(Mat &frame, Mat logo) {
   
    
    Mat roi = frame(Rect(0, 0, logo.cols, logo.rows));
    float alph = 0, bta = 1;
    int rownumber = roi.rows;
    int colnumber = roi.cols;
    for (int i = 0; i < rownumber; i++)
    {
        for (int j = 0; j < colnumber; j++)
        {

            if (!(logo.at<Vec3b>(i, j)[0] >= 250 &&
                logo.at<Vec3b>(i, j)[1] >= 250 &&
                logo.at<Vec3b>(i, j)[2] >= 250))
            {
                roi.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(roi.at<Vec3b>(i, j)[0] * alph + logo.at<Vec3b>(i, j)[0] * bta);
                roi.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(roi.at<Vec3b>(i, j)[1] * alph + logo.at<Vec3b>(i, j)[1] * bta);
                roi.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(roi.at<Vec3b>(i, j)[2] * alph + logo.at<Vec3b>(i, j)[2] * bta);
            }

        }

    }
}

int main(int argc, const char** argv)
{
	cv::CommandLineParser cmd(argc, argv,
		"{ c camera |                    | use camera }"
		"{ f file   | ../data/vtest.avi  | input video file }"
		"{ m method | mog                | method (mog, mog2) }"
		"{ h help   |                    | print help message }");
	char* ptrpic = "C:\\03study\\vs\\imgdata\\1280.jpg";
	char* ptrlogo = "C:\\03study\\vs\\imgdata\\wlmy_150.png";
	char* vfile = "C:\\03study\\vs\\imgdata\\xlgc.mp4";
	char* winname = "show";

	VideoCapture cap;
	cap.open(vfile);
	long totalFrameNumber = cap.get(CAP_PROP_FRAME_COUNT);
	int fps = cap.get(CAP_PROP_FPS);
	int waitfor = (int)(1000 / fps);
	int wait;
	int64 start, end;
	Mat frame;
	Mat logo = imread(ptrlogo);
	namedWindow(winname);

	for (;;)
	{
		//cap >> frame;
		//if (frame.empty())
		//break;
		start = cv::getTickCount();
		if (!cap.read(frame)) break;
		alogo(frame, logo);
		imshow(winname, frame);
		end = cv::getTickCount();
		wait = waitfor - (end - start);
		if (wait < 1) wait = 1;

		char c = waitKey(wait);
		if (c == 27) break;

	}
	cap.release();
	return 1;
}

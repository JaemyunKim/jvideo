#ifndef VIDEO_CAPTURE_TYPE_H_
#define VIDEO_CAPTURE_TYPE_H_


#ifndef __cplusplus
#  error MultiVideoCapture.hpp header must be compiled as C++
#endif


#include "opencv2/opencv.hpp"
#include "FrameType.hpp"


enum CamStatus {
	CAM_STATUS_CLOSED,
	CAM_STATUS_OPENED,
	CAM_STATUS_OPENING,
};


class VideoCaptureType : protected cv::VideoCapture {
public:
	VideoCaptureType();
	virtual ~VideoCaptureType();

	virtual bool open(int index);
	virtual bool open(int index, int apiPreference);
	virtual bool isOpened() const;
	virtual CamStatus status() const;

	virtual void release();

	virtual bool retrieve(FrameType& frame, int flag = 0);
	virtual bool read(FrameType& frame);
	virtual VideoCaptureType& operator >> (FrameType& frame);

	virtual bool set(cv::Size resolution = { 640, 480 }, float fps = 30.f);

protected:
	int mCamId;
	CamStatus mStatus;

	cv::Size mResolution;
	float mFps;
};


#endif // !VIDEO_CAPTURE_TYPE_H_

#ifndef CALIBRATION_OBJECT_H
#define CALIBRATION_OBJECT_H

#include <cv.h>

using namespace cv;

// Class storing a representation of the calibration object, with 35 Left face points and 28 Right face points
class CalibrationObject
{

public:
	CalibrationObject();
	~CalibrationObject();
	Point3d getLeftPt(int row, int column);
	Point3d getRightPt(int row, int column);

	// RAW uses x,y values for the actual pixel in the image.
	Point2d getLeftAssocImagePt_RAW(int row, int column);
	Point2d getRightAssocImagePt_RAW(int row, int column);
	void setLeftAssocImagePt_RAW(int row, int column, Point2d pt);
	void setRightAssocImagePt_RAW(int row, int column, Point2d pt);

	// ADJ uses x,y values for the pixel in the image, RELATIVE TO THE IMAGE CENTRE.
	Point2d getLeftAssocImagePt_ADJ(int row, int column);
	Point2d getRightAssocImagePt_ADJ(int row, int column);
	void setLeftAssocImagePt_ADJ(int row, int column, Point2d pt);
	void setRightAssocImagePt_ADJ(int row, int column, Point2d pt);

	// X/Y/Z values of actual calibration points in world coordinate system
	// It wasn't actually very useful storing these separately; change if I have time
	Point3d *lMeasurements;
	Point3d *rMeasurements;

	// x/y values of calibration points in image
	// It wasn't actually very useful storing these separately; change if I have time
	Point2d *lAssocImagePts_RAW;
	Point2d *rAssocImagePts_RAW;
	Point2d *lAssocImagePts_ADJ;
	Point2d *rAssocImagePts_ADJ;

};

#endif // CALIBRATION_OBJECT_H

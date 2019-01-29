#include <math.h>
#include <stdio.h>

class Point2 {
	public:
		float DistanceBetween(Point2 other);
		void Print();
		int Quadrant();
		Point2();
		Point2(float x_in, float y_in);
	private:
		float x;
		float y;
};

#ifndef LINEAR_PRIMITIVE_CLASS
#define LINEAR_PRIMITIVE_CLASS

#include"Vector3.h"
#include<iostream>

class LinearPrimitive {
	public:
		Vector3 position;
		Vector3 vec1;
		Vector3 vec2;
		LinearPrimitive(float point1X, float point1Y, float point1Z, float point2X, float point2Y, float point2Z, float point3X, float point3Y, float point3Z);
		void ComputeNodalPoints(Vector3* pointOfView, Vector3* vecOfView, bool* isOnObject, float* distance);

};

#endif

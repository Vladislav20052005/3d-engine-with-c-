#ifndef MATRIX3_CLASS
#define MATRIX3_CLASS

#include "Vector3.h"

class Matrix3 {
	private:
		float matrix[3][3]{};
	public:
		Matrix3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33);
		Matrix3(Vector3& first, Vector3& second, Vector3& third);
		Matrix3();


		float get(unsigned int i, unsigned int j);
		void set(float k, unsigned int i, unsigned int j);


		float det();

		Vector3 solve(Vector3& b);


		Matrix3 operator+(Matrix3& right);
		Matrix3 operator-(Matrix3& right);
		Matrix3 operator*(Matrix3& right);
		Matrix3 operator*(float k);


		Matrix3& operator+=(Matrix3& right);
		Matrix3& operator-=(Matrix3& right);
		Matrix3& operator*=(float k);
		Matrix3& operator/=(float k);
};

#endif

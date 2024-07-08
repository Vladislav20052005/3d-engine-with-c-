#include"Matrix3.h"


Matrix3::Matrix3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33) {
	
}

Matrix3::Matrix3() {
	for (unsigned int i = 0; i < 3; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			matrix[i][j] = 0.f;
		}
	}
}


float Matrix3::get(unsigned int i, unsigned int j) {
	return matrix[i][j];
}


void Matrix3::set(float k, unsigned int i, unsigned int j) {
	matrix[i][j] = k;
}



float Matrix3::det() {
	return matrix[0][0] * matrix[1][1] * matrix[2][2] +
		matrix[0][1] * matrix[1][2] * matrix[2][0] +
		matrix[0][2] * matrix[1][0] * matrix[2][1] -

		matrix[0][2] * matrix[1][1] * matrix[2][0] -
		matrix[0][0] * matrix[1][2] * matrix[2][1] -
		matrix[0][1] * matrix[1][0] * matrix[2][2];
}




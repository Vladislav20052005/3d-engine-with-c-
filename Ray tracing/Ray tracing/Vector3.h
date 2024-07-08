#ifndef VECTOR3_CLASS
#define VECTOR3_CLASS

#include<iostream>
#include<cmath>


class Vector3 {
	private:
		float x, y, z;
	public:
		Vector3(float x, float y, float z);
		Vector3();

		float getX();
		float getY();
		float getZ();

		void setX(float k);
		void setY(float k);
		void setZ(float k);


		float length();
		void normalize();


		Vector3 operator+(Vector3& right);
		Vector3 operator-(Vector3& right);
		float operator*(Vector3& right);
		Vector3 operator*(float k);



		Vector3& operator+=(Vector3 right);
		Vector3& operator-=(Vector3 right);
		Vector3& operator*=(float k);
		Vector3& operator/=(float k);


};

std::ostream& operator<<(std::ostream& os, Vector3 vec);

Vector3 operator*(float k, Vector3& vec);

float det(Vector3* vec1, Vector3* vec2, Vector3* vec3);
Vector3 solve(Vector3* vec1, Vector3* vec2, Vector3* vec3, Vector3* result);

#endif
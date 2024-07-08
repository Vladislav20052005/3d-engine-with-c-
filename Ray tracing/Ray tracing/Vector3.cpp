#include "Vector3.h"


Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3() {
	this->x = 0.f;
	this->y = 0.f;
	this->z = 0.f;
}



float Vector3::getX() {
	return this->x;
}

float Vector3::getY() {
	return this->y;
}

float Vector3::getZ() {
	return this->z;
}

void Vector3::setX(float k) {
	this->x = k;
}

void Vector3::setY(float k) {
	this->y = k;
}

void Vector3::setZ(float k) {
	this->z = k;
}

float Vector3::length() {
	return pow(x * x + y * y + z * z, 0.5);
}



void Vector3::normalize() {
	*this /= this->length();
}


Vector3 Vector3::operator+(Vector3& right) {
	return Vector3(this->x + right.x, this->y + right.y, this->z + right.z);
}


Vector3 Vector3::operator-(Vector3& right) {
	return Vector3(this->x - right.x, this->y - right.y, this->z - right.z);
}

float Vector3::operator*(Vector3& right) {
	return this->x * right.x + this->y * right.y + this->z * right.z;
}

Vector3 Vector3::operator*(float k) {
	return Vector3(this->x * k, this->y * k, this->z * k);
}


Vector3 operator*(float k, Vector3& vec) {
	return Vector3(vec.getX() * k, vec.getY() * k, vec.getZ() * k);
}


Vector3& Vector3::operator+=(Vector3 right) {
	this->x += right.x;
	this->y += right.y;
	this->z += right.z;
	return *this;
}

Vector3& Vector3::operator-=(Vector3 right) {
	this->x -= right.x;
	this->y -= right.y;
	this->z -= right.z;
	return *this;
}

Vector3& Vector3::operator*=(float k) {
	this->x *= k;
	this->y *= k;
	this->z *= k;
	return *this;
}

Vector3& Vector3::operator/=(float k) {
	this->x /= k;
	this->y /= k;
	this->z /= k;
	return *this;
}

std::ostream& operator<<(std::ostream& os, Vector3 vec) {
	return os << '(' << vec.getX() << ", " << vec.getY() << ", " << vec.getZ() << ')';
}



float det(Vector3* vec1, Vector3* vec2, Vector3* vec3) {
	return vec1->getX() * vec2->getY() * vec3->getZ() +
		vec1->getY() * vec2->getZ() * vec3->getX() +
		vec1->getZ() * vec2->getX() * vec3->getY() -

		vec1->getZ()* vec2->getY()* vec3->getX() -
		vec1->getX() * vec2->getZ() * vec3->getY() -
		vec1->getY() * vec2->getX() * vec3->getZ();
}


Vector3 solve(Vector3* vec1, Vector3* vec2, Vector3* vec3, Vector3* result) {
	float determinant = det(vec1, vec2, vec3);
	return Vector3(det(result, vec2, vec3) / determinant, det(vec1, result, vec3) / determinant, det(vec1, vec2, result) / determinant);
}
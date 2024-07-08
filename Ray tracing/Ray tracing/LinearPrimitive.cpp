#include"LinearPrimitive.h"

LinearPrimitive::LinearPrimitive(float point1X, float point1Y, float point1Z, float point2X, float point2Y, float point2Z, float point3X, float point3Y, float point3Z) {
	this->position.setX(point1X);
	this->position.setY(point1Y);
	this->position.setZ(point1Z);

	this->vec1.setX(point2X - point1X);
	this->vec1.setY(point2Y - point1Y);
	this->vec1.setZ(point2Z - point1Z);

	this->vec2.setX(point3X - point1X);
	this->vec2.setY(point3Y - point1Y);
	this->vec2.setZ(point3Z - point1Z);

	vec1 *= -1.f;
	vec2 *= -1.f;

}

void LinearPrimitive::ComputeNodalPoints(Vector3* pointOfView, Vector3* vecOfView, bool* isOnObject, float* distance) {
	Vector3 relativePosition = position - *pointOfView;
	Vector3 result = solve(&vec1, &vec2, vecOfView, &relativePosition);
	if (result.getX() >= 0 && result.getY() >= 0 && result.getX() + result.getY() <= 1 && result.getZ() >= 0) {// && result.getX() <= 1 && result.getY() <= 1) {
		*isOnObject = true;
		*distance = result.getZ();
	}
}
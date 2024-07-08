#include"LinearObject.h"

LinearObject::LinearObject(LinearPrimitive** primitives, unsigned int primitiveCnt, Material* material) {
	this->primitives = primitives;
	this->primitiveCnt = primitiveCnt;
	this->material = material;
}

void LinearObject::ComputeNodalPoints(Vector3* pointOfView, Vector3* vecOfView, std::vector<std::pair<Material*, float>>* materials) {
	bool isOnObject = false;
	float distance = NULL;
	for (unsigned int i = 0; i < primitiveCnt; i++) {
		primitives[i]->ComputeNodalPoints(pointOfView, vecOfView, &isOnObject, &distance);
	}
	if (isOnObject) {
		materials->push_back(std::make_pair(this->material, distance));
	}
}
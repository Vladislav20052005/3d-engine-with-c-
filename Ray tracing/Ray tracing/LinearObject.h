#ifndef LINEAR_OBJECT_CLASS
#define LINEAR_OBJECT_CLASS

#include"LinearPrimitive.h"
#include"Material.h"
#include<vector>

class LinearObject {
	private:
		LinearPrimitive** primitives;
		unsigned int primitiveCnt;
		Material* material;
	public:
		LinearObject(LinearPrimitive** primitives, unsigned int primitiveCnt, Material* material);
		void ComputeNodalPoints(Vector3* pointOfView, Vector3* vecOfView, std::vector<std::pair<Material*, float>>* materials);

};

#endif

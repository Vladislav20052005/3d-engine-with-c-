#ifndef MATERIAL_CLASS
#define MATERIAL_CLASS


class Material {
	public:
		unsigned __int8 R;
		unsigned __int8 G;
		unsigned __int8 B;
		unsigned __int8 A;
		Material(unsigned __int8 red, unsigned __int8 green, unsigned __int8 blue, unsigned __int8 alpha);
};

#endif
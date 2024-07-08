#ifndef CAMERA_CLASS
#define CAMERA_CLASS

#include"Vector3.h"
#include"Matrix3.h"
#include"LinearObject.h"
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<thread>
#include<GLFW/glfw3.h>

class Camera {
	private:
		GLFWwindow* window;
		Vector3 position;
		Vector3 direction;
		Vector3 scanner;
		Vector3 front;
		Vector3 up;
		Vector3 right;
		float step = 0.0025f;
		const float moveSpeed = 1.f;
		const float rotationSpeed = 0.1f;

	public:
		unsigned __int8* data;
		unsigned int width, height, pixelSize;
		float fov;

		LinearObject** scene;
		unsigned int sceneCnt;

		Camera(float positionX, float positionY, float positionZ, 
			unsigned int pixelSize, unsigned int width, unsigned int height, float fov, 
			LinearObject** scene, unsigned int sceneCnt, GLFWwindow* window);
		~Camera();
		void update();
		void scan();
		void updateViewVectors();
		void updateControls();

		
};

#endif

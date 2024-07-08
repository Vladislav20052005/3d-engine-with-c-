#include"Camera.h"


Camera::Camera(float positionX, float positionY, float positionZ, 
	unsigned int pixelSize, unsigned int width, unsigned int height, float fov, 
	LinearObject** scene, unsigned int sceneCnt, GLFWwindow* window) {
	this->window = window;
	this->position = Vector3(positionX, positionY, positionZ);
	this->direction = Vector3(0.f, 0.f, 0.f);
	this->pixelSize = pixelSize;
	this->width = width;
	this->height = height;
	this->fov = fov;
	this->scene = scene;
	this->sceneCnt = sceneCnt;
	this->data = new unsigned __int8[3 * width * height * pixelSize];
}

Camera::~Camera() {
	delete[] this->data;
}


void Camera::update() {

	updateViewVectors();
	updateControls();


	scanner = front;
	scanner -= up * (height / 2);
	scanner -= right * (width / 2);

	std::vector<std::pair<Material*, float>> materials;

	for (unsigned int i = 0; i < height; i++) {
		for (unsigned int j = 0; j < width; j++) {
			for (unsigned int k = 0; k < sceneCnt; k++) {
				scene[k]->ComputeNodalPoints(&position, &scanner, &materials);
			}

			data[3 * (width * i + j)] = 0;
			data[3 * (width * i + j) + 1] = 0;
			data[3 * (width * i + j) + 2] = 0;
			if(materials.size() != 0) {
				std::sort(begin(materials), end(materials), [](std::pair<Material*, float> a, std::pair<Material*, float> b) {return a.second < b.second;});
				data[3 * (width * i + j)] = materials[0].first->R;
				data[3 * (width * i + j) + 1] = materials[0].first->G;
				data[3 * (width * i + j) + 2] = materials[0].first->B;
				for (int ii = 1; ii < materials.size(); ii++) {

					data[3 * (width * i + j)] += (materials[ii].first->R * materials[ii - 1].first->A);
					data[3 * (width * i + j) + 1] += (materials[ii].first->G * materials[ii - 1].first->A);
					data[3 * (width * i + j) + 2] += (materials[ii].first->B * materials[ii - 1].first->A);
				}
			}
			materials.clear();
			
			scanner += right;
		}
		scanner -= right * (width);
		scanner += up;
	}


}

void Camera::scan() {

}


void Camera::updateViewVectors() {


	
	front.setX(cos(direction.getY()) * cos(direction.getZ()));
	up.setX(-sin(direction.getZ()) * cos(direction.getY()));
	right.setX(sin(direction.getY()));

	front.setY(sin(direction.getX()) * sin(direction.getY()) * cos(direction.getZ()) + sin(direction.getZ()) * cos(direction.getX()));
	up.setY(-sin(direction.getX()) * sin(direction.getY()) * sin(direction.getZ()) + cos(direction.getX()) * cos(direction.getZ()));
	right.setY(-sin(direction.getX()) * cos(direction.getY()));

	front.setZ(sin(direction.getX()) * sin(direction.getZ()) - sin(direction.getY()) * cos(direction.getX()) * cos(direction.getZ()));
	up.setZ(sin(direction.getX()) * cos(direction.getZ()) + sin(direction.getY()) * sin(direction.getZ()) * cos(direction.getX()));
	right.setZ(cos(direction.getX()) * cos(direction.getY()));

	up *= step;
	right *= step;

}


void Camera::updateControls() {
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		this->position += front * moveSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		this->position -= right * (moveSpeed / step);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		this->position -= front * moveSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		this->position += right * (moveSpeed / step);
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		this->position += Vector3(0.f, moveSpeed, 0.f);
	}
	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
	{
		this->position -= Vector3(0.f, moveSpeed, 0.f);
	}
	if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
	{
		this->direction.setZ(this->direction.getZ() + rotationSpeed);
	}
	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
	{
		this->direction.setZ(this->direction.getZ() - rotationSpeed);
	}
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
	{
		this->direction.setY(this->direction.getY() + rotationSpeed);
	}
	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
	{
		this->direction.setY(this->direction.getY() - rotationSpeed);
	}
	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
	{
		this->direction.setX(this->direction.getX() - rotationSpeed);
	}
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
	{
		this->direction.setX(this->direction.getX() + rotationSpeed);
	}
}
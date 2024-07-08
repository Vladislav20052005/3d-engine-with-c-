#include<iostream>
#include"Vector3.h"
#include"Camera.h"
#include"LinearObject.h"
#include <GLFW/glfw3.h>
#include<ctime>

#define WIDTH 300
#define HEIGHT 300






int main(void)
{
    LinearPrimitive face1(-1.f, 0.f, -1.f, -1.f, 0.f, 1.f, -1.f, 1.f, 0.f);
    LinearPrimitive face2(1.f, 0.f, -1.f, 1.f, 0.f, 1.f, 1.f, 1.f, 0.f);

    Material material1(255, 0, 0, 10);
    Material material2(0, 255, 0, 0);


    LinearPrimitive* primitives1[1];
    primitives1[0] = &face1;

    LinearPrimitive* primitives2[1];
    primitives2[0] = &face2;

    LinearObject pyramid1(primitives1, 1, &material1);
    LinearObject pyramid2(primitives2, 1, &material2);


    LinearObject* scene[2];
    scene[0] = &pyramid1;
    scene[1] = &pyramid2;



    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(HEIGHT, WIDTH, "RayTracing", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    Camera camera(-2.f, 0.f, 0.f, 1, WIDTH, HEIGHT, 45.f, scene, 2, window);


    //Controls controls(window, &camera);
    int start;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        start = clock();
        camera.update();
        /* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);
        glDrawPixels(HEIGHT, WIDTH, GL_RGB, GL_UNSIGNED_BYTE, camera.data);

        //controls.updateControls();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        std::cout << clock() - start << '\n';
    }

    glfwTerminate();
    //delete[] data;
    return 0;
}
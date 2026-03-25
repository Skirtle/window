#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

struct Engine {
    GLFWwindow* window;
    int WIDTH = 800, HEIGHT = 600;

    Engine() {
        // Init GLFW
        if (!glfwInit()) {
            std::cerr << "Failed to init GLFW\n";
            exit(EXIT_FAILURE);
        }

        // Tell GLFW what OpenGL version we want
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Create window
        window = glfwCreateWindow(WIDTH, HEIGHT, "Window title", nullptr, nullptr);

        if (!window) {
            std::cerr << "Failed to create window\n";
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD\n";
            exit(EXIT_FAILURE);
        }

        glViewport(0, 0, WIDTH, HEIGHT);

        // Set resize callback
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    }

    ~Engine() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
};

struct Particle {
    int x, y;
    int charge;
    Particle(int tx, int ty, int c) {
        x = tx;
        y = ty;
        charge = c;
    }

    void draw() {
        glBegin(GL_TRIANGLE_FAN);
        for ()
    }
};

Engine engine;

int main() {
    while (!glfwWindowShouldClose(engine.window)) {
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(engine.window);
        glfwPollEvents();
    }

    return 0;
}

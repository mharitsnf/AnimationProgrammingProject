#include "external/glad/include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include "src/opengl/Shader.h"
#include "src/opengl/Attribute.h"
#include "src/opengl/Uniform.h"
#include "src/opengl/IndexBuffer.h"
#include "src/opengl/Draw.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // initialize shader program
    Shader shader(
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "out vec4 vertexColor;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos, 1.0);\n"
        "   vertexColor = vec4(0.5, 0.0, 0.0, 1.0);\n"
        "}\0",
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "uniform vec4 ourColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = ourColor;\n"
        "}\n\0"
    );

    // setup object vertices
    float vertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };

    std::vector<vec3> verticesVec3 = {
        vec3(0.5f,  0.5f, 0.0f),
        vec3(0.5f, -0.5f, 0.0f),
        vec3(-0.5f, -0.5f, 0.0f),
        vec3(-0.5f,  0.5f, 0.0f)
    };

    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

     std::vector<unsigned int> indicesUint = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    // setup VBO and VAO
    // VBO is vertex buffer object, for filling a buffer with vert positions, normals, uvs, etc.
    // EBO is element buffer object, so we can just store unique vertices, and reuse it through specified indices.
    // VAO is vertex array object, for "saving" VBO and EBO configurations so you don't have to specify it over and over again.
    
    // Create and bind VAO
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // create and bind VBO, populate data, and then set it to shader
    // automatically unbind when it's done
    Attribute<vec3> aPos;  
    aPos.Set(verticesVec3);
    aPos.BindTo(0);

    // create and bind EBO, populate data, and then set it to shader
    IndexBuffer indexBuffer;
    indexBuffer.Set(indicesUint);

    // unbind VAO
    glBindVertexArray(0);
    
    // render loop
    while (!glfwWindowShouldClose(window)) {
        // input
        processInput(window);

        // rendering background
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // set uniform
        glUseProgram(shader.GetHandle());
        double timeValue = glfwGetTime();
        float greenValue = static_cast<float>(sin(timeValue) / 2.0 + 0.5);
        int vertexColorLocation =  Uniform<vec4>::GetLocation(shader.GetHandle(), "ourColor");
        Uniform<vec4>::Set(vertexColorLocation, vec4(0.0f, greenValue, 0.0f, 1.0f));

        glBindVertexArray(VAO);
        Draw(indexBuffer, DrawMode::Triangles);

        glUseProgram(0);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
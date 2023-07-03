#include "LearnOpenGLApp.h"

#include "../math/mat4.h"
#include "../math/quat.h"
#include "../opengl/Uniform.h"
#include "../opengl/Draw.h"

void LearnOpenGLApp::Initialize() {
    mRotation = 0.0f;
	mShader = new Shader("shaders/learnopengl.vert", "shaders/learnopengl.frag");
	mDisplayTexture = new Texture;

    mVertexArray = new VertexArray();
    mVertexPositions = new Attribute<vec3>();
	mVertexTexCoords = new Attribute<vec2>();
	mIndexBuffer = new IndexBuffer();

    mVertexArray->Bind();

    // setup object vertices
    std::vector<vec3> verts = {
        vec3(0.5f,  0.5f, 0.0f),    // top right
        vec3(0.5f, -0.5f, 0.0f),    // bottom right
        vec3(-0.5f, -0.5f, 0.0f),   // bottom left
        vec3(-0.5f,  0.5f, 0.0f)    // top left 
    };
    mVertexPositions->Set(verts);
    mVertexPositions->BindTo(0);

    std::vector<vec2> uvs = {
        vec2(1.0f, 1.0f),           // top right
        vec2(1.0f, 0.0f),           // bottom right
        vec2(0.0f, 0.0f),           // bottom left
        vec2(0.0f, 1.0f)            // top left 
    };
    mVertexTexCoords->Set(uvs);
    mVertexTexCoords->BindTo(1);

    std::vector<unsigned int> indices = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };
    mIndexBuffer->Set(indices);

    mDisplayTexture->Load("textures/wall.jpg");
}

// inside the loop loop
void LearnOpenGLApp::Render(float inAspectRatio) {

    mShader->Bind();

    mDisplayTexture->Set(mShader->GetUniform("texture0"), 0);

    Draw(*mIndexBuffer, *mVertexArray, DrawMode::Triangles);

    mDisplayTexture->UnSet(0);

    mVertexPositions->UnBindFrom(0);
    mVertexTexCoords->UnBindFrom(1);

    mShader->UnBind();
}

void LearnOpenGLApp::Shutdown() {
	delete mShader;
	delete mDisplayTexture;
	delete mVertexPositions;
	delete mVertexTexCoords;
	delete mIndexBuffer;
}
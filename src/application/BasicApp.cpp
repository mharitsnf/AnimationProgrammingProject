#include "BasicApp.h"

#include "../math/mat4.h"
#include "../math/quat.h"
#include "../opengl/Uniform.h"
#include "../opengl/Draw.h"

void BasicApp::Initialize() {
    mRotation = 0.0f;
	mShader = new Shader("shaders/static.vert", "shaders/lit.frag");
	mDisplayTexture = new Texture;
    mDisplayTexture->Load("assets/textures/wall.jpg");

    mVertexArray = new VertexArray();
	mVertexPositions = new Attribute<vec3>();
	mVertexNormals = new Attribute<vec3>();
	mVertexTexCoords = new Attribute<vec2>();
	mIndexBuffer = new IndexBuffer();


	std::vector<vec3> positions;
	positions.push_back(vec3(-1, -1, 0));
	positions.push_back(vec3(-1, 1, 0));
	positions.push_back(vec3(1, -1, 0));
	positions.push_back(vec3(1, 1, 0));
    
	mVertexArray->Bind();
	mVertexPositions->Set(positions);
    mVertexPositions->BindTo(mShader->GetAttribute("position"));
	mVertexArray->Unbind();

	std::vector<vec3> normals;
	normals.resize(4, vec3(0, 0, 1));

	mVertexArray->Bind();
	mVertexNormals->Set(normals);
	mVertexNormals->BindTo(mShader->GetAttribute("normal"));
	mVertexArray->Unbind();

	std::vector<vec2> uvs;
	uvs.push_back(vec2(0, 0));
	uvs.push_back(vec2(0, 1));
	uvs.push_back(vec2(1, 0));
	uvs.push_back(vec2(1, 1));

	mVertexArray->Bind();
	mVertexTexCoords->Set(uvs);
	mVertexTexCoords->BindTo(mShader->GetAttribute("texCoord"));
	mVertexArray->Unbind();

	std::vector<unsigned int> indices;
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(2);
	indices.push_back(1);
	indices.push_back(3);

	mVertexArray->Bind();
	mIndexBuffer->Set(indices);
	mVertexArray->Unbind();

}

void BasicApp::Update(float inDeltaTime) {
    mRotation += inDeltaTime * 45.0f;
	while (mRotation > 360.0f) {
		mRotation -= 360.0f;
	}
}

void BasicApp::Render(float inAspectRatio) {
    // calculating uniform
    mat4 projection = perspective(60.0f, inAspectRatio, 0.01f, 1000.0f);
	mat4 view = lookAt(vec3(0, 0, -5), vec3(0, 0, 0), vec3(0, 1, 0));
	mat4 model = quatToMat4(angleAxis(mRotation * DEG2RAD, vec3(0, 0, 1)));

	mShader->Bind();

    mDisplayTexture->Set(mShader->GetUniform("tex0"), 0);

    // setting uniform
	Uniform<mat4>::Set(mShader->GetUniform("model"), model);
	Uniform<mat4>::Set(mShader->GetUniform("view"), view);
	Uniform<mat4>::Set(mShader->GetUniform("projection"), projection);
	Uniform<vec3>::Set(mShader->GetUniform("light"), vec3(0, 0, 1));

	Draw(*mIndexBuffer, *mVertexArray, DrawMode::Triangles);

    mDisplayTexture->UnSet(0);

	mShader->UnBind();
}

void BasicApp::Shutdown() {
    delete mShader;
	delete mDisplayTexture;
	delete mVertexPositions;
	delete mVertexNormals;
	delete mVertexTexCoords;
	delete mIndexBuffer;
    delete mVertexArray;
}
#include "pch.h"
#include "Game.h"
#include "Engine.h"
#include "Material.h"
#include "MeshRenderer.h"
#include "GameObject.h"



shared_ptr<GameObject>gameobject = make_shared<GameObject>();

void Game::Init(const WindowInfo& windowinfo)
{
	GEngine->Init(windowinfo);
	/*vector<Vertex> vec(3);
	vec[0].pos = Vec3(0.f, 0.5f, 0.5f);
	vec[0].color = Vec4(1.f, 0.f, 0.f, 1.f);
	vec[1].pos = Vec3(0.5f, -0.5f, 0.5f);
	vec[1].color = Vec4(0.f, 1.0f, 0.f, 1.f);
	vec[2].pos = Vec3(-0.5f, -0.5f, 0.5f);
	vec[2].color = Vec4(0.f, 0.f, 1.f, 1.f);
	*/
	/*vector<Vertex> vec(6);
vec[0].pos = Vec3(-0.5f, 0.5f, 0.5f);
vec[0].color = Vec4(1.f, 0.f, 0.f, 1.f);
vec[1].pos = Vec3(0.5f, 0.5f, 0.5f);
vec[1].color = Vec4(0.f, 1.f, 0.f, 1.f);
vec[2].pos = Vec3(0.5f, -0.5f, 0.5f);
vec[2].color = Vec4(0.f, 0.f, 1.f, 1.f);

vec[3].pos = Vec3(0.5f, -0.5f, 0.5f);
vec[3].color = Vec4(0.f, 0.f, 1.f, 1.f);
vec[4].pos = Vec3(-0.5f, -0.5f, 0.5f);
vec[4].color = Vec4(0.f, 1.f, 0.f, 1.f);
vec[5].pos = Vec3(-0.5f, 0.5f, 0.5f);
vec[5].color = Vec4(1.f, 0.f, 0.f, 1.f);
	*/
	vector<Vertex> vec(4);
	vec[0].pos = Vec3(-0.5f, 0.5f, 0.5f);
	vec[0].color = Vec4(1.f, 0.f, 0.f, 1.f);
	vec[0].uv = Vec2(0.f,0.f);
	vec[1].pos = Vec3(0.5f, 0.5f, 0.5f);
	vec[1].color = Vec4(0.f, 1.f, 0.f, 1.f);
	vec[1].uv = Vec2(1.f, 0.f);
	vec[2].pos = Vec3(0.5f, -0.5f, 0.5f);
	vec[2].color = Vec4(0.f, 0.f, 1.f, 1.f);
	vec[2].uv = Vec2(1.f, 1.f);
	vec[3].pos = Vec3(-0.5f, -0.5f, 0.5f);
	vec[3].color = Vec4(0.f, 1.f, 0.f, 1.f);
	vec[3].uv = Vec2(0.f, 1.f);

	vector<uint32> indexVec;
	{
		indexVec.push_back(0);
		indexVec.push_back(1);
		indexVec.push_back(2);
	}
	{
		indexVec.push_back(0);
		indexVec.push_back(2);
		indexVec.push_back(3);
	}

	gameobject->Init();

	shared_ptr<MeshRenderer>meshRenderer = make_shared<MeshRenderer>();
	{
		shared_ptr<Mesh>mesh = make_shared<Mesh>();
		mesh->Init(vec, indexVec);
		meshRenderer->SetMesh(mesh);
	}

	{
		shared_ptr<Shader>shader = make_shared<Shader>();
		shared_ptr<Texture>texture = make_shared<Texture>();
		shader->Init(L"..\\Resources\\Shader\\default.hlsli");
		texture->Init(L"..\\Resources\\Texture\\unreal.png");

		shared_ptr<Material>material = make_shared<Material>();
		material->SetShader(shader);
		material->SetFloat(0, 0.1f);
		material->SetFloat(1, 0.2f);
		material->SetFloat(2, 0.3f);
		material->SetFloat(3, 0.4f);
		material->SetTexture(0, texture);
		meshRenderer->SetMaterial(material);
	}
	
	gameobject->AddComponent(meshRenderer);
	


	GEngine->GetcmdQ()->WaitSync();
}

void Game::Update()
{
	GEngine->Update();
	GEngine->RenderBegin();
	gameobject->Update();
	//{
	//	static Transform t = {};
	//	if (INPUT->GetButton(KEY_TYPE::W))t.offset.y += 1.f*DELTA_TIME;
	//	if (INPUT->GetButton(KEY_TYPE::S))t.offset.y -= 1.f * DELTA_TIME;
	//	if (INPUT->GetButton(KEY_TYPE::A))t.offset.x -= 1.f * DELTA_TIME;
	//	if (INPUT->GetButton(KEY_TYPE::D))t.offset.x += 1.f * DELTA_TIME;
	//		
	//	//t.offset = Vec4(0.75f, 0.f, 0.3f, 0.f);
	//	mesh->SetTransform(t);
	//	mesh->Render();
	//}
	/*{
		Transform t;
		t.offset = Vec4(0.25f, 0.25f, 0.2f, 0.f);
		mesh->SetTransform(t);
		mesh->Render();
	}*/

	GEngine->RenderEnd();

}
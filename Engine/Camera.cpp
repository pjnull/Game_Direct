#include "pch.h"
#include "Camera.h"
#include "Engine.h"
#include "Transform.h"
#include "Scene.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "MeshRenderer.h"

Matrix Camera::S_MatProjection;
Matrix Camera::S_MatView;


Camera::Camera():Component(COMPONENT_TYPE::CAMERA)
{
}

void Camera::FinalUpdate()
{
	_matView = GetTransform()->GetLocalToWorlMatrix().Invert();

	float width = static_cast<float>(GEngine->GetWindow().width);
	float height = static_cast<float>(GEngine->GetWindow().height);

	if (_type == Projection_Type::PERSPECTIVE)
	{
		_matProjection = ::XMMatrixPerspectiveLH(_fov,width/height,_near,_far);
	}
	else
		_matProjection = ::XMMatrixOrthographicLH(width*_scale,height*_scale,_near,_far);
}

void Camera::Render()
{
	shared_ptr<Scene> scene = GET_SINGLE(SceneManager)->GetActiveScene();
	const vector<shared_ptr<GameObject>>& gameObjects = scene->GetGameObjects();

	for (auto& gameObject : gameObjects)
	{
		if (gameObject->GetMeshRenderer() == nullptr)continue;
		gameObject->GetMeshRenderer()->Render();
	}
}

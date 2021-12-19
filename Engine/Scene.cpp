#include "pch.h"
#include "Scene.h"
#include "GameObject.h"

void Scene::Awake()
{
	for (const shared_ptr<GameObject>& gameObject : _gameobject)
	{
		gameObject->Awake();
	}
}

void Scene::Start()
{
	for (const shared_ptr<GameObject>& gameObject : _gameobject)
	{
		gameObject->Start();
	}
}

void Scene::Update()
{
	for (const shared_ptr<GameObject>& gameObject : _gameobject)
	{
		gameObject->Update();
	}
}

void Scene::LateUpdate()
{
	for (const shared_ptr<GameObject>& gameObject : _gameobject)
	{
		gameObject->LateUpdate();
	}
}

void Scene::FinalUpdate()
{
	for (const shared_ptr<GameObject>& gameObject : _gameobject)
	{
		gameObject->FinalUpdate();
	}
}

void Scene::AddGameObject(shared_ptr<GameObject> gameobject)
{
	_gameobject.push_back(gameobject);
}

void Scene::RemoveGameObject(shared_ptr<GameObject> gameobject)
{
	auto findit = std::find(_gameobject.begin(), _gameobject.end(), gameobject);
	if (findit != _gameobject.end())
	{
		_gameobject.erase(findit);
	}
}

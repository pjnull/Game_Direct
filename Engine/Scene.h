#pragma once
class GameObject;


class Scene
{
public:
	void Awake();
	void Start();
	void Update();
	void LateUpdate();

	void AddGameObject(shared_ptr<GameObject>gameobject);
	void RemoveGameObject(shared_ptr<GameObject>gameobject);

private:
	vector<shared_ptr<GameObject>>_gameobject;
};


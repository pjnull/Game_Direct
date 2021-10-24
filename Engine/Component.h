#pragma once
#include "Enginepch.h"

class GameObject;
class Transform;

enum class COMPONENT_TYPE : uint8
{
	TRANSFORM,
	MESH_RENDERER,
	MONO_BEHAVIOUR,
	END,
};

enum
{
	FIXED_COMPONENT_COUNT = static_cast<uint8>(COMPONENT_TYPE::END) - 1
};
class Component
{
public:

	Component(COMPONENT_TYPE type);
	virtual ~Component();

public:
	virtual void	Awake() {}//제일 처음 호출
	virtual void	Start() {}//2
	virtual void	Update() {}//3
	virtual void	LateUpdate() {}//제일 마지막에 호출

public:
	COMPONENT_TYPE GetType() { return _type; }
	bool IsValid() { return _gameObject.expired() == false; }

	shared_ptr<GameObject> GetGameObject();
	shared_ptr<Transform> GetTransform();

private:
	friend class GameObject;
	void SetGameObject(shared_ptr<GameObject> gameObject) { _gameObject = gameObject; }

protected:
	COMPONENT_TYPE	_type;
	weak_ptr<GameObject> _gameObject;
};


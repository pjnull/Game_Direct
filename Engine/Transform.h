#pragma once
#include "Component.h"
#include "Enginepch.h"

struct TransformMatrix
{
	Vec4 offset;
};

class Transform	: public Component
{
public:

	Transform();
	virtual ~Transform();

	virtual void FinalUpdate() override;
	void PushData();


public:
	const Vec3& GetLocalPosition() { return _localPosition; }
	const Vec3& GetLocalRotation() { return _localRotation; }
	const Vec3& GetLocalScale() { return _localScale; }

	const Matrix& GetLocalToWorlMatrix() { return _matrixWorld; }
	const Vec3& GetWorlPositon() { return _matrixWorld.Translation(); }

	Vec3 GetRight() { return _matrixWorld.Right(); }
	Vec3 GetUp() { return _matrixWorld.Up(); }
	Vec3 GetLook() { return _matrixWorld.Backward(); }

	void SetLocalPosition(const Vec3& position) { _localPosition = position; }
	void SetLocalRotation(const Vec3& rotation) { _localPosition = rotation; }
	void SetLocalScale(const Vec3& scale) { _localPosition = scale; }

public:
	void SetParent(shared_ptr<Transform>parent) { _parent = parent; }
	weak_ptr<Transform>GetParent() { return _parent; }

private:
	Vec3 _localPosition = {};
	Vec3 _localRotation = {};
	Vec3 _localScale = {1.f,1.f,1.f};
	Matrix _matrixLocal = {};
	Matrix _matrixWorld = {};

	weak_ptr<Transform> _parent;
};


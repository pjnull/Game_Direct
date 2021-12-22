#pragma once
#include "Component.h"

enum class Projection_Type
{
	PERSPECTIVE,//���� ����
	ORTHOGRAPHIC,//���� ����
};


class Camera:public Component
{
public:
	Camera();
	virtual ~Camera()
	{

	}
	virtual void FinalUpdate() override;
	void Render();

private:
	Projection_Type _type = Projection_Type::PERSPECTIVE;

	float _near=1.f;
	float _far=1000.f;
	float _fov=XM_PI/4.f;
	float _scale=1.f;

	Matrix _matView = {};
	Matrix _matProjection = {};

public:
	static Matrix S_MatView;
	static Matrix S_MatProjection;


};


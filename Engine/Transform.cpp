#include "pch.h"
#include "Transform.h"
#include "Engine.h"
#include "Camera.h"
Transform::Transform() : Component(COMPONENT_TYPE::TRANSFORM)
{
}

Transform::~Transform()
{
}

void Transform::FinalUpdate()
{
	Matrix matScale = Matrix::CreateScale(_localScale);
	Matrix matTranslation = Matrix::CreateTranslation(_localPosition);
	Matrix matRotation = Matrix::CreateRotationX(_localRotation.x);
	matRotation *= Matrix::CreateRotationY(_localRotation.y);
	matRotation *= Matrix::CreateRotationZ(_localRotation.z);
	_matrixLocal = matScale * matRotation * matTranslation;
	_matrixWorld = _matrixLocal;

	shared_ptr<Transform>parent = GetParent().lock();
	if (parent != nullptr)
	{
		_matrixWorld *= parent->GetLocalToWorlMatrix();
	}

}

void Transform::PushData()
{

	Matrix matWVP = _matrixWorld * Camera::S_MatView * Camera::S_MatProjection;
	CONST_BUFFER(CONSTANT_BUFFER_TYPE::TRANSFORM)->PushData(&matWVP, sizeof(matWVP));

}


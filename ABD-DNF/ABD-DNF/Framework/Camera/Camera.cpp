#include "framework.h"
#include "Camera.h"

Camera* Camera::_instance = nullptr;
Camera::Camera()
{
	_view = make_shared<Transform>();
	_uiView = make_shared<Transform>();
	_uiView->Update();
	_projection = make_shared<MatrixBuffer>();

	//XMMATRIX projMatrix = XMMatrixOrthographicOffCenterLH(0,WIN_WIDTH,0,WIN_HEIGHT,0.0f, 1.0f);
	XMMATRIX projMatrix = XMMatrixOrthographicLH(WIN_WIDTH, WIN_HEIGHT, 0.0f, 1.0f);
	_projection->SetData(projMatrix);
	_projection->Update_Resource();

	SetViewPort(WIN_WIDTH, WIN_HEIGHT);
}

Camera::~Camera()
{
}

void Camera::Update()
{
	if (_target.expired())
		FreeMode();
	else
		FollowMode();

	

	_view->Update();
}

void Camera::PostRender()
{
	

	Vector2 temp = GetWorldMousePos();
	ImGui::Text("World_mousePos: { %.0f, %.0f }", temp.x, temp.y);
	ImGui::Text("Win_mousePos: { %.0f, %.0f }", WIN_MOUSE_POS.x, WIN_MOUSE_POS.y);
}

void Camera::ShakeStart(float magnitude, float duration, float reduceDamping)
{
	_magnitude = magnitude;
	_duration = duration;
	_reduceDamping = reduceDamping;

	_originPos = -_view->GetWorldPos();
}

void Camera::SetViewPort(UINT width, UINT height)
{
	D3D11_VIEWPORT vp;
	vp.Width = width;
	vp.Height = height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	DC->RSSetViewports(1, &vp);
}

void Camera::SetViewBuffer()
{
	_view->SetWorldBuffer(1);
}

void Camera::SetUIViewBuffer()
{
	_uiView->SetWorldBuffer(1);
}

void Camera::SetProjectionBuffer()
{
	_projection->SetVS_Buffer(2);
}

void Camera::SetPosition(Vector2 pos)
{
	_view->SetPosition(-pos);
}

void Camera::SetScale(Vector2 scale)
{
	_view->SetScale(scale);
}

void Camera::SetAngle(float angle)
{
	_view->SetAngle(-angle);
}

void Camera::AddVector2(Vector2 pos)
{
	_view->AddVector2(-pos);
}

void Camera::AddScale(Vector2 scale)
{
	_view->AddScale(scale);
}

void Camera::AddAngle(float angle)
{
	_view->AddAngle(-angle);
}

Vector2 Camera::GetWorldMousePos()
{
	XMMATRIX inverseMatrix = DirectX::XMMatrixInverse(nullptr, _view->GetSRT());

	Vector2 mousePos = WIN_MOUSE_POS - CENTER;
	return mousePos.TransformCoord(inverseMatrix);
}

Vector2 Camera::GetScreenMousePos()
{
	return WIN_MOUSE_POS - CENTER;
}

void Camera::Shake()
{
	if (_duration <= 0.0f)
		return;

	_duration -= DELTA_TIME;
	_magnitude -= _reduceDamping * DELTA_TIME;

	if (_magnitude <= 0.0f)
	{
		_magnitude = 0.0f;
		_duration = 0.0f;
	}

	Vector2 randomPos;
	randomPos.x = _originPos.x + MathUtility::RandomFloat(-_magnitude, _magnitude);
	randomPos.y = _originPos.y + MathUtility::RandomFloat(-_magnitude, _magnitude);
	SetPosition(randomPos);

	if (_duration <= 0.0f)
	{
		_magnitude = 0.0f;
		SetPosition(_originPos);
	}
}

void Camera::FreeMode()
{
	if (KEY_PRESS(VK_RBUTTON))
	{
		if (KEY_PRESS('W'))
		{
			AddVector2(UP_VECTOR * DELTA_TIME * _speed);
		}

		if (KEY_PRESS('S'))
		{
			AddVector2(-UP_VECTOR * DELTA_TIME * _speed);
		}

		if (KEY_PRESS('D'))
		{
			AddVector2(RIGHT_VECTOR * DELTA_TIME * _speed);
		}

		if (KEY_PRESS('A'))
		{
			AddVector2(-RIGHT_VECTOR * DELTA_TIME * _speed);
		}
		
		
	

	}
}

void Camera::FollowMode()
{
	Vector2 targetPos = _target.lock()->GetWorldPos() - _offset;
	
	if (targetPos.x < _leftBottom.x + WIN_WIDTH * 0.5f)
		targetPos.x = _leftBottom.x + WIN_WIDTH * 0.5f;
	
	if (targetPos.x > _rightTop.x - WIN_WIDTH * 0.5f)
		targetPos.x = _rightTop.x - WIN_WIDTH * 0.5f;
	
	if (targetPos.y < _leftBottom.y + WIN_HEIGHT * 0.5f)
		targetPos.y = _leftBottom.y + WIN_HEIGHT * 0.5f;
	
	if (targetPos.y > _rightTop.y - WIN_HEIGHT * 0.5f)
		targetPos.y = _rightTop.y - WIN_HEIGHT * 0.5f;
	
	Vector2 temp = LERP(-_view->GetWorldPos(), targetPos, 0.04f);

	SetPosition(temp);
}

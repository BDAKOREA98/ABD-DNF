// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <time.h>
#include <tchar.h>
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <wrl/client.h>
#include <functional>
#include <iostream>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <dwrite.h>

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")

// DirectX Tex
#include "../DXTex/DirectXTex.h"

// Imgui
#include "../ImGUI/imgui.h"
#include "../ImGUI/imgui_impl_dx11.h"
#include "../ImGUI/imgui_impl_win32.h"
#include <d2d1.h>
// FMOD
#include "Library/FMOD/inc/fmod.hpp"
#pragma comment(lib,"Library/FMOD/fmod_vc.lib")

using namespace std;
using namespace DirectX;
using namespace Microsoft::WRL;

// Framework
#include "Framework/Device/Device.h"

// Math
#include "Framework/Math/Vector2.h"
#include "Framework/Math/MathUtility.h"
#include "Framework/Math/Transform.h"

// Utility
#include "Framework/Utility/Timer.h"
#include "Framework/Utility/InputManager.h"
#include "Framework/Utility/tinyxml2.h"
#include "Framework/Utility/SoundManager.h"

// Render
#include "Framework/Render/ConstantBuffer.h"
#include "Framework/Render/GlobalBuffer.h"
#include "Framework/Render/VertexLayout.h"
#include "Framework/Render/VertexBuffer.h"
#include "Framework/Render/IndexBuffer.h"
#include "Framework/Render/Shader.h"
#include "Framework/Render/VertexShader.h"
#include "Framework/Render/PixelShader.h"
#include "Framework/Render/ShaderManager.h"





// TextureMapping
#include "Framework/TextureMapping/SRV.h"
#include "Framework/TextureMapping/SRVManager.h"
#include "Framework/TextureMapping/SamplerState.h"
#include "Framework/TextureMapping/BlendState.h"
#include "Framework/TextureMapping/StateManager.h"

// Collider
#include "Framework/Collider/Collider.h"
#include "Framework/Collider/CircleCollider.h"
#include "Framework/Collider/RectCollider.h"

// Action
#include "Framework/Animation/Action.h"


// Obj
#include "Object/BasicObject/Quad.h"
#include "Object/BasicObject/Sprite.h"
#include "Object/BasicObject/Sprite_Frame.h"
#include "Object/BasicObject/Sprite_Clip.h"
#include "Object/BasicObject/Effect.h"
#include "Object/BasicObject/EffectManager.h"

//DUN
#include "Object/DUN/Map.h"
#include "Object/DUN/Map2.h"
#include "Object/DUN/Creature.h"
#include "Object/DUN/Item.h"
#include "Object/DUN/Inventory.h"
#include "Object/DUN/HP.h"
#include "Object/DUN/MP.h"
#include "Object/DUN/UI.h"

#include "Object/DUN/Player.h"
#include "Object/DUN/Monster_mad.h"

// Camera
#include "Object/DUN/PlayerManager.h"
#include "Framework/Camera/Camera.h"

#define PLAYER		PlayerManager::GetPlayer()

// Scene
#include "Scene/Scene.h"
#include "Scene/SceneManager.h"

// Program
#include "Program/Program.h"

#include "Types.h"

extern HWND hWnd;
extern Vector2 PlayerScenePos;
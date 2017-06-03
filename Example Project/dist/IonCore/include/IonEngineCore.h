#ifndef IONENGINECORE_H
#define IONENGINECORE_H

// System includes
#include <math.h>
#include <assert.h>

// External Libraries
#include "DirectXTex.h"	//	Needed?
#include "MathEngine.h"
#include "File.h"

// Helper includes
#include "DebugOut.h"
#include "d3dUtil.h"
#include "Color.h"


// Inputs includes
#include "Keyboard.h"
#include "Mouse.h"

// Engine 
#include "Engine.h"
#include "Model.h"
#include "GpuVertTypes.h"
#include "Camera.h"
#include "Texture.h"
#include "Image.h"
#include "Rect.h"

// Shaders
#include "ShaderBase.h"
#include "ShaderColor.h"
#include "ShaderTexture.h"
#include "ShaderColorLight.h"
#include "ShaderTextureLight.h"
#include "ShaderColorVary.h"
#include "ShaderSprite.h"


// Graphics Objects
//*
#include "GraphicsObject_Base.h"
///#include "GraphicsObject_ColorByPosition.h"
#include "GraphicsObject_Color.h"
#include "GraphicsObject_Color_Light.h"
#include "GraphicsObject_WireframeColor.h"
#include "GraphicsObject_WireframeColorAuto.h"
#include "GraphicsObject_Texture.h"
#include "GraphicsObject_Texture_Light.h"
#include "GraphicsObject_Sprite.h"
///#include "GraphicsObject_SpriteBox.h"
//*/

#endif
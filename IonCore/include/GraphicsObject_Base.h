#ifndef _GraphicsObject_Base
#define _GraphicsObject_Base

#include "Matrix.h"

class Model;
class ShaderMeshData;
struct ID3D11DeviceContext;
class ShaderBase;
class Camera;
//class ShaderDrawCommand;

class GraphicsObject_Base : public Align16
{
public:
	GraphicsObject_Base(const GraphicsObject_Base&) = delete;				   // Copy constructor
	GraphicsObject_Base(GraphicsObject_Base&&) = default;                    // Move constructor
	GraphicsObject_Base& operator=(const GraphicsObject_Base&) & = default;  // Copy assignment operator
	GraphicsObject_Base& operator=(GraphicsObject_Base&&) & = default;       // Move assignment operator
	~GraphicsObject_Base() = default;		  							   // Destructor
	GraphicsObject_Base();

	void SetModel(Model* mod);
	Model* getModel() { return pModel; };

	virtual void SetWorld(const Matrix& mat) { World = mat; };
	virtual Matrix& GetWorld() { return World; };

	virtual void Render(Camera* mCam) = 0;
	//virtual void UpdateDrawCmd() = 0;

protected:
	//ShaderDrawCommand*	pDrawCmd;
	Model* pModel;
	Matrix World;
};

#endif _GraphicObject_Base

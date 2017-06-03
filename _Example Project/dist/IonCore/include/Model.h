#ifndef MODEL_H
#define MODEL_H

#include <d3d11.h>
#include "Align16.h"

#include "Vect.h"
#include "Matrix.h"

class MeshSeparator;
struct StandardVertex;
struct TriangleByIndex;

class Model	: public Align16
{
private:
	MeshSeparator* meshes;

	// Model information
	TriangleByIndex *pTriList;
	StandardVertex* pStdVerts;
	Vect* pVectList;

	// GPU connections
	ID3D11Device*			mDevice;
	ID3D11Buffer*           mpVertexBuffer;
	ID3D11Buffer*           mpIndexBuffer;

	// AABB: axis aligned bounding box
	// Specifies the minimum extent of this AABB in the world space x, y and z axes.
	Vect minPointAABB;
	// Specifies the maximum extent of this AABB in the world space x, y and z axes
	Vect maxPointAABB;

	// Bounding Sphere: bounding volume
	Vect center;
	float radius;

	char *textNames;
	int numTextures;

	int numVerts;
	int numTris;


	//	============================================

	void privLoadDataToGPU();
	void privLoadDataFromFile(const char * const _modelName, StandardVertex*& pVerts, int& nverts, TriangleByIndex*& ptlist, int& ntri);

public:
	Model(const Model&) = delete;				// Copy constructor
	Model(Model&&) = delete;                    // Move constructor
	Model& operator=(const Model&) & = delete;  // Copy assignment operator
	Model& operator=(Model&&) & = delete;       // Move assignment operator

	enum PreMadedeModels {
		UnitBox,
		UnitBox_RepeatedTexture,
		UnitBox_SixFaceTexture,
		UnitPyramid,
		UnitPyramid_RepeatedTexture,
		UnitSphere,
		UnitSphere_Texture,
		UnitBox2D
	};

	Model() = delete;
	Model(StandardVertex *pVerts, int nverts, TriangleByIndex *ptlist, int ntri);
	Model(PreMadedeModels pm);
	Model(const char * const _modelName);

	virtual ~Model();

	void BindVertexIndexBuffers(ID3D11DeviceContext* context);
	void Render(ID3D11DeviceContext* context);
	void RenderMesh(ID3D11DeviceContext* context, int meshnum);

	// Get access
	int GetMeshCount();
	bool ValidMeshNum(int i);

	// Get the texture name
	char *getTextureName(int index);
	int getTextureNum()
	{
		return numTextures;
	};

	// Get access
	Vect* getVectList(void);
	int getVectNum()
	{
		return numVerts;
	}

	TriangleByIndex *getTriangleList(void);
	int getTriNum()
	{
		return numTris;
	};

	StandardVertex* getStdVertList(void);

	const Vect& getCenter() const { return center; }
	const float getRadius() const { return radius; }
	const Vect& getMinAABB() const { return minPointAABB; }
	const Vect& getMaxAABB() const { return maxPointAABB; }
};



#endif
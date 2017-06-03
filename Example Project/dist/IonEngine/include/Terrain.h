#ifndef TERRAIN_H
#define TERRAIN_H

#include "Color.h"
#include "RenderType.h"
#include "TerrainCellStruct.h"

class Matrix;

class Model;
class Texture;

class GraphicsObject_Texture_Light;
class ShaderBase;
class Camera;
class Collidable;

/////////////////////////////////////////////////
///	\ingroup TERRAIN
/// \class Terrain
///	\brief Terrain class for 3D terrain
///
///	The Terrain Object allows users to define a 3D textured and lit terrain
///	based off of a heightmap texture. The class also provides various functions
///	for interacting with the terrain.
/////////////////////////////////////////////////
class Terrain : public RenderType
{
	friend class TerrainArea;
	friend class TerrainAssets;
private:
	CellAABB* CellArray;
	Model* pModel;
	GraphicsObject_Texture_Light* pGObj;

	float gridLength;
	float half_width;

	int side_Verts;
	int width;

	int num_Cells;

	int GetPixelHeight(size_t side, size_t pixel_width, int x, int y);
	float NormalizedHeight(unsigned char h);

	Model* GenerateTerrain(const wchar_t* tex, int heightFactor, int RepeatU, int RepeatV);


	//*
	//float GetHeight(const Vect& pos) const;
	//Vect GetSurfaceNormal(const Vect& pos);

	const CellAABB& GetCell(int index) const;
	int GetCellIndex(const Vect& pos) const;
	int GetGridLength() { return (int)gridLength; };

	virtual void Render(Camera* pCam) override;
	//*/

	// Private default constructor
	Terrain() = delete;
public:
	Terrain(const wchar_t* Height_Map_Path, Texture* tex, ShaderBase* shader, const Vect& lightCol, int width, int height, int RepeatU, int RepeatV);
	~Terrain();
	Terrain(const Terrain&) = delete;
	Terrain& operator=(const Terrain&) = delete;

	/////////////////////////////////////////////////
	///	\brief Function that sets the world matrix of the Terrain
	///
	/// \param mat A const Matrix reference for the world.
	/////////////////////////////////////////////////
	void SetWorld(const Matrix& mat);
	/////////////////////////////////////////////////
	///	\brief Function that gets the world matrix of the Terrain
	///
	/// \return reference to world Matrix.
	/////////////////////////////////////////////////
	Matrix& GetWorld();

	/////////////////////////////////////////////////
	///	\brief Function that sets the Light colors of the Terrain
	///
	///	This function takes a single color vect and applies it to
	/// the ambient, diffuse, and specular light of the Terrain Object.
	///
	/// \param lightCol Color vect for ambient, diffuse, and specular light
	/////////////////////////////////////////////////
	void SetLightColors(const Vect& lightCol);
	/////////////////////////////////////////////////
	///	\brief Function that sets the Light colors of the Terrain
	///
	///	This function takes in (and applies) a seperate color vect for
	/// the ambient, diffuse, and specular light of the Terrain Object.
	///
	/// \param amb Color vect for ambient light
	/// \param diff Color vect for diffuse light
	/// \param spec Color vect for specular light
	/////////////////////////////////////////////////
	void SetLightColors(const Vect& amb, const Vect& diff, const Vect& spec);

	/////////////////////////////////////////////////
	///	\brief Function that sets the Terrain's texture
	///
	/// \param tex A pointer to the Texture to be used
	/////////////////////////////////////////////////
	void SetTexture(Texture* tex);

	/////////////////////////////////////////////////
	///	\brief Function that finds the surface point from a given world position
	///
	///	This function takes in a vector position in world space and
	///	returns a similar vector position with an adjusted Y to the Terrain's
	///	surface. If the provided position is not above or below the Terrain
	///	then the returning vector will have a Y of zero.
	///
	/// \param pos Vect position in world space
	///
	///	\return Vect position of surface point
	/////////////////////////////////////////////////
	Vect GetSurfacePoint(const Vect& pos);
};

#endif // !TERRAIN_H

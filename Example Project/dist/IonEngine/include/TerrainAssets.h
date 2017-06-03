#ifndef TERRAINASSETS_H
#define TERRAINASSETS_H

#include <map>

class Terrain;
class Texture;
class ShaderBase;
class Vect;

/////////////////////////////////////////////////
///	\ingroup RESOURCES
///	\ingroup TERRAIN
/// \class TerrainAssets
///	\brief System manager for for creating and accessing Terrain objects from external resources.
///
///	The TerrainAssets is a singleton that allows the user to create and resuse
///	Terrain objects throughout their code.
///	
///	Terrains are created via the Load() function in the IonEngine::LoadResources()
/// function. They can then be accessed by using the Get() function with the associated
///	key that the user defined upon loading.
/////////////////////////////////////////////////
class TerrainAssets
{
	friend class IonEngine;
public:
	typedef std::string TerrainKey;	/*!< Typedef of an std::string for an easier to read name. */
private:
	static TerrainAssets* ptrInstance;
	std::map<TerrainKey, Terrain*> TerrainMap;

	TerrainAssets() = default;								// Private constructor
	TerrainAssets(const TerrainAssets&) = delete;				// Prevent copy-construction
	TerrainAssets& operator=(const TerrainAssets&) = delete;	// Prevent assignment
	~TerrainAssets();										// Only this class can delete

	static TerrainAssets& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new TerrainAssets;
		return *ptrInstance;
	};

	void privLoad(const TerrainKey& Terrain_Map_Key, const wchar_t* texHeight, ShaderBase* shader, const Vect& lightCol, int width, int height, int RepeatUV, Texture* pTexture);

	Terrain* privGet(const TerrainKey& Terrain_Map_Key);

	static void Delete();
public:
	/////////////////////////////////////////////////
	///	\brief Function creates and saves a Terrain object.
	///
	///	This Load() function creates and stores a Terrain Object based off of the
	///	HeightMap_Tex_Path parameter. The Terrain_Map_Key parameter is a key string for access
	///	later when using the Get() command.
	///
	///	NOTE: The file paths start within the "Assets" directory of the root project directory
	///
	///	\param Terrain_Map_Key An std::string for use as a storage key
	///
	///	\param HeightMap_Tex_Path A wide char string for path to Heightmap (starting in the "Assets" directory)
	///
	///	\param pShader Shader pointer for the Terrain object (NOTE: only use ShaderTextureLight pointers)
	///
	///	\param Light_Color Color vect for the color of the light
	///
	///	\param Scale_width int for scaling the size of the terrain
	///
	///	\param Scale_height int for scaling the highest point of the terrain.
	///
	///	\param RepeatUV int for the number of times to repeat a Texture across 
	///
	///	\param pTexture pointer to the Texture to use with the terrain
	///
	/////////////////////////////////////////////////
	static void Load(const TerrainKey& Terrain_Map_Key, const wchar_t* HeightMap_Tex_Path, ShaderBase* pShader, const Vect& Light_Color, int Scale_width, int Scale_height, int RepeatUV, Texture* pTexture)
	{
		Instance().privLoad(Terrain_Map_Key, HeightMap_Tex_Path, pShader, Light_Color, Scale_width, Scale_height, RepeatUV, pTexture);
	};

	/////////////////////////////////////////////////
	///	\brief Function returns Terrain pointer based off of the passed in key.
	///
	///	This Get() function uses it's Terrain_Map_Key parameter to search the
	///	Terrain map and return the Terrain object saved under the same key string.
	///
	///	\param Terrain_Map_Key An std::string for use as a key to access the stored Terrain
	///
	///	\return Pointer to Terrain object at stored key
	/////////////////////////////////////////////////
	static Terrain* Get(const TerrainKey& Terrain_Map_Key) { return Instance().privGet(Terrain_Map_Key); };
};



#endif
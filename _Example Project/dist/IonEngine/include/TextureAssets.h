#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <map>

class Texture;

/////////////////////////////////////////////////
///	\ingroup RESOURCES
/// \class TextureAssets
///	\brief System manager for saving and accessing external texture resources.
///
///	The TextureAssets is a singleton that allows the user to resuse saved
///	external texture resources throughout their project.
///	
///	Textures are saved via the Load() functions in the IonEngine::LoadResources()
/// function. They can then be accessed by using the Get() functions and the associated
///	key that the user defined upon loading.
/////////////////////////////////////////////////
class TextureAssets
{
friend class IonEngine;	//	Access Delete Function
public:
	typedef std::string TextureKey;		/*!< Typedef of an std::string for an easier to read name. */
private:
	static TextureAssets* ptrInstance;
	std::map<TextureKey, Texture*> TextureMap;

	TextureAssets() = default;									// Private constructor
	TextureAssets(const TextureAssets&) = delete;				// Prevent copy-construction
	TextureAssets& operator=(const TextureAssets&) = delete;	// Prevent assignment
	~TextureAssets();											// Only this class can delete

	static TextureAssets& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new TextureAssets;
		return *ptrInstance;
	};

	void privLoad(const TextureKey& Texture_Map_Key, const char* Texture_File_Path);
	//void privLoad(const TextureKey& Texture_Map_Key, const unsigned char& char_Red, const unsigned char& char_Green, const unsigned char& char_Blue);
	void privLoad(const TextureKey& Model_Map_Key);
	Texture* privGet(const TextureKey& Texture_Map_Key);
	Texture* privGet(const TextureKey& Model_Map_Key, int Texture_Number);

	static void Delete();
public:
	/////////////////////////////////////////////////
	///	\brief Function saves a texture created from the desired path.
	///
	///	This Load() function creates and stores a texture pointer based off of the
	///	Texture_File_Path parameter. The Texture_Map_Key parameter is a key string for access
	///	later when using the Get() command.
	///
	///	NOTE: The file paths start within the "Assets" directory of the root project directory
	///	\param Texture_Map_Key An std::string for use as a storage key
	///
	///	\param Texture_File_Path A char string to the file path (starting in the "Assets" directory)
	/////////////////////////////////////////////////
	static void Load(const TextureKey& Texture_Map_Key, const char* Texture_File_Path) { Instance().privLoad(Texture_Map_Key, Texture_File_Path); };
	
	/////////////////////////////////////////////////
	///	\brief Function saves all textures from a loaded model.
	///
	///	This Load() function creates and stores a texture pointer based off of all the
	///	textures associated with a specified model. This function accesses the model via the ModelManager
	///	and the specified Model_Map_Key string. All textures loaded via this function will use the file name of the
	///	textures as the TextureKey string for later access.
	///
	///	Alternatively, the user can individually call the Load(const TextureKey& Texture_Map_Key, const char* Texture_File_Path) function multiple times
	///	in order to specify the key string name of each texture.
	///
	///	\param Model_Map_Key An std::string for use as a key to access the stored model.
	/////////////////////////////////////////////////
	static void Load(const TextureKey& Model_Map_Key) { Instance().privLoad(Model_Map_Key); }
	
	/////////////////////////////////////////////////
	///	\brief Function returns texture pointer based off of the passed in key.
	///
	///	This Get() function uses it's Texture_Map_Key parameter to search the
	///	texture map and return the texture saved under the same key string.
	///
	///	\param Texture_Map_Key An std::string for use as a key to access the stored texture
	///
	///	\return Pointer to texture at stored key
	/////////////////////////////////////////////////
	static Texture* Get(const TextureKey& Texture_Map_Key) { return Instance().privGet(Texture_Map_Key); };

	/////////////////////////////////////////////////
	///	\brief Function returns texture pointer that is associated with a loaded Model.
	///
	///	This Get() function uses it's Model_Map_Key parameter and Texture_Number parameter
	///	to grab a specific texture that is associated with a model.
	///
	///	NOTE: In order to use this function, the texture key that is stored MUST BE THE SAME as it's file name.
	///	The Load(const TextureKey& Model_Map_Key) function will automatically do this, but if the textures are indivudually loaded
	/// with keys that are different from their file names, then this function will not work.
	///
	///	\param Model_Map_Key An std::string for use as a key to access the stored model.
	///
	///	\param Texture_Number An integer to access the specified texture tied to the model.
	///
	///	\return pointer to texture
	/////////////////////////////////////////////////
	static Texture* Get(const TextureKey& Model_Map_Key, int Texture_Number) { return Instance().privGet(Model_Map_Key, Texture_Number); };
};

#endif TEXTUREMANAGER_H


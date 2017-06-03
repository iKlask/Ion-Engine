#ifndef SKYBOXASSETS_H
#define SKYBOXASSETS_H

#include <map>

class SkyBox;
class Texture;
class ShaderBase;

/////////////////////////////////////////////////
///	\ingroup RESOURCES
///	\ingroup SKY-BOX
/// \class SkyBoxAssets
///	\brief System manager for for creating and accessing SkyBox objects from external resources.
///
///	The SkyBoxAssets is a singleton that allows the user to create and resuse
///	SkyBox objects throughout their code.
///	
///	SkyBoxes are created via the Load() function in the IonEngine::LoadResources()
/// function. They can then be accessed by using the Get() function with the associated
///	key that the user defined upon loading.
/////////////////////////////////////////////////
class SkyBoxAssets
{
	friend class IonEngine;
public:
	typedef std::string SkyBoxKey;	/*!< Typedef of an std::string for an easier to read name. */
private:
	static SkyBoxAssets* ptrInstance;
	std::map<SkyBoxKey, SkyBox*> SkyBoxMap;

	SkyBoxAssets() = default;								// Private constructor
	SkyBoxAssets(const SkyBoxAssets&) = delete;				// Prevent copy-construction
	SkyBoxAssets& operator=(const SkyBoxAssets&) = delete;	// Prevent assignment
	~SkyBoxAssets();										// Only this class can delete

	static SkyBoxAssets& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new SkyBoxAssets;
		return *ptrInstance;
	};

	void privLoad(const SkyBoxKey& SkyBox_Map_Key, float scale, ShaderBase* shader, Texture* pTexture);

	SkyBox* privGet(const SkyBoxKey& SkyBox_Map_Key);

	static void Delete();
public:
	/////////////////////////////////////////////////
	///	\brief Function saves a SkyBox created from the desired texture.
	///
	/// \param SkyBox_Map_Key
	///
	/// \param scale
	///
	/// \param shader
	///
	/// \param pTexture
	/////////////////////////////////////////////////
	static void Load(const SkyBoxKey& SkyBox_Map_Key, float scale, ShaderBase* shader, Texture* pTexture)
	{
		Instance().privLoad(SkyBox_Map_Key, scale, shader, pTexture);
	};

	/////////////////////////////////////////////////
	///	\brief Function returns SkyBox pointer based off of the passed in key.
	///
	///	This Get() function uses it's SkyBox_Map_Key parameter to search the
	///	SkyBox map and return the SkyBox object saved under the same key string.
	///
	///	\param SkyBox_Map_Key An std::string for use as a key to access the stored SkyBox
	///
	///	\return Pointer to SkyBox object at stored key
	/////////////////////////////////////////////////
	static SkyBox* Get(const SkyBoxKey& SkyBox_Map_Key) { return Instance().privGet(SkyBox_Map_Key); };
};



#endif
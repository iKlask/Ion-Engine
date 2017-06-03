#ifndef SHADERASSETS_H
#define SHADERASSETS_H

#include <map>

class ShaderBase;

/////////////////////////////////////////////////
///	\ingroup RESOURCES
/// \class ShaderAssets
///	\brief System manager for saving and accessing external shader resources.
///
///	The ShaderAssets is a singleton that allows the user to resuse saved
///	external shader resources throughout their project.
///	
///	Shaders are saved via the Load() functions in the IonEngine::LoadResources()
/// function. They can then be accessed by using the Get() functions and the associated
///	key that the user defined upon loading.
/////////////////////////////////////////////////
class ShaderAssets
{
friend class IonEngine;	//	Access Delete Function

public:
	typedef std::string ShaderKey;		/*!< Typedef of an std::string for an easier to read name. */
private:
	static ShaderAssets* ptrInstance;
	std::map<ShaderKey, ShaderBase*> ShaderMap;

	ShaderAssets() = default;									// Private constructor
	ShaderAssets(const ShaderAssets&) = delete;				// Prevent copy-construction
	ShaderAssets& operator=(const ShaderAssets&) = delete;	// Prevent assignment
	~ShaderAssets();											// Only this class can delete

	static ShaderAssets& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ShaderAssets;
		return *ptrInstance;
	};

	void privLoad(const ShaderKey& Shader_Map_Key, ShaderBase* Shader);
	ShaderBase* privGet(const ShaderKey& Shader_Map_Key);

	static void Delete();

	static void LoadDefault();
public:
	/////////////////////////////////////////////////
	///	\brief Function saves a shader created from the desired path.
	///
	///	This Load() function stores a shader pointer in the ShaderAssets map.
	///	The Shader_Map_Key parameter is a key string for access later when using the Get() command.
	///
	///	\param Shader_Map_Key An std::string for use as a storage key
	///
	///	\param Shader A ShaderBase pointer to store
	/////////////////////////////////////////////////
	static void Load(const ShaderKey& Shader_Map_Key, ShaderBase* Shader) { Instance().privLoad(Shader_Map_Key, Shader); };

	/////////////////////////////////////////////////
	///	\brief Function returns shader pointer based off of the passed in key.
	///
	///	This Get() function uses it's Shader_Map_Key parameter to search the
	///	shader map and return the shader saved under the same key string.
	///
	///	\param Shader_Map_Key An std::string for use as a key to access the stored shader
	///
	///	\return Pointer to shader at stored key
	/////////////////////////////////////////////////
	static ShaderBase* Get(const ShaderKey& Shader_Map_Key) { return Instance().privGet(Shader_Map_Key); };
};

#endif


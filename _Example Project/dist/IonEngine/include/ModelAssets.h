#ifndef MODELASSETS_H
#define MODELASSETS_H

#include <map>

class Model;

/////////////////////////////////////////////////
///	\ingroup RESOURCES
/// \class ModelAssets
///	\brief System manager for saving and accessing external model resources.
///
///	The ModelAssets is a singleton that allows the user to resuse saved
///	external model resources throughout their project.
///	
///	Models are saved via the Load() functions in the IonEngine::LoadResources()
/// function. They can then be accessed by using the Get() functions and the associated
///	key that the user defined upon loading.
/////////////////////////////////////////////////
class ModelAssets
{
friend class IonEngine;	//	Access Delete Function

public:
	typedef std::string ModelKey;	/*!< Typedef of an std::string for an easier to read name. */
private:
	static ModelAssets* ptrInstance;
	std::map<ModelKey, Model*> ModelMap;

	ModelAssets() = default;								// Private constructor
	ModelAssets(const ModelAssets&) = delete;				// Prevent copy-construction
	ModelAssets& operator=(const ModelAssets&) = delete;	// Prevent assignment
	~ModelAssets();										// Only this class can delete

	static ModelAssets& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ModelAssets;
		return *ptrInstance;
	};

	void privLoad(const ModelKey& Model_Map_Key, const char* Model_File_Path);
	Model* privGet(const ModelKey& Model_Map_Key);

	static void Delete();

	static void LoadDefault();

public:
	/////////////////////////////////////////////////
	///	\brief Function saves a model created from the desired path.
	///
	///	This Load() function creates and stores a model pointer based off of the
	///	Model_File_Path parameter. The Model_Map_Key parameter is a key string for access
	///	later when using the Get() command.
	///
	///	NOTE: The file paths start within the "Assets" directory of the root project directory
	///	\param Model_Map_Key An std::string for use as a storage key
	///
	///	\param Model_File_Path A char string to the file path (starting in the "Assets" directory)
	/////////////////////////////////////////////////
	static void Load(const ModelKey& Model_Map_Key, const char* Model_File_Path) { Instance().privLoad(Model_Map_Key, Model_File_Path); };

	/////////////////////////////////////////////////
	///	\brief Function returns model pointer based off of the passed in key.
	///
	///	This Get() function uses it's Model_Map_Key parameter to search the
	///	model map and return the model saved under the same key string.
	///
	///	\param Model_Map_Key An std::string for use as a key to access the stored Model
	///
	///	\return Pointer to Model at stored key
	/////////////////////////////////////////////////
	static Model* Get(const ModelKey& Model_Map_Key) { return Instance().privGet(Model_Map_Key); };
};

#endif


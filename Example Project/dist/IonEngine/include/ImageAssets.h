#ifndef IMAGEASSETS_H
#define IMAGEASSETS_H

#include <map>

class Image;
class Texture;
struct Rect;

/////////////////////////////////////////////////
///	\ingroup RESOURCES
/// \class ImageAssets
///	\brief System manager for saving and accessing Images from external resources.
///
///	The ImageAssets is a singleton that allows the user to resuse saved
///	Images from external Texture resources throughout their project.
///	
///	Images are saved via the Load() functions in the IonEngine::LoadResources()
/// function. They can then be accessed by using the Get() functions and the associated
///	key that the user defined upon loading.
/////////////////////////////////////////////////
class ImageAssets
{
	friend class IonEngine;
public:
	typedef std::string ImageKey;	/*!< Typedef of an std::string for an easier to read name. */
private:
	static ImageAssets* ptrInstance;
	std::map<ImageKey, Image*> ImageMap;

	ImageAssets() = default;								// Private constructor
	ImageAssets(const ImageAssets&) = delete;				// Prevent copy-construction
	ImageAssets& operator=(const ImageAssets&) = delete;	// Prevent assignment
	~ImageAssets();										// Only this class can delete

	static ImageAssets& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ImageAssets;
		return *ptrInstance;
	};

	void privLoad(const ImageKey& Image_Map_Key, Texture* pTexture);
	void privLoad(const ImageKey& Image_Map_Key, Texture* pTexture, const Rect& Sub_Image_Rect);

	Image* privGet(const ImageKey& Image_Map_Key);

	static void Delete();

public:
	/////////////////////////////////////////////////
	///	\brief Function saves a Image created from the desired texture.
	///
	///	This Load() function creates and stores a Image pointer based off of the
	///	pTexture parameter. The Image_Map_Key parameter is a key string for access
	///	later when using the Get() command. This function grabs the entire texture as an image.
	///
	///	\param Image_Map_Key An std::string for use as a storage key
	///
	///	\param pTexture A Texture pointer to grab the image from
	/////////////////////////////////////////////////
	static void Load(const ImageKey& Image_Map_Key, Texture* pTexture) { Instance().privLoad(Image_Map_Key, pTexture); };

	/////////////////////////////////////////////////
	///	\brief Function saves a Image created from the desired tecture.
	///
	///	This Load() function creates and stores a Image pointer based off of the
	///	pTexture and Sub_Image_Rect parameters. The Image_Map_Key parameter is a key string for access
	///	later when using the Get() command. This function grabs a specific
	/// sub-image from the texture (based on the Sub_Image_Rect).
	///
	///	\param Image_Map_Key An std::string for use as a storage key
	///
	///	\param pTexture A Texture pointer to grab the image from
	///
	/// \param Sub_Image_Rect A rectangle to specify the sub-image to gram from the texture
	/////////////////////////////////////////////////
	static void Load(const ImageKey& Image_Map_Key, Texture* pTexture, const Rect& Sub_Image_Rect) { Instance().privLoad(Image_Map_Key, pTexture, Sub_Image_Rect); };

	/////////////////////////////////////////////////
	///	\brief Function returns Image pointer based off of the passed in key.
	///
	///	This Get() function uses it's Image_Map_Key parameter to search the
	///	Image map and return the Image saved under the same key string.
	///
	///	\param Image_Map_Key An std::string for use as a key to access the stored Image
	///
	///	\return Pointer to Image at stored key
	/////////////////////////////////////////////////
	static Image* Get(const ImageKey& Image_Map_Key) { return Instance().privGet(Image_Map_Key); };
};


#endif
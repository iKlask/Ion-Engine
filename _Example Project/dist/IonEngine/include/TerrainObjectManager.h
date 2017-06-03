#ifndef TERRAINOBJECTMANAGER_H
#define TERRAINOBJECTMANAGER_H

class RenderType;
class NullTerrain;
class Terrain;
class Camera;

class TerrainObjectManager {
private:
	friend class Scene;

	RenderType* CurTerrain;
	NullTerrain* nullT;

	void RenderTerrain(Camera* pCam);

public:
	TerrainObjectManager();
	~TerrainObjectManager();
	TerrainObjectManager(const TerrainObjectManager&) = delete;
	TerrainObjectManager& operator=(const  TerrainObjectManager&) = delete;

	void SetSceneTerrain(Terrain* t);
	Terrain* GetSceneTerrain();
};

#endif // !TERRAINOBJECTMANAGER_H

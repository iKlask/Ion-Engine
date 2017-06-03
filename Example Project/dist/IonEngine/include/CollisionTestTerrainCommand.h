#ifndef CollisionTestTerrainCommand_H
#define CollisionTestTerrainCommand_H

#include "CollisionCommandBase.h"
#include "CollidableGroup.h"

#include "Visualizer.h"
#include "SceneManager.h"

#include "Terrain.h"
#include "TerrainArea.h"

template<typename C>
class CollisionTestTerrainCommand : public CollisionCommandBase {
private:
	typename const CollidableGroup<C>::CollidableCollection& Collection;
	int numColliding;
public:
	CollisionTestTerrainCommand()
		: Collection(CollidableGroup<C>::GetColliderCollection())
	{};

	~CollisionTestTerrainCommand() {
		DebugMsg::out("Deleteing CollisionTestTerrainCommand...\n");
	}

	virtual void execute() {
		//*
		//	Make sure collection isn't empty
		numColliding = 0;
		if (Collection.size() > 0) {

			Terrain* pTerrain = SceneManager::GetCurrentTerrain();
			CollisionVolumeAABB Cell;
			Vect pos;
			Vect col = Color::DarkGray;
			float radius;
			bool collides;

			//	For Every Collidable in the Group
			for (auto cIt = Collection.begin(); cIt != Collection.end(); cIt++)
			{
				pos = (*cIt)->GetDefualtBSphere().GetCenter();
				radius = (*cIt)->GetDefualtBSphere().GetRadius();

				//*
				TerrainArea cellArea(pTerrain, pos, radius);// = TerrainArea(pTerrain, pos, radius);

				if (cellArea.isPermitted() ) {	//the TerrainArea may be invalid for collision checking
					//	For every Cell within the current Collidable's Default Bsphere
					for (TerrainArea::iterator tIt = cellArea.begin(); tIt != cellArea.end(); tIt++)
					{
						//	Calculate AABB
						Cell.ComputeData(tIt.GetMinCorner(), tIt.GetMaxCorner());

						//	Check for collision from Collidable BSphere to Cell AABB
						collides = IonMathTools::Intersect((*cIt)->GetDefualtBSphere(), Cell);
						if (collides)
						{
							//DrawVisualizer( (*cIt)->GetDefualtBSphere(), Color::Orange);
							//DrawVisualizer(Cell, Color::Orange);
							

							//	If it passes, check Collision of CellAABB with the CollisionVolume of Collidable
							collides = (*cIt)->GetCollisionVolume().Intersect(Cell);
							if (collides)
							{
								(*cIt)->CollisionTerrain();	//trigger collision

								DrawVisualizer((*cIt)->GetCollisionVolume(), Color::Red);
								//DrawVisualizer(Cell, Color::Red);
								numColliding++;
								col = Color::Red;
							}
							else {
								col = Color::Orange;
							}
						}
						else
						{
							//DrawVisualizer( (*cIt)->GetDefualtBSphere(), Color::DarkGray);
							//DrawVisualizer(Cell, Color::Yellow);
							col = Color::Yellow;
						}
						DrawVisualizer(Cell, col);
					}
					//*/
				}

			}
			//DebugMsg::out("Colliding Num: %d\n", numColliding);
		}
		//*/
	}

	void DrawVisualizer(const CollisionVolume& col, const Vect& c)
	{
		#if USE_VISUALIZER
		col.DebugView(c);
		#else
		col;
		c;
		#endif
	}
};

#endif 

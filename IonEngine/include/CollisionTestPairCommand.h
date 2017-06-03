#ifndef COLLISIONTESTPAIRCOMMAND_H
#define COLLISIONTESTPAIRCOMMAND_H

#include "CollisionCommandBase.h"
#include "CollidableGroup.h"

//#include "CollisionVolumeBSphere.h"	//	remove?
//#include "CollisionVolume.h"

#include "IonMathTools.h"
#include "Visualizer.h"
#include "Color.h"

class CollisionVolumeBSphere;
class CollisionVolume;

template<typename C1, typename C2>
class CollisionTestPairCommand : public CollisionCommandBase {
private:
	typename const CollidableGroup<C1>::CollidableCollection& Collection1;
	typename const CollidableGroup<C2>::CollidableCollection& Collection2;
public:
	CollisionTestPairCommand()
		:	Collection1(CollidableGroup<C1>::GetColliderCollection()),
			Collection2(CollidableGroup<C2>::GetColliderCollection())
	{};

	~CollisionTestPairCommand() {
		DebugMsg::out("Deleteing CollisionTestPairCommand...\n");
	}

	virtual void execute() {
		//*
		//	Check CollidableGroups for AABB collision
		if (Collection1.size() > 0 && Collection2.size() > 0) {

			bool collides = IonMathTools::Intersect(CollidableGroup<C1>::GetAABB(), CollidableGroup<C2>::GetAABB());
			if (collides)
			{
				DrawVisualizer(CollidableGroup<C1>::GetAABB(), Color::Yellow);
				DrawVisualizer(CollidableGroup<C2>::GetAABB(), Color::Yellow);

				//	Check every C1 collidable Bsphere with C2 CollidableGroup AABB
				for (auto it1 = Collection1.begin(); it1 != Collection1.end(); it1++)
				{
					collides = IonMathTools::Intersect((*it1)->GetDefualtBSphere(), CollidableGroup<C2>::GetAABB());
					if (collides)
					{
						DrawVisualizer( (*it1)->GetDefualtBSphere(), Color::Orange);

						//	Check every C2 collidable Bsphere with C1 collidable Bsphere
						for (auto it2 = Collection2.begin(); it2 != Collection2.end(); it2++)
						{
							collides = IonMathTools::Intersect((*it1)->GetDefualtBSphere(), (*it2)->GetDefualtBSphere());
							if (collides)
							{
								DrawVisualizer( (*it2)->GetDefualtBSphere(), Color::Orange);

								//	Test real Collision Volume intersection
								TestCollision((*it1), (*it2));
							}
							else {
								DrawVisualizer( (*it2)->GetDefualtBSphere(), Color::DarkGray);
							}
						}

					}
					else {
						DrawVisualizer( (*it1)->GetDefualtBSphere(), Color::DarkGray);
					}
				}
			}
			else {
				DrawVisualizer( CollidableGroup<C1>::GetAABB(), Color::DarkGray);
				DrawVisualizer( CollidableGroup<C2>::GetAABB(), Color::DarkGray);
			}
		}
		//*/

	}

	template<typename Col1, typename Col2>
	void TestCollision(Col1* col1, Col2* col2) 
	{
		if (IonMathTools::Intersect(col1, col2)) {
			col1->Collision(col2);
			col2->Collision(col1);

			DrawVisualizer(col1, col2, Color::Red);
		}
		else {
			DrawVisualizer(col1, col2, Color::DarkGray);
		}
	}

	template<typename Col1, typename Col2>
	void DrawVisualizer(Col1* col1, Col2* col2, const Vect& c) 
	{
		#if USE_VISUALIZER
		Visualizer::ShowCollisionVolume(col1, c);
		Visualizer::ShowCollisionVolume(col2, c);
		#else
		col1;
		col2;
		c;
		#endif
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
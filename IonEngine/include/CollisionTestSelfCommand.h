#ifndef COLLISIONTESTSELFCOMMAND_H
#define COLLISIONTESTSELFCOMMAND_H

#include "CollisionCommandBase.h"
#include "CollidableGroup.h"

//#include "CollisionVolumeBSphere.h"	//	remove?
//#include "CollisionVolume.h"

#include "Visualizer.h"

#define USETHIS 0

template<typename C>
class CollisionTestSelfCommand : public CollisionCommandBase {
private:
	typename const CollidableGroup<C>::CollidableCollection& Collection;
public:
	CollisionTestSelfCommand()
		: Collection(CollidableGroup<C>::GetColliderCollection())
	{};

	~CollisionTestSelfCommand() {
		DebugMsg::out("Deleteing CollisionTestSelfCommand...\n");
	}

	virtual void execute() {
		//*
		//	Check every collidable Bsphere with the other collidable Bspheres
		if (Collection.size() > 0) {
			bool collides;
			//	start at begin, as long as iter isnt the end and the next iter isnt the end
			for (auto it1 = Collection.begin(); (it1 != Collection.end()) && ((++it1) != Collection.end()); it1++)
			{
				//	start at the next iter, loop till end
				for (auto it2 = std::next(it1, 1); it2 != Collection.end(); it2++)
				{
					collides = IonMathTools::Intersect( (*it1)->GetDefualtBSphere(), (*it2)->GetDefualtBSphere());
					if (collides)
					{
						DrawVisualizer( (*it1)->GetDefualtBSphere(), Color::Red);
						DrawVisualizer( (*it2)->GetDefualtBSphere(), Color::Red);

						//	Test real Collision Volume intersection
						TestCollision((*it1), (*it2));
					}
					else {
						DrawVisualizer( (*it1)->GetDefualtBSphere(), Color::DarkGray);
						DrawVisualizer( (*it2)->GetDefualtBSphere(), Color::DarkGray);
					}
				}
			}
		}
		//*/

	}

	template<typename Col>
	void TestCollision(Col* col1, Col* col2) 
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

	template<typename Col>
	void DrawVisualizer(Col* col1, Col* col2, const Vect& c)
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
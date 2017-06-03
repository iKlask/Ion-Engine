#ifndef TERRAINAREA_H
#define TERRAINAREA_H

class Terrain;
class Vect;

class TerrainArea {
private:
	int iStart;
	int iEnd;

	int Grid_Length;
	int Area_Length;
	Terrain* pTerrain;

	TerrainArea() = delete;	//prevent default constructor
public:
	class iterator
	{
	public:
		iterator(int index, TerrainArea* pTA);		//Constructor

		iterator operator++();						//prefix increment operator
		iterator operator++(int post);				//postfix increment operator
		iterator operator--();						//prefix decrement operator
		iterator operator--(int post);				//postfix decrement operator

		bool operator==(const iterator& check);		//equals operator
		bool operator!=(const iterator& check);		//not equals operator

		const Vect& GetMinCorner();
		const Vect& GetMaxCorner();
		int GetCell() { return Cell; }

	private:
		int Cell;
		TerrainArea* ptr;
	};

	iterator begin()
	{
		return iterator(iStart, this);
	}

	iterator end()
	{
		return iterator((iEnd + Grid_Length) - Area_Length, this);	//End of section is at the start of the next row...
	}


	TerrainArea(Terrain * pTerr, const Vect& pos, float radius);
	~TerrainArea();
	TerrainArea(const TerrainArea&);
	TerrainArea& operator=(const TerrainArea&);

	bool isPermitted();

};

#endif // !TERRAINAREA_H

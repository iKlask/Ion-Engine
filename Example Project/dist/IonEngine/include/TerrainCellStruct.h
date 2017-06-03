#ifndef TERRAINCELLSTRUCT_H
#define TERRAINCELLSTRUCT_H

#include "Vect.h"
#include "Align16.h"

struct CellAABB : public Align16
{
	Vect min;
	Vect max;
};


#endif // !TERRAINCELLSTRUCT_H

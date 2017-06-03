#ifndef LIGHTDATA_H
#define LIGHTDATA_H

#include "Vect.h"

struct LightData : public Align16
{
	Vect Amb;
	Vect Diff;
	Vect Spec;
};


#endif

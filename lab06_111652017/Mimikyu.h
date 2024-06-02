#ifndef __MIMIKYU_H__
#define __MIMIKYU_H__

#include "Pokemon.h"

// TODO: Implement a Mimikyu class, you can refer to Pikachu class

class Mimikyu : public Pokemon
{
public:
	Mimikyu(int hp, int attack, int defense, int specialAttack, int specialDefense, int speed);

	void description();
};

#endif // !__MIMIKYU_H__
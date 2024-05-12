#ifndef __PIKACHU_H__
#define __PIKACHU_H__

#include "Pokemon.h"

class Pikachu : public Pokemon
{
public:
	Pikachu(int hp, int attack, int defense, int specialAttack, int specialDefense, int speed);

	void description();
};

#endif // !__PIKACHU_H__
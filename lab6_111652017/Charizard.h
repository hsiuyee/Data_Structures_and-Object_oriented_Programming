#ifndef __CHARIZARD_H__
#define __CHARIZARD_H__

#include "Pokemon.h"

// TODO: Implement a Charizard class, you can refer to Pikachu class

class Charizard : public Pokemon
{
public:
	Charizard(int hp, int attack, int defense, int specialAttack, int specialDefense, int speed);

	void description();
};

#endif // !__CHARIZARD_H__
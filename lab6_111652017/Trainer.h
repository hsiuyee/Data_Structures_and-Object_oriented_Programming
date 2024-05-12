#ifndef __TRAINER_H__
#define __TRAINER_H__

#include <string>

#include "Pokemon.h"

using namespace std;

class Trainer
{
private:
	string name;
	Pokemon* pokemon;

public:
	Trainer(string name): name(name), pokemon(nullptr) {}

	void changePokemon(Pokemon* pokemon);
};

#endif // !__TRAINER_H__
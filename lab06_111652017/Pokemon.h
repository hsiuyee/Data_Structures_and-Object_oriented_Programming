#ifndef __POKEMON_H__
#define __POKEMON_H__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pokemon
{
protected:
	string nickname;

	int hp;
	int attack;
	int defense;
	int specialAttack;
	int specialDefense;
	int speed;

public:
	Pokemon(): 
		nickname(""), hp(0), attack(0), defense(0), specialAttack(0), specialDefense(0), speed(0) {}
	Pokemon(int hp, int attack, int defense, int specialAttack, int specialDefense, int speed):
		nickname(""), hp(hp), attack(attack), defense(defense), specialAttack(specialAttack), specialDefense(specialDefense), speed(speed) {}

	void setNickname(string name) { this->nickname = name; }
	string getNickname() { return nickname; }

	void info();
	virtual void description() = 0;
};

#endif // !__POKEMON_H__

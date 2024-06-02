#include "Mimikyu.h"

// TODO: Implement a Mimikyu class, you can refer to Pikachu class

Mimikyu::Mimikyu(int hp, int attack, int defense, int specialAttack, int specialDefense, int speed) :
	Pokemon(hp, attack, defense, specialAttack, specialDefense, speed)
{
	// TODO: Initialize the default nickname
	nickname = "Dummy";
}

void Mimikyu::description()
{
	// Descript this Pokemon
	cout << this->nickname << " is Mimikyu" << endl;
}
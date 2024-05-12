#include "Pikachu.h"

Pikachu::Pikachu(int hp, int attack, int defense, int specialAttack, int specialDefense, int speed) :
	Pokemon(hp, attack, defense, specialAttack, specialDefense, speed)
{
	// TODO: Initialize the default nickname
	nickname = "Dummy";
}

void Pikachu::description()
{
	// Descript this Pokemon
	cout << this->nickname << " is Pikachu" << endl;
}
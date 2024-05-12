#include "Trainer.h"
#include "Charizard.h"
#include "Pikachu.h"
#include "Mimikyu.h"



void Trainer::changePokemon(Pokemon* pokemon)
{
	// TODO: Change the current Pokemon, but only Charizard is acceptable class
	// 
	// Hint: You can use 'dynamic_cast<>()' to check whether it is the class you want

	if (Charizard* charizard = dynamic_cast<Charizard*>(pokemon))
    {
        this->pokemon = charizard;
        cout << "Trainer " << name << " changes Pokemon successfully";
    }
    else
    {
		string temp;
		if (Pikachu* charizard = dynamic_cast<Pikachu*>(pokemon))
		{
			temp = "Pikachu";
		}
		if (Mimikyu* charizard = dynamic_cast<Mimikyu*>(pokemon))
		{
			temp = "Mimikyu";
		}
        cout << "Trainer " << name << " can not use " << temp;
    }
}
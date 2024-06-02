#include <iostream>

#include "Pokemon.h"
#include "Pikachu.h"
#include "Mimikyu.h"
#include "Charizard.h"
#include "Trainer.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


using namespace std;

string convert(string input){
	string result = "";
	for (char c : input) {
        if (std::isdigit(c)) {
            result += c;
        }
    }
	return result;
}

int main() {
	// TODO: Read the data from the txt file.
	// ifstream infile("Sample_Input.txt"); 
	ifstream infile("Hidden_Input.txt"); 
	int T;
	infile >> T;
	string input, temp;
	vector<Pokemon*> classTypeList;
	getline(infile, temp, '\n');  
	while(T--){
		getline(infile, input, '\n');  
		// cout << "input: " << input << "\n";
		// // input = "Pikachu, pikachu, 142, 117, 101, 112, 112, 156";

		string className, nickname, attributes[6];
		int hp, attack, defense, specialAttack, specialDefense, speed;

		stringstream ss(input);

		getline(ss, className, ',');  
		// cout << "className: " << className << "\n";  
		ss.ignore(); 

		getline(ss, nickname, ',');     
		// cout << "nickname: " << nickname << "\n";  
		ss.ignore(); 

		for(int i = 0; i < 6; i++){
			if(i == 5){
				ss >> attributes[i];
				attributes[i] = convert(attributes[i]);
				ss >> temp;
				continue;
			}
			getline(ss, attributes[i], ',');    
			attributes[i] = convert(attributes[i]);
			// cout << "i:" << attributes[i] << "\n";
		}
		// try {
			hp = stoi(attributes[0]); 
			attack = stoi(attributes[1]); 
			defense = stoi(attributes[2]); 
			specialAttack = stoi(attributes[3]); 
			specialDefense = stoi(attributes[4]); 
			speed= stoi(attributes[5]);
		// } 
		// catch (const std::invalid_argument& e) {
		// 	std::cerr << "Invalid input: " << e.what() << '\n';
		// 	return 1; 
		// }

		// TODO: Create the Pokemon according to the input file.

	// 	//   1. Create the Pokemon.
		Pokemon* pokemon;
		
	// 	//   2. Print out the infomation.
		// cout << "input: " << input << "\n";
		// cout << "className: " << className << "\n";
		// cout << "nickname: " << nickname << "\n";
		// cout << "hp: " << hp << "\n";
		// cout << "attack: " << attack << "\n";
		// cout << "defense: " << defense << "\n"; 
		// cout << "specialAttack: " << specialAttack << "\n";
		// cout << "specialDefense: " << specialDefense << "\n";
		// cout << "speed: " << speed << "\n";
		// cout << endl;


	// 	//   3. Print out the description.
		if (className == "Pikachu")
		{
			pokemon = new Pikachu(hp, attack, defense, specialAttack, specialDefense, speed);
		}
		if (className == "Mimikyu")
		{
			pokemon = new Mimikyu(hp, attack, defense, specialAttack, specialDefense, speed);
		}
		if (className == "Charizard")
		{
			pokemon = new Charizard(hp, attack, defense, specialAttack, specialDefense, speed);
		}
		classTypeList.push_back(pokemon);

		// 
		// Example:
		// 
		// Pokemon* pikachu = new Pikachu(
		//     pikachu'hp,
		//	   pikachu'attack, 
		//	   pikachu'defense, 
		//	   pikachu'specialAttack, 
		//	   pikachu'specialDefense, 
		//	   pikachu'speed
		// );
		// pikachu->setNickname(pikachu'nickname);
		// pikachu->info();
		// pikachu->description();
		// cout << endl;

		
		pokemon->setNickname(nickname);
		pokemon->description();
		pokemon->info();
		cout << endl;
	}
		Trainer* trainer = new Trainer("Red");

		// // TODO: Change the trainer Red current Pokemon. Bear in mind, only Charizard is acceptable class!
		// // 
		// // Example:
		// // 
		// // trainer->changePokemon(pikachu);
		// // cout << endl;
	for(auto it : classTypeList){
		trainer->changePokemon(it);
		cout << endl;
	}
	return 0;
}
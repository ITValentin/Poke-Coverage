#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
std::string program, loop = " ";
std::vector<std::string> weaknesses;
const std::vector<std::string> types{ "fire", "water", "grass", "electric", "ice", "fighting", "poison", "ground", "flying", "psychic", "bug", "rock", "ghost", "dragon", "dark", "steel", "fairy" };



bool fire = false, water = false, grass = false, electric = false, ice = false, fighting = false, poison = false, ground = false, flying = false, psychic = false, bug = false, rock = false,
ghost = false, dragon = false, dark = false, steel = false, fairy = false;

bool gtg;
std::vector<std::string> team;

void userinput() {
	std::cout << "pokemon_master>>";
	std::cin >> loop;
}

void typeif(std::string type) {

	if (type == "fire") {
		grass = true;
		ice = true;
		bug = true;
		steel = true;
	}
	else if (type == "water") {
		fire = true;
		ground = true;
		rock = true;
	}
	else if (type == "grass") {
		water = true;
		ground = true;
		rock = true;
	}
	else if (type == "electric") {
		water = true;
		flying = true;
	}
	else if (type == "ice") {
		grass = true;
		ground = true;
		flying = true;
		dragon = true;
	}
	else if (type == "fighting") {
		ice = true;
		rock = true;
		dark = true;
		steel = true;
	}
	else if (type == "poison") {
		grass = true;
		fairy = true;
	}
	else if (type == "ground") {
		fire = true;
		electric = true;
		poison = true;
		rock = true;
		steel = true;
	}
	else if (type == "flying") {
		grass = true;
		fighting = true;
		bug = true;
	}
	else if (type == "psychic") {
		fighting = true;
		poison = true;
	}
	else if (type == "bug") {
		grass = true;
		psychic = true;
		dark = true;
	}
	else if (type == "rock") {
		fire = true;
		ice = true;
		flying = true;
		bug = true;
	}
	else if (type == "ghost") {
		psychic = true;
		ghost = true;
	}
	else if (type == "dragon") {
		dragon = true;
	}
	else if (type == "dark") {
		psychic = true;
		ghost = true;
	}
	else if (type == "steel") {
		ice = true;
		rock = true;
		fairy = true;
	}
	else if (type == "fairy") {
		fighting = true;
		dragon = true;
		dark = true;
	}
}

void maketypesfalse() {
	fire = false, water = false, grass = false, electric = false, ice = false, fighting = false, poison = false, ground = false, flying = false,
		psychic = false, bug = false, rock = false, ghost = false, dragon = false, dark = false, steel = false, fairy = false;
}

void weaklist() {
	if (!fire) {
		weaknesses.push_back("fire");
	}
	if (!water) {
		weaknesses.push_back("water");
	}
	if (!grass) {
		weaknesses.push_back("grass");
	}
	if (!electric) {
		weaknesses.push_back("electric");
	}
	if (!ice) {
		weaknesses.push_back("ice");
	}
	if (!fighting) {
		weaknesses.push_back("fighting");
	}
	if (!poison) {
		weaknesses.push_back("poison");
	}
	if (!ground) {
		weaknesses.push_back("ground");
	}
	if (!flying) {
		weaknesses.push_back("flying");
	}
	if (!psychic) {
		weaknesses.push_back("psychic");
	}
	if (!bug) {
		weaknesses.push_back("bug");
	}
	if (!rock) {
		weaknesses.push_back("rock");
	}
	if (!ghost) {
		weaknesses.push_back("ghost");
	}
	if (!dragon) {
		weaknesses.push_back("dragon");
	}
	if (!dark) {
		weaknesses.push_back("dark");
	}
	if (!steel) {
		weaknesses.push_back("steel");
	}
	if (!fairy) {
		weaknesses.push_back("fairy");
	}
}




int main() {

	

	while (loop != "term") {
		std::cout << "\n***Welcome to Dom's Pokemon Team Checker.***\n\n";
		loop = 1;
		maketypesfalse();
		std::cout << "Please input all type moves on your team one by one.\nRepeat types do not need to be inputted.\nInput 'done' to check your team.\n";
		std::cout << "\nExample: A pokemon with a fire, fighting, and dark type move should be inputted as follows.\npokemon_master>>fire\npokemon_master>>fighting\npokemon_master>>dark\n\n";
		while (loop != "done") {
			userinput();
			if (loop == "done") break;
			if (std::count(types.begin(), types.end(), loop)) gtg = true;
			if (gtg) team.push_back(loop);
			else std::cout << "\nUnsupported type. Please try again or input 'done' to leave.\n\n";
			gtg = false;
		}

		std::cout << "\nEvaluating the following types: ";
		for (int i = 0; i < team.size(); i++) {
			if (i == team.size() - 1) {
				std::cout << "and " << team[i] << ".\n";
			}
			else std::cout << team[i] << ", ";
		}

		for (int i = 0; i < team.size(); i++) {
			typeif(team[i]);
		}

		weaklist();
		if (weaknesses.size() == 0) std::cout << "Your team has no offensive weaknesses.\n";
		std::cout << "\nYour team is missing: ";

		for (int i = 0; i < weaknesses.size(); i++) {
			if (i == weaknesses.size() - 1) {
				std::cout << "and " << weaknesses[i] << " type coverage.\n";
			}
			else std::cout << weaknesses[i] << ", ";
		}

		std::cout << "\nTo return to startup, input 'start' else exit the console window or input any character to terminate the program.\n";
		userinput();
		if (loop == "term") exit;

	}

	return 0;
}
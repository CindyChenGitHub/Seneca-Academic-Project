/**********************************************************
// Workshop 7 - Derived Classes
// File Hero.cpp
// Date: 2018/03/18
// Student: Cindy Chen
// Description: In lab
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Hero.h"

using namespace std;
using namespace sict;

namespace sict {

	Hero::Hero() {
		hero_name[0] = '\0';
		hero_health = 0;
		hero_strength = 0;
	}

	Hero::Hero(const char name[], int health, int strength) {
		bool valid = !(name == NULL || strncmp(name, "",Max_Name) == 0 || name[0] == '\0' || health < 0 || strength < 0);
		if (valid) {
			strncpy(hero_name, name, Max_Name-1);
			hero_name[Max_Name] = '\0';
			hero_health = health;
			hero_strength = strength;
		}
		else {
			hero_name[0] = '\0';
			hero_health = 0;
			hero_strength = 0;
		}
	}

	Hero::~Hero() {
	}

	void Hero::operator-=(int attack) {
		if (attack > 0) {
			if (hero_health >= attack)	hero_health -= attack;
			else hero_health = 0;
		}
	}

	bool Hero::isAlive() const {
		return (hero_health > 0);
	}

	int Hero::attackStrength() const {
		if (hero_strength > 0) return hero_strength;
		else return 0;
	}

	void Hero::display(std::ostream& os) const {
		if (hero_name == NULL || strncmp(hero_name, "",Max_Name+1) == 0 || hero_name[0] == '\0') {
			std::cout << "No hero" << std::endl;
		}
		else {
			std::cout << hero_name;
		}
	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		hero.display(os);
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero first_ = first;
		Hero second_ = second;
		int round = 0;
		for (int i = 0; (i < Max_Rounds) && first_.isAlive() && second_.isAlive(); i++) {
			first_ -= (second_.attackStrength());
			second_ -= (first_.attackStrength());
			round++;
		}
		std::cout << "Ancient Battle! " << first << " vs " << second << " : Winner is ";
		if (first_.isAlive()) {
			std::cout << first << " in " << round << " rounds." << endl;
			return first;
		}
		else {
			std::cout << second << " in " << round << " rounds." << endl;
			return second;
		}
	}
}
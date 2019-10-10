/**********************************************************
// Workshop 7 - Derived Classes
// File SuperHero.cpp
// Date: 2018/03/20
// Student: Cindy Chen
// Description: At home
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"SuperHero.h"

using namespace std;
using namespace sict;

namespace sict {

	SuperHero::SuperHero() {
		hero_s_power = 0;
		hero_s_defend = 0;
	}

	SuperHero::SuperHero(const char name[], int health, int strength, int s_power, int s_defend) {

        bool valid = !(name == NULL || strncmp(name, "", Max_Name) == 0 || name[0] == '\0' || health < 0 || strength < 0 || s_power < 0 || s_defend < 0);
        if (valid) {
            strncpy(SuperHero::hero_name, name, Max_Name - 1);
            hero_name[Max_Name] = '\0';
            hero_health = health;
            hero_strength = strength;
            hero_s_power = s_power;
            hero_s_defend = s_defend;
        }
        else {
            hero_name[0] = '\0';
            hero_health = 0;
            hero_strength = 0;
            hero_s_power = 0;
            hero_s_defend = 0;
        }
	}

	SuperHero::~SuperHero() {
	}

	int SuperHero::attackStrength() const {
		if (Hero::attackStrength() > 0 && hero_s_power > 0) return (Hero::attackStrength() + hero_s_power);
		else return 0;
	}

	int SuperHero::defend() const{
		if (hero_s_defend > 0) return hero_s_defend;
		else return 0;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero first_ = first;
		SuperHero second_ = second;
		int round = 0;
		for (int i = 0; (i < Max_Rounds) && first_.isAlive() && second_.isAlive(); i++) {
			first_ -= ( second_.attackStrength() - first_.defend() );
			second_ -= ( first_.attackStrength() - second_.defend() );
			round++;
		}
		std::cout << "Super Fight! " << first << " vs " << second << " : Winner is ";
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



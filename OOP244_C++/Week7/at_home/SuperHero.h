/**********************************************************
// Workshop 7 - Derived Classes
// File SuperHero.h
// Date: 2018/03/20
// Student: Cindy Chen
// Description: At home
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_SUPERHEADER_H
#define SICT_SUPERHEADER_H
#include "Hero.h"
using namespace sict;

namespace sict {

	class SuperHero: public Hero {
		int hero_s_power;
		int hero_s_defend;
	public:
		SuperHero();
        SuperHero(const char name[], int health, int strength, int s_power, int s_defend);
		~SuperHero();
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif
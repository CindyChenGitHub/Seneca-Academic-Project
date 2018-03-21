/**********************************************************
// Workshop 7 - Derived Classes
// File Hero.h
// Date: 2018/03/20
// Student: Cindy Chen
// Description: At home
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_HEADER_H
#define SICT_HEADER_H
namespace sict {
	const int Max_Rounds = 100;
	const int Max_Name = 41;
	class Hero {
    protected:
		char hero_name[Max_Name];
		int hero_health;
		int hero_strength;
	public:
		Hero();
		Hero(const char name[], int health, int strength);
		~Hero();
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		void display(std::ostream& os) const;
		friend std:: ostream& operator<<(std::ostream& os, const Hero& hero);
	};
	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif // !SICT_HEADER_H


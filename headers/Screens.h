#pragma once
#include <iostream>
#include <conio.h>
#include <stdlib.h>

#include "Turn.h"

#ifndef SCREENS_H
#define SCREENS_H

template <class T, class F, class I>
class Screens {

private:

public:
	void intro();
	void settings(char* name_cur, int strs_cur, int seed_cur, int mark_cur, int turn_cur);
	void CharSpecificSet(const char *setting_name, char setting_current[]);
	void IntSpecificSet(const char* setting_name, int setting_current);
	void Menu(int num_of_t, int cap_of_t, int num_of_a, int strs, int strs_cap, int num_of_c, std::string career, int wage);
	
	template<class T, class F, class I>
	void Specialty(T text1, I text2, F text3, I text4, F text5);

	template<class T, class F, class I>
	void Specialty(T text1, I text2, F text3, I text4);
};

#endif

#pragma once
#include <iostream>
#include <conio.h>
#include "Turn.h"

class Screens {

private:

public:
	void Intro();
	void Settings(char* name_cur, int strs_cur, int seed_cur, int mark_cur, int turn_cur);
	void CharSpecificSet(const char *setting_name, char setting_current[]);
	void IntSpecificSet(const char* setting_name, int setting_current);
	
	void Menu(int num_of_t, int cap_of_t, int num_of_a, int strs, int strs_cap, int num_of_c, std::string career, int wage);
	void Specialty(const char* text1, const char* text2, const char* text3);
	void Specialty(const char* text1, const char* text2, int text3, const char* text4);
	void Specialty(const char* text1, const char* text2, int text3, const char* text4, int text5);
};
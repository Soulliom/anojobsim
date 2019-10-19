#include <iostream>
#include <conio.h>

#include "../headers/Turn.h"
#include "../headers/Screens.h"

/* Screens must include spaces as empty spaces

		Template:
		"*-----------------------------------------------------------------------------------------------------------------*\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"*----------------------------------------------------------------------------------------------------------------*\n";
*/
Turn T;

void Screens<class T, class F, class I>::Intro() {
	system("CLS");
	std::cout << "\n" <<
		"*----------------------------------------------------------------------------------------------------------------*\n"
		"                                                                                                                  \n"
		"                                             Welcome to Job Simulator                                             \n"
		"                                               Created By Soulliom                                                \n"
		"\n"
		"\n"
		"\n"
		"                       The Goal is to earn one million Marks in the least amount of turns (days)\n"                                     
		"\n"
		"\n"
		"                                  Every turn you will be able to use 2 actions.\n"
		"                            And every couple turn you will pay for different necessities,\n"
		"\n"
		"                                        *------------------------------*\n"
		"                                        |Press 'Space' the Key to Start|\n"
		"                                        *------------------------------*\n"
		"*----------------------------------------------------------------------------------------------------------------*\n";
}

template<class T, class F, class I>
void Screens<class T, class F, class I>::Settings(char *name_cur, int strs_cur, int seed_cur, int mark_cur, int turn_cur) {
	system("CLS");
	std::cout << "\n" <<
		"*--------------------------------------------------------------------------------------------------------------------*\n"
		"                                                                                                                  \n"
		"                                                   Job Simulator\n"
		"                                                     Settings\n"
		"\n"
		" 1. Name || " << name_cur << "\n"
		"\n"
		" 2. Stress Limit || " << strs_cur << "\n"
		"\n"
		" 3. Seed (Blank if Random) || " << seed_cur << "\n"
		"\n"
		" 4. Mark Goal  || " << mark_cur << "\n"
		"\n"
		" 5. Limited Turns (Blank if Unlimited) || " << turn_cur << "\n"
		"\n"
		"                                                                                           Press Enter to Continue\n"
		"*----------------------------------------------------------------------------------------------------------------*\n";
}

template<class T, class F, class I>
void Screens<class T, class F, class I>::CharSpecificSet(const char *setting_name, char setting_current[]) {
	system("CLS");
	std::cout << "\n" <<
	"*--------------------------------------------------------------------------------------------------------------------*\n"
		"\n"
		"                                                   Job Simulator\n"
		"                                                     Settings\n"
		"\n"
		<<setting_name<<"\n"
		"\n"
		<< "Current Setting: " << setting_current <<"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"                                                                                         Press Enter to go Back\n"
		"*----------------------------------------------------------------------------------------------------------------*\n";
}

template<class T, class F, class I>
void Screens<class T, class F, class I>::IntSpecificSet(const char* setting_name, int setting_current) {
	system("CLS");
	std::cout << "\n" <<
		"*----------------------------------------------------------------------------------------------------------------*\n"
		"\n"
		"                                                   Job Simulator\n"
		"                                                     Settings\n"
		"\n"
		<< setting_name << "\n"
		"\n"
		<<"Current Setting: "<< setting_current << "\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"                                                                                         Press Enter to go Back\n"
		"*----------------------------------------------------------------------------------------------------------------*\n";
}

template<class T, class F, class I>
void Screens<class T, class F, class I>::Menu(int num_of_t, int cap_of_t, int num_of_a, int strs, int strs_cap, int num_of_c, std::string career, int wage) {
	system("CLS");
	std::cout << "\n" <<
		"*----------------------------------------------------------------------------------------------------------------*\n"
		" 1. Start A New Job                                                   Turn: " << num_of_t << " / " << cap_of_t <<"\n"
		"                                                                      Actions Remaining : " << num_of_a <<"\n"
		" 2. Work\n"
		"                                                                      Stress: " << strs << " / " << strs_cap << "\n"
		" 3. Gamble                                                            Balance: " << num_of_c << "\n"
		"\n"
		" 4. Illegal Activity                                                  Wage: " << wage << "\n"
		"                                                                      Job: " << career << "\n"
		" 5. Stress Relief\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"                                                                                                 Press Esc to Quit\n"
		"*----------------------------------------------------------------------------------------------------------------*\n";
}
template<class T, class F, class I>
void Screens<class T, class F, class I>::Specialty(T text1, I text2, F text3, I text4, F text5) {
	system("CLS");
	std::cout << "\n" <<
		"*----------------------------------------------------------------------------------------------------------------*\n"
		"\n"
		<< text1 << "\n"
		"\n"
		<< text2 << " " << text3 << "\n"
		"\n"
		<< text4 << " " << text5 << "\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"*----------------------------------------------------------------------------------------------------------------*\n";
}

template<class T, class F, class I>
void Screens<class T, class F, class I>::Specialty(T text1, I text2, F text3, I text4) {
	system("CLS");
	std::cout << "\n" <<
		"*----------------------------------------------------------------------------------------------------------------*\n"
		"\n"
		<< text1 << "\n"
		"\n"
		<< text2 << " " << text3 << "\n"
		"\n"
		<< text4 << "\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"*----------------------------------------------------------------------------------------------------------------*\n";
}
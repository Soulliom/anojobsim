#include <iostream>
#include <conio.h>
#include "Screens.h"
#include "Turn.h"

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

void Screens::Intro() {
	std::cout << "\n" <<
		"*----------------------------------------------------------------------------------------------------------------*\n"
		"                                                                                                                  \n"
		"                                             Welcome to Job Simulator                                             \n"
		"                                               Created By Soulliom               **--                                 \n"
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

void Screens::Settings(char *name_cur, int strs_cur, int seed_cur, int mark_cur, int turn_cur) {
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

void Screens::CharSpecificSet(const char *setting_name, char setting_current[]) {
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

void Screens::IntSpecificSet(const char* setting_name, int setting_current) {
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

void Screens::Menu(int num_of_t, int cap_of_t, int num_of_a, int strs, int strs_cap, int num_of_c, std::string career, int wage) {
	std::cout << "\n" <<
		"*----------------------------------------------------------------------------------------------------------------*\n"
		" Turn: " << num_of_t << " / " << cap_of_t <<   "                                          Cash: " << num_of_c << "\n"
		" Actions Remaining: " << num_of_a <<                    "                                 Job: "<< career <<"\n"
		" Stress: " << strs << " / " << strs_cap <<         "                                      Wage: " << wage << "\n"						
		"\n"
		" 1. Start A New Job\n"
		"\n"
		" 2. Work\n"
		"\n"
		" 3. Gamble\n"
		"\n"
		" 4. Illegal Activity\n"
		"\n"
		" 5. Stress Relief\n"
		"\n"
		"                                                                                                 Press Esc to Quit\n"
		"*----------------------------------------------------------------------------------------------------------------*\n";
}

void Screens::Specialty(const char* text1, const char* text2, const char* text3) {
	std::cout << "\n" <<
		"*----------------------------------------------------------------------------------------------------------------*\n"
		"\n"
		<< text1  << "\n"
		"\n"
		<< text2 << "\n"
		"\n"
		<< text3 << "\n"
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

void Screens::Specialty(const char* text1, const char* text2, int text3, const char* text4) {
	std::cout << "\n" <<
		"*----------------------------------------------------------------------------------------------------------------*\n"
		"\n"
		<< text1 << "\n"
		"\n"
		<< text2 << " " << text3 << "\n"
		"\n"
		<< text4 <<"\n"
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

void Screens::Specialty(const char* text1, const char* text2, int text3, const char* text4, int text5) {
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
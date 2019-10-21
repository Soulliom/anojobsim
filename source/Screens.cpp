#include <iostream>
#include <conio.h>
#include <windows.h>

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

void Screens::Intro() {
	system("CLS");
	std::cout << "\n" <<
		"*----------------------------------------------------------------------------------------------------------------*\n"
		"                                                                                                                  \n"
		"                                             Welcome to Job Simulator                                             \n"
		"                                               Created By Soulliom                                                \n"
		"\n"
		"\n"
		"\n"
		"                       The Goal is to earn the Mark(Dollar) goal in the least amount of Turns(Days)\n"                                     
		"\n"
		"\n"
		"                                  Every turn you will be able to use 2 actions.\n"
		"                                          Everything is Randomized.\n"
		"\n"
		"                                        *------------------------------*\n"
		"                                        |Press 'Space' the Key to Start|\n"
		"                                        *------------------------------*\n"
		"*----------------------------------------------------------------------------------------------------------------*\n";
	Sleep(500);
}

void Screens::Settings(char *name_cur, int strs_cur, int seed_cur, int mark_cur, int turn_cur) {
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
	Sleep(500);
}

void Screens::CharSpecificSet(const char *setting_name, char setting_current[]) {
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
	Sleep(500);
}

void Screens::IntSpecificSet(const char* setting_name, int setting_current) {
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
	Sleep(500);
}

void Screens::Menu(int num_of_t, int cap_of_t, int num_of_a, int strs, int strs_cap, int num_of_c, std::string career, int wage) {
	system("CLS");
	std::cout << "\n" <<
		"*----------------------------------------------------------------------------------------------------------------*\n"
		" 1. Start A New Job                                                   Turn: " << num_of_t << " / " << cap_of_t <<"\n"
		"                                                                      Actions Remaining : " << num_of_a <<"\n"
		" 2. Work\n"
		"                                                                      Balance: " << num_of_c << "\n"
		" 3. Gamble                                                            Stress: " << strs << " / " << strs_cap << "\n"
		"\n"
		" 4. Illegal Activity                                                  Job: " << career << "\n"
		"                                                                      Wage: " << wage << "\n"
		" 5. Stress Relief\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"                                                                                                 Press Esc to Quit\n"
		"*----------------------------------------------------------------------------------------------------------------*\n";
	Sleep(500);
}

//Templates arent working for some reason LNK2019 
void Screens::Specialty(const char* text1, const char* text2, const char* text3) {
	system("CLS");
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
	Sleep(500);
}

void Screens::Specialty(const char* text1, const char* text2, int text3, const char* text4) {
	system("CLS");
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
	Sleep(500);
}

void Screens::Specialty(const char* text1, const char* text2, int text3, const char* text4, int text5) {
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
	Sleep(500);
}

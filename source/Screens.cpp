#include "../headers/Screens.h"

void Screens::IntroScr() {
	system("CLS");
	std::cout << "\n" <<
		"  *----------------------------------------------------------------------------------------------------------------*\n"
		"  \n"
		"                                              Welcome to Job Simulator\n"
		"                                                (Created By Soulliom)\n"
		"  \n"
		"                                              'Everything is Randomized'\n"
		"  \n"
		"  \n"                                     
		"  \n"
		"  \n"
		"  \n"
		"                                            Press 'Enter' for a tutorial\n"
		"  \n"
		"                                          *------------------------------*\n"
		"                                          |Press the 'Space' Key to Start|\n"
		"                                          *------------------------------*\n"
		"  *----------------------------------------------------------------------------------------------------------------*\n";
	Sleep(500);
}

void Screens::TutorialScr() {
	system("CLS");
	std::cout << "\n" <<
		"  *----------------------------------------------------------------------------------------------------------------*\n"
		"  \n"
		"                                               Welcome to Job Simulator\n"
		"                                                 Created By Soulliom\n"
		"  \n"
		"  - Everything is randomized. Some jobs/hobbies will be better than others.\n"
		"  \n"
		"  - The more stress you have, the more difficult things will become.\n"
		"  \n"
		"  - If you go below 0 marks, you lose the game. (If you enable a turn limit and go above that you will lose too)\n"
		"  \n"
		"  - If you go above your stress limit, a turn will be skipped.\n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  *----------------------------------------------------------------------------------------------------------------*\n";
}

void Screens::SettingsScr(int strs_cur, int seed_cur, int mark_cur, int turn_cur) {
	system("CLS");
	std::cout << "\n" <<
		"  *----------------------------------------------------------------------------------------------------------------*\n"
		"  \n"
		"                                                     Job Simulator\n"
		"                                                       Settings\n"
		"  \n"
		"   1. Stress Limit || " << strs_cur << "\n"
		"  \n"
		"   2. Seed (Blank if Random) || " << seed_cur << "\n"
		"  \n"
		"   3. Mark Goal  || " << mark_cur << "\n"
		"  \n"
		"   4. Limited Turns (Blank if Unlimited) || " << turn_cur << "\n"
		"  \n"
		"  \n"
		"  \n"
		"                                                                                             Press Enter to Continue\n"
		"  *----------------------------------------------------------------------------------------------------------------*\n";
	Sleep(500);
}

void Screens::IntSpecificSet(const char* setting_name, int setting_current) {
	system("CLS");
	std::cout << "\n" <<
		"  *----------------------------------------------------------------------------------------------------------------*\n"
		"  \n"
		"                                                     Job Simulator\n"
		"                                                       Settings\n"
		"  \n"
		"  "<< setting_name << "\n"
		"  \n"
		"  "<<"Current Setting: "<< setting_current << "\n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"                                                                                              Press Enter to go Back\n"
		"  *----------------------------------------------------------------------------------------------------------------*\n";
	Sleep(500);
}

void Screens::Menu(int num_of_t, int cap_of_t, int num_of_a, int strs, int strs_cap, int num_of_c, std::string career, int wage) {
	system("CLS");
	std::cout << "\n" <<
		"  *----------------------------------------------------------------------------------------------------------------*\n"
		"  \n"
		"   1. Start A New Job                                                   Turn: " << num_of_t << " / " << cap_of_t <<"\n"
		"                                                                        Actions Remaining : " << num_of_a <<"\n"
		"   2. Work\n"
		"                                                                        Stress: " << strs << " / " << strs_cap << "\n"
		"   3. Crime\n"
		"                                                                        Balance: " << num_of_c << "\n"
		"   4. Stress Relief                                                     Job: " << career << "\n"
		"                                                                        Wage: " << wage << "\n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"                                                                                                   Press Esc to Quit\n"
		"  *----------------------------------------------------------------------------------------------------------------*\n";
	Sleep(500);
}

//Templates arent working for some reason LNK2019 
void Screens::Specialty(const char* text1, const char* text2, const char* text3) {
	system("CLS");
	std::cout << "\n" <<
		"  *----------------------------------------------------------------------------------------------------------------*\n"
		"\n"
		"  "<< text1 <<"\n"
		"\n"
		"  "<< text2 << "\n"
		"\n"
		"  "<< text3 << "\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"  *----------------------------------------------------------------------------------------------------------------*\n";
	Sleep(500);
}

void Screens::Specialty(const char* text1, const char* text2, int text3, const char* text4) {
	system("CLS");
	std::cout << "\n" <<
		"  *----------------------------------------------------------------------------------------------------------------*\n"
		"  \n"
		"  "<< text1 << "\n"
		"  \n"
		"  "<< text2 << " " << text3 << "\n"
		"  \n"
		"  "<< text4 <<"\n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  *----------------------------------------------------------------------------------------------------------------*\n";
	Sleep(500);
}

void Screens::Specialty(const char* text1, const char* text2, int text3, const char* text4, int text5) {
	system("CLS");
	std::cout << "\n" <<
		"  *----------------------------------------------------------------------------------------------------------------*\n"
		"  \n"
		"  "<< text1 << "\n"
		"  \n"
		"  "<< text2 << " " << text3 << "\n"
		"  \n"
		"  "<< text4 << " " << text5 << "\n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  \n"
		"  *----------------------------------------------------------------------------------------------------------------*\n";
	Sleep(500);
}

#include <iostream>
#include <conio.h>
#include <windows.h>

#include "../headers/Settings.h"

void Settings::Introduction() {

	S.IntroScr();
	bool introCont = false;
	while (!introCont) {
		switch (_getch()) {
		case SPA:
			introCont = true;
			break;
		case ENT:
			S.TutorialScr();
			system("PAUSE");
			introCont = true;
			break;

		default:
			introCont = false;
			break;
		}
	}
}

/* Specific Settings */
int Settings::StrsSet() {
	while (true) {
		S.IntSpecificSet("Stress Limit, (Cannot be below 25 nor higher than 200).", T.stressCap);
		std::cin >> T.stressCap; //input for setting

		if (T.stressCap < 25) {
			std::cout << "\nStress limit cannot be below 25!\n";
			system("PAUSE");
		}
		else if (T.stressCap > 200) {
			std::cout << "\nStress limit cannot exceed 200!\n";
			system("PAUSE");
		}
		else {
			return T.stressCap;
			break;
		}
	}
}

int Settings::SeedSet() {
	S.IntSpecificSet("Game Seed, (0 for completely random)", T.seed);
	std::cin >> T.seed;
	return T.seed;
}

int Settings::MarkSet() {
	while (true) {
		S.IntSpecificSet("Mark Goal, (0 for defaulT. Cannot be below 10,000 nor higher than 1,000,000)", T.markGoal);
		std::cin >> T.markGoal;

		if (T.markGoal < 10000) {
			std::cout << "\nMark Goal cannot be below 10,000!\n";
			system("PAUSE");
		}
		else if (T.markGoal > 1000000) {
			std::cout << "\nMark Goal cannot exceed 1,000,000!\n";
			system("PAUSE");
		}
		else {
			return T.markGoal;
			break;
		}
	}
}

int Settings::TLmtSet() {
	while (true) {
		S.IntSpecificSet("Turns Limit, (0 for none. Cannot be below 15 nor higher than 500)", T.turnLimit);
		std::cin >> T.turnLimit;

		if (T.turnLimit == 0) {
			return 0;
		}
		else if (T.turnLimit < 15) {
			std::cout << "\nTurn Limit cannot be below 15!.\n";
			system("PAUSE");
		}
		else if (T.turnLimit > 500) {
			std::cout << "\nTurn Limit cannot exceed 500!.\n";
			system("PAUSE");
		}
		else {
			return T.turnLimit;
			break;
		}
	}
}
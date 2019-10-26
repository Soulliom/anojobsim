//note: if stress overexceeds loss of day little stress relief. + loss of money?

/* To Do */ 
// Illegal Actions
// Win/loss (broke)
// Other options
// Debug debug debug
// Cleaner code

#include <iostream>
#include <conio.h>
#include <string>
#include <random>
#include <cstring>
#include <stdlib.h>
#include <windows.h>

#include "../headers/Turn.h"
#include "../headers/Screens.h"

/* Preproccessor Keys */
#define ONE 49
#define TWO 50
#define THR 51
#define FOR 52
#define FIV 53
#define SPA 32
#define ESC 27
#define ENT 13 

/* Variables */
bool gameOver = false;
bool win = false;

int main() {
	
	//Init Classes
	Turn T;
	Screens S;

	//Intro
	S.Intro();
	bool introCont = false;
	while (!introCont) {
		switch (_getch()) {
		case SPA:
			introCont = true;
			break;
		case ENT:
			S.Tutorial();
			system("PAUSE");
			introCont = true;
			break;

		default:
			introCont = false;
			break;
		}
	}

	//Settings
	bool exit = false;
	while (!exit) { 
		S.Settings(T.charName, T.stressCap, T.seed, T.markGoal, T.turnLimit); //Run settings screen
		switch (_getch()) {
			case ONE: //Name setting
				while (true) {
					S.CharSpecificSet("Character Name, (Limit is 20 Characters).", T.charName); 
					std::cin >> T.charName; //input for setting

					if (strlen(T.charName) > 20) {
						std::cout << "\nName is too long! Try again!\n";
						system("PAUSE");
					}
					else {
						break;
					}
				}
				break;

			case TWO: //Stress setting
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
						break;
					}
				}
				break;

			case THR: //Seed setting
				S.IntSpecificSet("Game Seed, (0 for completely random)", T.seed);
				std::cin >> T.seed;
				break;

			case FOR: //Mark setting
				while (true) {
					S.IntSpecificSet("Mark Goal, (0 for default. Cannot be below 10,000 nor higher than 1,000,000,000)", T.markGoal);
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
						break;
					}
				}
				break;

			case FIV: //Limit on Turns setting
				while (true) {
					S.IntSpecificSet("Turns Limit, (0 for none. Cannot be below 15 nor higher than 500)", T.turnLimit);
					std::cin >> T.turnLimit;
					
					if (T.turnLimit == 0) {
						//...Turn off turn limit
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
						break;
					}
				}
				break;

			case ENT: //Start game / end settings 
				T.InitSeed();
				exit = true;
				break;
		}
	}

	//Game
	while (!gameOver) {

		S.Menu(T.numOfTurns, T.turnLimit, T.numOfActions, T.stress, T.stressCap, T.amOfMarks, T.career, T.wage);
		switch (_getch()) {
		case ONE:
			T.Job();
			break;

		case TWO:
			T.Work();
			break;

		case THR:
			//Illegal (success: more stress + money, lose: stress + loss of turn)
			//T.Illegal
			break;

		case FOR:
			//Stress Relief
			T.StrsRelief();
			break;

		case ESC:
			return 0;
			break;
		
		default:
			continue;
			break;

		}
		gameOver = T.CheckTurn(gameOver);	
	}
}
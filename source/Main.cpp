//note: if stress overexceeds loss of day little stress relief

/* To Do */ 
// Work Func
// Variables
// Mechanics
// Debug

#include <iostream>
#include <conio.h>
#include <string>
#include <random>
#include <cstring>

#include "../headers/Turn.h"
#include "../headers/Screens.h"

/* Preproccessor Keystoke Buttons */
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

/* Function Definitions */
void TurnLoss();
void MarkLoss();
void Win();

int main() {
	
	//Init Classes
	Turn T;
	Screens S;

	//Intro
	S.Intro();
	while(true){

		//Pause until space key is hit
		if (_getch() == SPA) {
			system("CLS");
			break;
		}
	}

	//Settings
	bool exit = false;
	while (!exit) { 
		system("CLS");
		S.Settings(T.charName, T.stressCap, T.seed, T.markGoal, T.turnLimit); //Run settings screen
		switch (_getch()) {
			case ONE: //Name setting
				while (true) {
					system("CLS");
					S.CharSpecificSet("Character Name, (Limit is 20 Characters)", T.charName); 
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
					system("CLS");
					S.IntSpecificSet("Stress Limit, (Cannot be below 25 nor higher than 200)", T.stressCap);
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
				system("CLS");
				S.IntSpecificSet("Game Seed, (0 for completely random)", T.seed);
				std::cin >> T.seed;
				break;

			case FOR: //Mark setting
				while (true) {
					system("CLS");
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
					system("CLS");
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
				system("CLS");
				T.InitSeed();
				exit = true;
				break;
		}
	}

	//Game
	while (!gameOver) {
		system("CLS");
		S.Menu(T.numOfTurns, T.turnLimit,T.numOfActions, T.stress, T.stressCap, T.amOfCash, T.career, T.wage);
		switch (_getch()) {
			case ONE:
				//Get a Job (based on amount of cash earning to find/get new job, select name, rand # of promotions, rand promotion benefit, rand base earnings)
				T.Job();
				break;
			case TWO:
				//Work (good day: stress relief + money, okay day: money, bad day, stress + money)
				//T.Work();
				break;
			case THR:
				//Gamble (win: stress relief + money, lose: stress + loss of money)
				//T.Gamble();
				break;
			case FOR:
				//Illegal (success: more stress + money, lose: stress + loss of turn)
				//T.Illegal
				break;
			case FIV:
				//Stress Relief
				//T.StrsRelief
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

	//Decide Whether Mark Loss, Turn Loss, or Win

	if (T.amOfCash < 0) {
		MarkLoss();
	}
	else if (T.numOfTurns >= T.turnLimit) {
		TurnLoss();
	}
	else {
		Win();
	}
}

void TurnLoss() {
	std::cout << "\n\nYou lost due to a lack of turns. Better Luck Next time!\n\n\n\n\n\n\n\n\n\n\n\n";
}

void MarkLoss() {
	std::cout << "\n\nYou lost due to a debt in marks. Better Luck Next time!\n\n\n\n\n\n\n\n\n\n\n\n";
}

void Win() {
	std::cout << "\n\nCongrats! You won!\n\n\n\n\n\n\n\n\n\n\n\n";
}
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
bool game_over = false;
bool win = false;

/* Function Definitions */
void TurnLoss();
void MarkLoss();
void Win();

//Init Classes
Turn T;
Screens S;

int main() {
	
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
		S.Settings(T.char_name, T.stress_cap, T.seed, T.mark_goal, T.turn_limit); //Run settings screen
		switch (_getch()) {
			case ONE: //Name setting
				while (true) {
					system("CLS");
					S.CharSpecificSet("Character Name, (Limit is 20 Characters)", T.char_name); 
					std::cin >> T.char_name; //input for setting

					if (strlen(T.char_name) > 20) {
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
					S.IntSpecificSet("Stress Limit, (Cannot be below 25 nor higher than 200)", T.stress_cap);
					std::cin >> T.stress_cap; //input for setting

					if (T.stress_cap < 25) {
						std::cout << "\nStress limit cannot be below 25!\n";
						system("PAUSE");
					}
					else if (T.stress_cap > 200) {
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
					S.IntSpecificSet("Mark Goal, (0 for default. Cannot be below 10,000 nor higher than 1,000,000,000)", T.mark_goal);
					std::cin >> T.mark_goal;

					if (T.mark_goal < 10000) {
						std::cout << "\nMark Goal cannot be below 10,000!\n";
						system("PAUSE");
					}
					else if (T.mark_goal > 1000000) {
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
					S.IntSpecificSet("Turns Limit, (0 for none. Cannot be below 15 nor higher than 500)", T.turn_limit);
					std::cin >> T.turn_limit;
					
					if (T.turn_limit == 0) {
						//...Turn off turn limit
					}
					else if (T.turn_limit < 15) {
						std::cout << "\nTurn Limit cannot be below 15!.\n";
						system("PAUSE");
					}
					else if (T.turn_limit > 500) {
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
	while (!game_over) {
		system("CLS");
		S.Menu(T.numOfTurns, T.turn_limit,T.numOfActions, T.stress, T.stress_cap, T.amOfCash, T.career, T.wage);
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
		game_over = T.CheckTurn(game_over);
	}

	//Decide Whether Mark Loss, Turn Loss, or Win

	if (T.amOfCash < 0) {
		MarkLoss();
	}
	else if (T.numOfTurns >= T.turn_limit) {
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
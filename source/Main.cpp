//note: if stress overexceeds loss of day little stress relief. + loss of money?

/* To Do */
// Gain stress if no job
// Illegal Actions -- tax evasion> skip next payment/lose money
//^, Drug use> lose tons of stress (50% || 75% of current stress)/ gain stress + lose a turn 
// After payment / gain stress & if no job gain more stress
// If not active in job cancel job and gain stress
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
#include "../headers/Settings.h"

/* Preproccessor Keys */
#define ONE 49
#define TWO 50
#define THR 51
#define FOR 52
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
	Settings Set;

	//Intro
	Set.Introduction();

	//Settings
	bool exit = false;
	while (!exit) { 
		S.SettingsScr(T.stressCap, T.seed, T.markGoal, T.turnLimit); //Run settings screen
		switch (_getch()) {

			case ONE: //Stress setting
				T.stressCap = Set.StrsSet();
				break;

			case TWO: //Seed setting
				T.seed = Set.SeedSet();
				break;

			case THR: //Mark setting
				T.markGoal = Set.MarkSet();
				break;

			case FOR: //Limit on Turns setting
				T.turnLimit = Set.TLmtSet();
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
			//Crime ((generally) success: more stress + money, lose: stress + loss of turn if job, loss of money if no job)
			T.Crime();
			break;

		case FOR:
			T.StrsRelief();
			break;

		case ESC:
			//S.Speciality();
			return 0;
			break;
		
		default:
			continue;
			break;

		}
		gameOver = T.CheckTurn(gameOver);	
	}
}
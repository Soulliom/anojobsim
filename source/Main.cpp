/*
Game created by Soulliom (George) 

Just supposed to be a little fun project I made, I enjoy rogue-likes and I was curious if I could make a somewhat decently sized project with C++
Although Im not perfect. I am happy I was able to finish this project without giving up on it :). Reccomendations and comments are a pleasure, please
contact me thru github or whatever (Soulliom) and tell me how you feel about this. Everything is randomized and alot of things are customizable.

*/

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

bool esc = false;

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
	while (!T.gameOver) {

		S.Menu(T.numOfTurns, T.turnLimit, T.numOfActions, T.stress, T.stressCap, T.balance, T.career, T.wage); //Run game screen
		switch (_getch()) {
<<<<<<< HEAD

		case ONE: //Job option
=======
				
		case ONE:
>>>>>>> 94d1a09cd8d3072bf0b1ccc6948d2a79fc2c6502
			T.Job();
			break;

		case TWO: //Work option
			T.Work();
			break;

		case THR: //Crime option
			T.Crime();
			break;

		case FOR: //Stress Relief/Hobby option
			T.StrsRelief();
			break;

		case ESC: //Exit Game
			while (!esc) {
				S.Specialty(" Are you sure you'd like to exit the game?", " 1. No", " 2. Yes");

				switch (_getch()) {
				case ONE: //NO
					esc = true;
					break;

				case TWO: //YES
					S.Specialty(" Thanks for playing!", "", "");
					return 0;
					break;

				default:
					continue;
					break;
				}
			}
			esc = false;

		default:
			continue;
			break;
		}
		//Check turn function finds if any win/loss conditions are met or if other functions must be called to limit stress or add payments
		T.gameOver = T.CheckTurn(T.gameOver);	
	}
}

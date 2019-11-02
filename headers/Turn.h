/*
This class contains all the ingame funcitons and variables
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <istream>
#include <time.h>
#include <string>
#include <windows.h>

#ifndef TURN_H
#define TURN_H

#include "Screens.h"

/* Preproccessor Keystoke Buttons */
#define ONE 49
#define TWO 50
#define THR 51

class Turn {

private:
	Screens Sc;

	// Job
	bool jobBool = false;
	int randNumOfJobFound = 0; //Jobs Signed for 
	int actsUntilProm = 0; //Random actions until next promotion
	int randNumOfProm = 0; //Random number of promotions
	int randProm = 0; //Random mark promotion
	int daysUntilFired = 0; //Days fired after not working
	int promCount = 0;
	int randJobMood = 0;

	//Crime
	int randSuccess = 0;
	bool taxEvasion = false;

	//Hobby
	int hobbyStressR = 0;
	bool isHobby = false;
	std::string sHobby = "No_Hobby_Yet";

	//General
	int rando = 0; //rand variable
	int payment = 0; 

public:

	//Ingame
	int numOfTurns = 1; //Turns
	int numOfActions = 2; //Actions in a turn
	int wage = 0; //Job wage
	int balance = 5000; //Starting cash 5000
	int randStress = 0;
	int stress = 0; //Current stress
	std::string career = "No_Job_Yet"; 

	//Game
	bool gameOver = false; //To see

	//Settings
	int turnLimit = 0;
	int seed = 0;
	long long markGoal = 100000; //default 100,000
	int stressCap = 100;

	//Functions
	void InitSeed();
	bool CheckTurn(bool check_over);
	void Job();
	void Work();
	void Crime();
	void StrsRelief();
	void StrsLimt();
};

#endif

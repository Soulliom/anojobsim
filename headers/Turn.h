#pragma once
#include <iostream>
#include <conio.h>
#include <stdlib.h>

/* Preproccessor Keystoke Buttons */
#define ONE 49
#define TWO 50

class Turn {

private:
	// Job
	bool jobBool = false;
	int randNumOfJobFound = 0; //Jobs Signed for 
	int randWage = 0; //Random wage
	int actsUntilProm = 0;
	int randNumOfProm = 0; //Random number of promotions
	int randProm = 0; //Random mark promotion
	int daysUntilFired = 0; //Days fired after not working
	int promCount = 0;
	int randJobMood = 0;

	//Hobby
	int hobbyStressR = 0;
	bool isHobby = false;
	std::string sHobby = "No Hobby Yet";

	//General
	int rando = 0; //rand variable

public:

	//Ingame
	int numOfTurns = 1;
	int numOfActions = 2;
	int amOfMarks = 1000;
	int randStress = 0;
	int stress = 0;
	std::string career = "Start a new Job";

	//Settings
	char charName[20] = "You";
	int turnLimit = 0;
	int seed = 0;
	long long markGoal = 1000000000;
	int stressCap = 100;

	//Functions
	void InitSeed();
	bool CheckTurn(bool check_over);
	void Job();
	void Work();
	void StrsRelief();

	//Job
	int wage = 0;
};
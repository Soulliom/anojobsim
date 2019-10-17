#pragma once
#include <iostream>
#include <conio.h>

class Turn {

private:
	// Job
	bool jobBool = false;
	int jobs; //Jobs available
	int randNumOfJobFound; //Jobs Signed for 
	int randWage; //Random wage
	int actsUntilProm;
	int randNumOfProm; //Random number of promotions
	int randProm; //Random mark promotion
	int daysUntilFired; //Days fired after not working
	int promCount;
	int randJobMood;

public:

	//Easter Egg
	int countEE = 0;

	//Ingame
	int numOfTurns = 1;
	int numOfActions = 2;
	int amOfMarks = 1000;
	int randStress;
	int stress = 0;
	std::string career = "Start a new Job";

	//Settings
	char charName[20] = "You";
	int turnLimit = 0;
	int seed = 0;
	long long markGoal = 1000000000;
	int stressCap = 100;

	//Functions
	void EE();
	void InitSeed();
	bool CheckTurn(bool check_over);
	void Job();
	void Work();

	//Job
	int wage = 0;
};
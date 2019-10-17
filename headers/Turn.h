#pragma once
#include <iostream>
#include <conio.h>

class Turn {

private:

public:
	//Ingame
	int numOfTurns = 1;
	int numOfActions = 2;
	int amOfCash = 1000;
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
	void InitSeed();
	bool CheckTurn(bool check_over);
	void Job();
	void Work();

	//Job
	int jobs;
	int randNumOfJobFound;
	int randNumOfProm;
	int randWage;
	int wage = 0;
	int randPromPerc;
	int daysUntilFire;

};
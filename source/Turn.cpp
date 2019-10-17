#include <iostream>
#include <istream>
#include <conio.h>
#include <time.h>
#include <string>

#include "../headers/Turn.h"
#include "../headers/Screens.h"

Screens S;

bool Turn::CheckTurn(bool check_over) {
	numOfActions--;
	if (numOfActions <= 0) {
		numOfTurns++;
		numOfActions = 2;
	}

	//Win & Loss Conditions
	if (numOfTurns == turn_limit) {
		return true;
	}

	else if (amOfCash < 0) {
		return true;
	}

	else if (amOfCash >= mark_goal) {
		return true;
	}

	else {
		return false;
	}
}

void Turn::InitSeed() {
	if (seed == 0) {
		srand(time(NULL));
	}
	else {
		srand(seed);
	}
}

//Job Option
void Turn::Job() {
	bool err = false;
	while (!err){
		system("CLS");
		S.Specialty("Please type in your perferred Job", "(Job title should be shorter than 40 characters)", "");
		system("PAUSE");

		std::getline(std::cin,career);

		if (career.size() > 40) {
			std::cout << "I said shorter than 40 characters.";
			system("PAUSE");
			continue;
		}
		err = true;
	}

	//Init jobs
	jobs = rand() % 10 + 1;
	randNumOfJobFound = rand() % jobs + 1;
	if (randNumOfJobFound > jobs / 2) {
		system("CLS");
		//Init Wage
		randWage = rand() % 200 + 800; //Base wage
		randNumOfProm = rand() % jobs + 1; //amount of promotions
		randPromPerc = rand() % 10 + 2; //this number will be divided by 10
		wage = randWage;

		//Stress
		randStress = rand() % 10;
		stress -= randStress;
		if (stress < 0) {
			stress = 0;
		}

		S.Specialty("Congrats! You found a Job!", "Your starting wage is:", wage, "Your stress is reduced by:", randStress);
		system("PAUSE");
	}
	else {
		randStress = rand() % 14 + 1; //add stress

		system("CLS");
		S.Specialty("Seems like you were not lucky enough to find a job.", "Your stress has been increased by:",randStress,"");

		//Reset job stats and add stress
		career = "Start a new Job";
		wage = 0;
		stress += randStress;

		system("PAUSE");
	}
}

// Work Option
void Turn::Work() {

}
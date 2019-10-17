#include <iostream>
#include <istream>
#include <conio.h>
#include <time.h>
#include <string>

#include "../headers/Turn.h"
#include "../headers/Screens.h"

#define TWO 50
#define ESC 27

Screens S;

bool Turn::CheckTurn(bool check_over) {
	numOfActions--;
	if (numOfActions <= 0) {
		numOfTurns++;
		numOfActions = 2;
	}

	//Win & Loss Conditions
	if (numOfTurns == turnLimit) {
		return true;
	}

	else if (amOfMarks < 0) {
		return true;
	}

	else if (amOfMarks >= markGoal) {
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
		S.Specialty("Please type in your perferred Job", "(Job title should be shorter than 40 characters)", "");
		_getch();

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
		//Init Wage
		randWage = rand() % 1200 + 400; //Base wage
		randNumOfProm = rand() % jobs + 2 / 2 + 1; //amount of promotions
		randProm = rand() % 450 + 50; //mark promotion
		actsUntilProm = rand() % 10 + 5; //how many acts until a promotion
		wage = randWage;
		jobBool = true;

		//Stress
		randStress = rand() % 10; // Stress v
		stress -= randStress;

		S.Specialty("Congrats! You found a Job!", "Your starting wage is:", wage, "Your stress is reduced by:", randStress);
		system("PAUSE");
	}
	else { //fail to find job
		randStress = rand() % 14 + 1; //add stress
		stress += randStress;

		S.Specialty("Seems like you were not lucky enough to find a job.", "Your stress has been increased by:",randStress,"");

		//Reset job stats and add stress
		career = "Start a new Job";
		wage = 0;

		system("PAUSE");
	}
}

// Work Option
void Turn::Work() {
	if (jobBool) {
		amOfMarks += wage; //get paid

		//Stress
		randJobMood = rand() % 10;
		if (randJobMood < 3) {
			randStress = rand() % 4 + 1;
			stress -= randStress;

			S.Specialty("You work for the day! I had a great day today!", "Your balance is increased by: ", wage, "Your stress is reduced by: ", randStress);
			system("PAUSE");
		}
		else {
			randStress = rand() % 15 + 1;
			stress += randStress;
			S.Specialty("You work, although you had a pretty bad day.", "Your balance is increased by: ", wage, "Your stress is increased by: ", randStress);
			system("PAUSE");
		}

		//Promotions
		if (++promCount == actsUntilProm) {
			if (randNumOfProm <= 0) { //if no more promotions left
				S.Specialty("This job isn't willing to give you anymore promotions", "", "");
				system("PAUSE");
			}
			else if (randNumOfProm > 0) { //if promotions left
				randNumOfProm -= 1; //reduce num of promotions
				actsUntilProm = rand() % 10 + 5;
				promCount = 0;
				wage += randProm; //increase working wage
				S.Specialty("You got promoted!", "You now will earn an extra: ", randProm, "");
				system("PAUSE");
			}
		}
	}

	else { //dont have a job
		S.Specialty("You don't have a job.", "You walk around the city aimlessly.", "People passing by notice you.");
		stress += 25;
		system("PAUSE");

		if (++countEE == 5) { //Easter Egg
			S.Specialty("Someone is... watching", "One adolescent in particular stares at you with disgust", "You walk home cautiously today... I don't want to be bothered");
			system("PAUSE");
		}
	}
}

void Turn::EE() {
	if (countEE == 5) {
		S.Specialty("There is no more.", "You are bound to your destiny.", "Farewell.");
		_getch();
	}
}
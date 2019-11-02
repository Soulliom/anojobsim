#include "../headers/Turn.h"

bool Turn::CheckTurn(bool check_over) {

	//Turn Check
	numOfActions--;
	if (numOfActions <= 0) {
		numOfActions = 2;
		numOfTurns++;

		//Payment check
		if (wage != 0) {
			if (taxEvasion) {
				taxEvasion = false;

				Sc.Specialty(" You don't owe anything this turn.", " (Tax Evasion)", "");
				system("PAUSE");
			}

			else {
				payment = rand() % (wage)+(wage / 2) * (1 + stress / stressCap);
				balance -= payment;

				Sc.Specialty(" Payments are due.", " You pay: ", payment, "");
				system("PAUSE");
			}
		}
	}
	//Stress Check
	if (stress < 0) {
		stress = 0;
	}
	if (stress >= stressCap) {
		StrsLimt();
	}

	//Win & Loss Conditions
	if (numOfTurns == turnLimit) {
		//Loss by lack of turns
		Sc.Specialty(" You lost the game due to a lack of turns!", " Thank you for playing!", "");
		system("PAUSE");
		return true;
	}

	else if (balance < 0) {
		//Loss by lack of marks
		Sc.Specialty(" You lost the game due to a lack of funds!", " Thank you for playing!", "");
		system("PAUSE");
		return true;
	}

	else if (balance >= markGoal) {
		//Win by reaching goal
		Sc.Specialty(" You won the game!", " Thank you for playing!", "");
		system("PAUSE");
		return true;
	}

	else {
		//Continue game
		return false;
	}
}

//Initiate seed
void Turn::InitSeed() {
	//completely randomized
	if (seed == 0) {
		srand(time(NULL));
	}
	//set seed
	else {
		srand(seed);
	}
}

//Job Option
void Turn::Job() {
	bool err = true;
	while (err){
		Sc.Specialty(" Please type in your perferred Job.", " (Job title should be shorter than 40 characters).", " (Use underscores as spaces)");

		std::cin >> career;

		if (career.size() > 40) {
			std::cout << "Job Title is too long! Try again!\n";
			system("PAUSE");
			continue;
		}
		err = false;
	}

	//Init jobs
	rando = rand() % 10 + 1;
	randNumOfJobFound = rand() % rando + 1;
	if (randNumOfJobFound >= (rando / 2)) {
		//Init Wage
		wage = rand() % 500 + 500; //Base wage
		randNumOfProm = rand() % rando + 2 / 2 + 1; //amount of promotions
		actsUntilProm = rand() % 5 + 5; //how many acts until a promotion
		jobBool = true;

		//Stress
		randStress = rand() % 10; // Stress v
		stress -= randStress;

		Sc.Specialty(" Congrats! You found a Job!", " Your starting wage is:", wage, " Your stress is reduced by:", randStress);
		system("PAUSE");
	}
	else { //fail to find job
		randStress = rand() % 10 + 5; //add stress
		stress += randStress;

		Sc.Specialty(" Seems like you were not lucky enough to find a job.", " Your stress has been increased by:",randStress,"");

		//Reset job stats and add stress
		career = "No_Job_Yet";
		wage = 0;

		system("PAUSE");
	}
}

// Work Option
void Turn::Work() {
	if (jobBool) {
		balance += wage; //get paid

		//Job stress
		randJobMood = rand() % 10;
		if (randJobMood < 3) {
			randStress = rand() % 4 + 1;
			stress -= randStress;

			Sc.Specialty(" You work for the day! I had a great day today!", " Your balance is increased by: ", wage, "Your stress is reduced by: ", randStress);
			system("PAUSE");
		}
		else {
			randStress =(rand() % 10 + stressCap/8) * (1 + stress/stressCap);
			stress += randStress;
			Sc.Specialty(" You work, although you had a pretty bad day.", " Your balance is increased by: ", wage, "Your stress is increased by: ", randStress);
			system("PAUSE");
		}

		//Promotions counter/init
		if (++promCount == actsUntilProm) {
			if (randNumOfProm <= 0) { //if no more promotions left
				Sc.Specialty(" This job isn't willing to give you anymore promotionSc.", "", "");
				system("PAUSE");
			}
			else if (randNumOfProm > 0) { //if promotions left
				randNumOfProm -= 1; //reduce num of promotions
				randProm = rand() % 800 + 200; //reset promotion earning
				actsUntilProm = rand() % 5 + 5; //reset acts until promotion
				promCount = 0; //reset promotion count
				wage += randProm; //increase working wage

				Sc.Specialty(" You got promoted!", " You now will earn an extra: ", randProm, "");
				system("PAUSE");
			}
		}
	}

	else { //dont have a job
		Sc.Specialty(" You don't have a job.", " You walk around the city aimlessly.", " Your stress is increased by: 10");
		system("PAUSE");

		stress += 10;
	}
}

//Crime function, Robbing(gives money/loses money), Evasion(skip next payment/skip next action), Drug(reduce major stress/payment)
void Turn::Crime() {
	Sc.Specialty(" 1. Rob a Store", " 2. Tax Evasion", " 3. Drug Use");
	bool err = true;
	while (err) {
		switch (_getch()) {
		case ONE:
			//Rob a store
			randSuccess = rand() % 9 + 1;

			if (randSuccess > 6) { //If successful
				rando = rand() % 1500 + 500;
				balance += rando;

				Sc.Specialty(" You successfully robbed a store", " Your balance is increased by: ", rando, "");
				system("PAUSE");
				err = false;
			}
			else { //If not successful
				rando = rand() % (1500 + 500) * (1 + (stress / stressCap));
				randStress = rand() % (stressCap / 4) + 1;
				balance -= rando;

				Sc.Specialty(" You failed to rob a store", " Your balance is decreased by: ", rando, " Your stress is increased by: ", randStress);
				system("PAUSE");
				err = false;
			}
			break;

		case TWO:
			//Tax Evasion
			randSuccess = rand() % 9 + 1;

			if (randSuccess > 6) {
				taxEvasion = true;

				Sc.Specialty(" You successfully commited tax evasion.", " Your next payment will be skipped", "");
				system("PAUSE");
				err = false;
			}
			else if(randSuccess > 3){
				Sc.Specialty(" You failed to commit tax evasion", " Fortunately you were not caught.", "");
				system("PAUSE");
				err = false;
			}
			else {
				Sc.Specialty(" You failded to commit tax evasion", " Unfortunately you were caught, you skip an extra action.", "");
				system("PAUSE");

				CheckTurn(gameOver);
				err = false;
			}
			break;

		case THR:
			//Drug use
			int temptype = 0;
			randSuccess = rand() % 9 + 1;

			// This section finds the amount of stress decreased
			if (randSuccess > 5) {
				rando = stressCap / 5;
				stress -= rando;
				temptype = randSuccess;

				Sc.Specialty(" You do some Mary Jane.", " Your stress is decreased by: ", rando, "");
				system("PAUSE");
			}
			else if (randSuccess > 2) {
				rando = stressCap / 4;
				stress -= rando;
				temptype = randSuccess;

				Sc.Specialty(" You do some Crack Cocaine", " Your stress is decreased by: ", rando, "");
				system("PAUSE");
			}
			else {
				rando = stressCap / 2;
				stress -= rando;
				temptype = randSuccess;

				Sc.Specialty(" You do some Crystal Methamphetamine", " Your stress is decreased by: ", rando, "");
				system("PAUSE");
			}

			//This section randomizes if the play will be fined or not
			randSuccess = rand() % 9 + 1;

			if (randSuccess > 5) {
				Sc.Specialty(" Your drug use goes undetected.", "", "");
				system("PAUSE");

				err = false;
			}
			else {
				rando = balance / (temptype * 10);
				balance -= rando;

				Sc.Specialty(" Your drug use is detected by the local police.", " Your balance is decreased by: ", rando, "");
				system("PAUSE");

				err = false;
			}
			break;
		}
	}
}

//Hobby Function
void Turn::StrsRelief() {
	//This combines the char* of the hobby and turns it into a string while combining it with menu-friendly strings
	std::string opHob = " 2. ";
	std::string youHob = " You ";
	
	opHob += sHobby;
	const char* tempOpHob = opHob.c_str();

	youHob += sHobby;
	const char* tempYouHob = youHob.c_str();

	//Hobby menu
	Sc.Specialty(" You decide to take your mind off things for a while.", " 1. Start a new Hobby", tempOpHob);

	bool err = true;
	while (true) {
		switch (_getch()) {
		//Create new hobby
		case ONE:
			while (err) {
				Sc.Specialty(" What would you like to do as a hobby?", " (Hobby should be shorter than 20 characters).", " (Use underscores as spaces)");

				std::cin >> sHobby;

				if (sHobby.size() > 20) {
					std::cout << "Hobby name is too long! Try again!\n";
					system("PAUSE");
					continue;
				}
				isHobby = true;
				err = false;
			}
			rando = rand() % 5 + 5;
			hobbyStressR = rand() % (stressCap / rando) + 5;
			break;

		//Continue old hobby
		case TWO:
			if (!isHobby) {
				Sc.Specialty(" You dont have a hobby, Please try starting one first","","");
				system("PAUSE");
				StrsRelief();
				break;
			}
			randStress = (rand() % hobbyStressR + hobbyStressR / 1.25) * (1 + (stress / stressCap));
			stress -= randStress;

			Sc.Specialty(tempYouHob, " Your stress is decreased by: ", randStress, "");
			system("PAUSE");
			break;

		default:
			continue;
			break;
		}
		break;
	}
}

//Function checks if stress has exceeded stressCap and delievers a punishment
void Turn::StrsLimt() {
	if (stress >= stressCap) {
		stress = stressCap;
	}
	randStress = stressCap / 4;
	stress -= randStress;

	Sc.Specialty(" You've gone over your stress limit, an action is skipped.", " Your stress is decreased by: ", randStress, "");

	gameOver = CheckTurn(gameOver);
	system("PAUSE");
}
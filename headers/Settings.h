/*
This class contains all the different types of customizable settings used in the game
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>

#ifndef SETTING_H
#define SETTING_H

#include "Screens.h"
#include "Turn.h"

/* Preproccessor Keys */
#define ONE 49
#define TWO 50
#define THR 51
#define FOR 52
#define SPA 32
#define ESC 27
#define ENT 13 

class Settings {
private:
	Screens S;
	Turn T;

public:
	void Introduction();

	int StrsSet();
	int SeedSet();
	int MarkSet();
	int TLmtSet();
};

#endif
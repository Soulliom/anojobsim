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
#define FIV 53
#define SPA 32
#define ESC 27
#define ENT 13 

class Settings {
public:
	void Introduction();

	void NameSet();
	void StrsSet();
	void SeedSet();
	void MarkSet();
	void TLmtSet();
};

#endif
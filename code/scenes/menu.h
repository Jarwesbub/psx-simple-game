#include "../constants.h"
#include <stdio.h>

Image pressStart;

int menu() {
	printf("MENU OPEN \n");
	short isMenuActive = 1;
	int coolDown = 0;
	menuInitialize();

	while(isMenuActive) {
		if(coolDown < 60) {
			coolDown++;
		}
		else {
			isMenuActive = readPADstartInput();
		}
		clearDisplay();
		menuDraw();
		display();
	}
	clearDisplay();
	clearVRAM();
    return 1;
}

void menuInitialize() {
	initializeScreen();
	initializeDebugFont();
	setBackgroundColor(createColor(0, 0, 0));
	initializePad();

	pressStart = createImage(img_press_start, 120, 100);
}

int readPADstartInput() {
	padUpdate();
	if(padCheck(PADstart) && !padCheckPressed(PADselect)) {
		return 0;
	}
	return 1;
}

void menuDraw() {
	FntPrint("The Game");
	drawImage(pressStart);
}
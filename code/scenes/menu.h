#include "../constants.h"
#include <stdio.h>

Image menuPressStart;

int menu() {
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
	}    return 1;
}

void menuInitialize() {
	initializeScreen();
	initializeDebugFont(120, 50); //120, 50
	setBackgroundColor(createColor(0, 0, 0));
	initializePad();

	menuPressStart = createImage(img_press_start, 100, 100);
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
	drawImage(menuPressStart);
}
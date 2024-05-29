#include "../constants.h"

int gameover() {
	short waitTime = 180;
	endInitialize();

	while(waitTime) {
		clearDisplay();
		FntPrint("Game Over");
		display();
		waitTime--;
	}

	clearDisplay();
	clearVRAM();
    return 0;
}

void endInitialize() {
	initializeScreen();
	initializeDebugFont();
	setBackgroundColor(createColor(0, 0, 0));
}
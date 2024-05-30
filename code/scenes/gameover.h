#include "../constants.h"

int gameover() {
	short waitTime = 180; // How many frames to wait
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
	initializeDebugFont(120, 50);
	setBackgroundColor(createColor(0, 0, 0));
}
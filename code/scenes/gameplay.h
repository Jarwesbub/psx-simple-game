#include "../constants.h"
#include "../sound.h"
#include "../../sounds/gameplay_theme.h"

Image player;

int x = 120;
int y = 100;
int speed = 2;

int gameplay() {
	short isActive = 1;
	initialize();

	while(isActive) {
		isActive = update();
		clearDisplay();
		draw();
		display();
	}
	clearDisplay();
	clearVRAM();
    return 0;
}

void initialize() {
	initializeScreen();
	initializePad();
	setBackgroundColor(createColor(0, 0, 0));

	audioInit();
	audioTransferVagToSPU(&gameplay_theme, gameplay_theme_size, SPU_0CH);
	audioPlay(SPU_0CH);

	player = createImage(img_crash, x, y);
}

int update() {
	padUpdate();
	if(padCheckPressed(PADselect) && padCheck(PADstart)) {
        return 0;
    }

	else if(padCheck(Pad1Up)) {
		y -= speed;
		player = moveImage(player, x, y);
	}

	else if(padCheck(Pad1Down)) {
		y += speed;
		player = moveImage(player, x, y);
	}

	else if(padCheck(Pad1Left)) {
		x -= speed;
		player = moveImage(player, x, y);
	}

	else if(padCheck(Pad1Right)) {
		x += speed;
		player = moveImage(player, x, y);
	}

	return 1;
}

void draw() {
	drawImage(player);
}
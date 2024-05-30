#include "../constants.h"
#include "../sound.h"
#include "../../sounds/gameplay_theme.h"

typedef struct {
	int x, y, speed;
	Image sprite;
} Player;

Player player;

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

	player.x = 120;
	player.y = 100;
	player.speed = 2;
	player.sprite = createImage(img_crash, player.x, player.y);
}

int update() {
	padUpdate();
	if(padCheck(PADselect)) {
        return 0;
    }

	if(padCheck(Pad1Up)) {
		player.y -= player.speed;
		player.sprite = moveImage(player.sprite, player.x, player.y);
	}

	if(padCheck(Pad1Down)) {
		player.y += player.speed;
		player.sprite = moveImage(player.sprite, player.x, player.y);
	}

	if(padCheck(Pad1Left)) {
		player.x -= player.speed;
		player.sprite = moveImage(player.sprite, player.x, player.y);
	}

	if(padCheck(Pad1Right)) {
		player.x += player.speed;
		player.sprite = moveImage(player.sprite, player.x, player.y);
	}

	return 1;
}

void draw() {
	drawImage(player.sprite);
}
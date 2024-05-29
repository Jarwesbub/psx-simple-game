#include "./code/scenes/menu.h"
#include "./code/scenes/gameplay.h"
#include "./code/scenes/gameover.h"


int main() {
	while(1) {
		menu();
		gameplay();
		gameover();
	}
	return 0;
}
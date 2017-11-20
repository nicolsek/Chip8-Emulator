/* Chip8.h -- An implementation of a Chip8's CPU. */
#include <string> //For the game name.

unsigned short opcode; //The current opcode being accessed, each opcode is 2 bytes. There are 35 opcodes.
unsigned char memory[4096]; //4KB of memory or 4096 bytes.

/* The CPU Registers */
unsigned char V[16]; //The register V(x) from 0 -> F.

unsigned short I; //Stores pointer information, right most 12 bits used.
unsigned short PC; //The program counter, 2 bytes each opcode.

unsigned short stack[16]; //The stack counter, 16 levels of nesting sub routine.
unsigned short SP; //The pointer to the stack.

unsigned char pixels[64 * 32]; //Graphics, represented as a 1 or a 0.

/* The Sound Timers */
unsigned char delay_timer; //Delay timer, whenever it's above 0 it starts counting down to 0 by a rate of -= 1 @ 60(hz), at 0 it deactivates.
unsigned char sound_timer; //Same with the delay but when it reaches 0 an audible buzz is heard.

/* User Keyboard */
unsigned char keyboard[16]; //From 0x0 - 0xF.

/**
 * @desc The Chip8 interpreter as a class, hey look I use the OOP paradigm.
 */
class Chip8 {
	public:
		void init(); //Init chip8
		void emulateCycle(); //Do an emulation frame.
		void loadGame(std::string); //Load a game if possible.
		void setKeys(); //Set if key is down or up.

		bool drawFlag;
};


void fetch();

void decode();
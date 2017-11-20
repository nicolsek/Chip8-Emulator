#include "chip8.h" //Self implementation, #Meta.
#include <iostream> 

/**
 * @desc Initialize the Chip8 interpreter.
 */
void Chip8::init() {
	PC = 0x200;
	opcode = 0; //Set the opcode to 0.
	I = 0;
	SP = 0;

	/* Do the things */
	//Clear the display.
	for (unsigned short clear = 0; clear < 64 * 32; ++clear) {
		pixels[clear] = 0;
	}

	//Clear the stack and the V registers.
	for (unsigned char clear = 0; clear < 16; ++clear) {
		stack[clear] = 0;
		V[clear] = 0;
	}
	
	//Clear the memory.
	for (unsigned short clear = 0; clear < 4096; ++clear) {
		memory[clear] = 0;
	}

	//Load the fonts.
	
	//Reset the timers.
	delay_timer = 0;
	sound_timer = 0;
}

/**
 * @desc Do an emulation frame.
 */
void Chip8::emulateCycle() {

}

/**
 * @desc Load the game by it's title.
 * @param {std::string} title the title of the game.
 */
void Chip8::loadGame(std::string title) {
	//
}

/**
 * @desc Set the keypresses if they're down or up.
 */
void Chip8::setKeys() {

}

/**
 * @desc Fetch the next opcode by merging the first two.
 */
void fetch() {
		opcode = memory[PC] << 8 | memory[PC + 1]; //Bitwise fucking shifting. 

}

/**
 * @desc Decode the opcode to the correct function in the opcode table.
 */ 
void decode() {
	switch(opcode & 0xF000) {
		case 0x0000:
			switch(opcode & 0x00FF) {
				case 0x0000: //Calls RCA 1802 program at address NNN. Not necessary for most ROMs.
			break;

				case 0x00E0: //Clears the screen.
			break;
				
				case 0x00EE: //Returns from a subroutine.
				PC = stack[--SP]; //Get the last place the PC was at.
				PC += 2; //Increase it cause subroutine is done.
			break;
		break;
			}

		case 0x1000: //Jumps to address NNN.
			I = opcode & 0x0FFF;
			PC += 2;
		break;

		case 0x2000: //Calls subroutine at NNN.
			stack[SP] = PC;
			++SP;
			PC = opcode & 0x0FFF;
		break;

		case 0x3000: //Skips the next instruction if VX equals NN. (Usually the next instruction is a jump to skip a code block)
			if (V[(opcode & 0x0F00 >> 8)] == opcode & 0x00FF) {
				PC += 2;
			}

			PC += 2;
		break;

		case 0x4000: //Skips the next instruction if VX doesn't equal NN. (Usually the next instruction is a jump to skip a code block)
			if (V[(opcode & 0x0F00) >> 8] != opcode & 0x00FF) {
				PC += 2;
			}

			PC += 2;
		break;

		case 0x5000: //Skips the next instruction if VX equals VY. (Usually the next instruction is a jump to skip a code block)
			if (V[(opcode & 0x0F00) >> 8] == V[(opcode & 0x00F0) >> 4]) {
				PC +=2;
			}

			PC += 2;
		break;

		case 0x6000: //Sets VX to NN.
			V[(opcode & 0x0F00) >> 8] = opcode & 0x00FF;

			PC += 2;
		break;

		case 0x7000: //Adds NN to VX. (Carry flag is not changed)
			V[(opcode & 0x0F00) >> 8] += opcode & 0x00FF;
		break;	

		case 0x8000:
			switch (opcode & 0x000F) {
				case 0x0000: //Sets VX to the value of VY.
					V[(opcode & 0x0F00) >> 8] = V[(opcode & 0x00F0) >> 4];
				break;

				case 0x0001: //Sets VX to VX or VY. (Bitwise OR operation)
					V[(opcode & 0x0F00) >> 8] = V[(opcode & 0x0F00) >> 8] | V[(opcode & 0x00F0) >> 4];
				break;

				case 0x0002: //Sets VX to VX and VY. (Bitwise AND operation)
					V[(opcode & 0x0F00) >> 8] = V[(opcode & 0x0F00) >> 8] & V[(opcode & 0x00F0) >> 4];
				break;

				case 0x0003: //Sets VX to VX xor VY.
					V[(opcode & 0x0F00) >> 8] = V[(opcode & 0x0F00) >> 8] ^ V[(opcode & 0x00F0) >> 4];
				break;

				case 0x0004: //Adds VY to VX. VF is set to 1 when there's a carry, and to 0 when there isn't.
						
				break;
			break;
			}	
		break;


		default:
			std::cout << "Uknown OpCode!" << std::endl;
	}
}
# Chip8-Emulator
A simple implementation of a Chip8 (interpreter technically) emulator. The goal is to be able to play and run a few demos of Chip8 games!
-----------

# Code Samples?
```C++
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
} //...
```
----------

# Why?
I thought this would be an awesome project to do. I really enjoyed working on this and better understanding bitshifting.
----------
/************************************************************************/
/* File Name : lc4_disassembler.c 										*/
/* Purpose   : This file implements the reverse assembler 				*/
/*             for LC4 assembly.  It will be called by main()			*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include "lc4_memory.h"

/**
 * translates the hex representation of arithmetic instructions
 * into their assembly equivalent in the given linked list.
 *
 * returns 0 upon success, and non-zero if an error occurs.
 */
int reverse_assemble (row_of_memory* memory)
{
	// printf("in reverse_assemble, linked list is %x\n", memory->contents);
	// convert hex to binary
	char hex[16];
	//use sprintf to convert unsigned int to string
	sprintf(hex, "%x", memory->contents);
  // printf("\n The string for the num is %s\n", hex);

	//call hextobin in lc4_memory.c to convert hex to binary
	char binary[16];
	// printf("hex is %s\n", hex);
	strcpy(binary, hextobin(hex));
	// printf("binary is %s\n", binary);

	//extract opcode
	char opcode[4];
	// opcode[4]='\0';

	switch(binary[10]){
		//case on 10th digit
			case '0':
			if(binary[11]=='0' & binary[12]=='0'){
				printf("11th and 12th digit is also 0, the operatio is ADD\n");
				// printf("memory assembly is %s\n", memory->assembly );
				// copy add into opcode
				strcpy(opcode, "ADD");
				// printf("memory assembly after assignment is %s\n", memory->assembly );

			} else if (binary[11]=='0' & binary[12]=='1'){
				printf("11th 0, and 12th 1, the operatio is MUL");
				// copy add into opcode
				strcpy(opcode, "MUL");

			} else if(binary[11]=='1' & binary[12]=='0'){
				printf("11th 1, and 12th 0, the operatio is SUB");
				// copy add into opcode
				strcpy(opcode, "SUB");
			} else if(binary[11]=='1' & binary[12]=='1'){
				printf("11th 1, and 12th 1, the operatio is DIV");
				// copy add into opcode
				strcpy(opcode, "DIV");
				// assign to memory->assembly;
			}
			memory->assembly = malloc(14);
			memory->assembly[14]='\0';
			strcat(memory->assembly,opcode);
			printf("memory assembly is %s\n", memory->assembly);

			break;
			case '1':
			printf("the operation is ADD IMMI\n");
			// copy add into opcode
			strcpy(opcode, "ADD");
			break;
		}

	//extract rd
	if(binary[4] == '0' & binary[5]=='0' &binary[6]=='0'){
		printf("rd is r0");
		//copy rd into memeory assembly
		char rd[4];
		strcpy(rd, " R0,");
		strcat(memory->assembly,rd);
		printf("memory assembly is %s\n", memory->assembly);
	} else if (binary[4] == '0' & binary[5]=='0' & binary[6]=='1'){
		printf("rd is r1");
		//copy rd into memeory assembly
		char rd[4];
		strcpy(rd, " R1,");
		strcat(memory->assembly,rd);
		printf("memory assembly is %s\n", memory->assembly);
	} else if (binary[4] == '0' & binary[5]=='1' & binary[6]=='0'){
		printf("rd is r2");
		//copy rd into memeory assembly
		char rd[4];
		strcpy(rd, " R2,");
		strcat(memory->assembly,rd);
		printf("memory assembly is %s\n", memory->assembly);
	} else if (binary[4] == '0' & binary[5]=='1' & binary[6]=='1'){
		printf("rd is r3");
		//copy rd into memeory assembly
		char rd[4];
		strcpy(rd, " R3,");
		strcat(memory->assembly,rd);
		printf("memory assembly is %s\n", memory->assembly);
	} else if (binary[4] == '1' & binary[5]=='0' & binary[6]=='0'){
		printf("rd is r4");
		//copy rd into memeory assembly
		char rd[4];
		strcpy(rd, " R4,");
		strcat(memory->assembly,rd);
		printf("memory assembly is %s\n", memory->assembly);
	} else if (binary[4] == '1' & binary[5]=='0' & binary[6]=='1'){
		printf("rd is r5");
		//copy rd into memeory assembly
		char rd[4];
		strcpy(rd, " R5,");
		strcat(memory->assembly,rd);
		printf("memory assembly is %s\n", memory->assembly);
	} else if (binary[4] == '1' & binary[5]=='1' & binary[6]=='0'){
		printf("rd is r6");
		//copy rd into memeory assembly
		char rd[4];
		strcpy(rd, " R6,");
		strcat(memory->assembly,rd);
		printf("memory assembly is %s\n", memory->assembly);
	} else if (binary[4] == '1' & binary[5]=='1' & binary[6]=='1'){
		printf("rd is r7");
		//copy rd into memeory assembly
		char rd[4];
		strcpy(rd, " R7,");
		strcat(memory->assembly,rd);
		printf("memory assembly is %s\n", memory->assembly);
	}

//extract rs
	if(binary[7] == '0' & binary[8]=='0' &binary[9]=='0'){
		printf("rs is r0");
		//copy rd into memeory assembly
		char rs[4];
		strcpy(rs, " R0,");
		strcat(memory->assembly,rs);
		printf("memory assembly is %s\n", memory->assembly);
	} else if (binary[7] == '0' & binary[8]=='0' & binary[9]=='1'){
		printf("rs is r1");
		//copy rd into memeory assembly
		char rs[4];
		strcpy(rs, " R1,");
		strcat(memory->assembly,rs);
		printf("memory assembly is %s\n", memory->assembly);
	} else if (binary[7] == '0' & binary[8]=='1' & binary[9]=='0'){
		printf("rs is r2");
		//copy rd into memeory assembly
		char rs[4];
		strcpy(rs, " R2,");
		strcat(memory->assembly,rs);
		printf("memory assembly is %s\n", memory->assembly);
	} else if (binary[7] == '0' & binary[8]=='1' & binary[9]=='1'){
		printf("rs is r3");
		//copy rd into memeory assembly
		char rs[4];
		strcpy(rs, " R3,");
		strcat(memory->assembly,rs);
		printf("memory assembly is %s\n", memory->assembly);
	} else if (binary[7] == '1' & binary[8]=='0' & binary[9]=='0'){
		printf("rs is r4");
		//copy rd into memeory assembly
		char rs[4];
		strcpy(rs, " R4,");
		strcat(memory->assembly,rs);
		printf("memory assembly is %s\n", memory->assembly);
	} else if (binary[7] == '1' & binary[8]=='0' & binary[9]=='1'){
		printf("rs is r5");
		//copy rd into memeory assembly
		char rs[4];
		strcpy(rs, " R5,");
		strcat(memory->assembly,rs);
		printf("memory assembly is %s\n", memory->assembly);
	} else if (binary[7] == '1' & binary[8]=='1' & binary[9]=='0'){
		printf("rs is r6");
		//copy rd into memeory assembly
		char rs[4];
		strcpy(rs, " R6,");
		strcat(memory->assembly,rs);
		printf("memory assembly is %s\n", memory->assembly);
	} else if (binary[7] == '1' & binary[8]=='1' & binary[9]=='1'){
		printf("rs is r7");
		//copy rd into memeory assembly
		char rs[4];
		strcpy(rs, " R7,");
		strcat(memory->assembly,rs);
		printf("memory assembly is %s\n", memory->assembly);
	}

	//extract rt
		if(binary[13] == '0' & binary[14]=='0' &binary[15]=='0'){
			printf("rt is r0");
			//copy rd into memeory assembly
			char rt[4];
			strcpy(rt, " R0");
			strcat(memory->assembly,rt);
			printf("memory assembly is %s\n", memory->assembly);
		} else if (binary[13] == '0' & binary[14]=='0' & binary[15]=='1'){
			printf("rt is r1");
			//copy rd into memeory assembly
			char rt[4];
			strcpy(rt, " R1");
			strcat(memory->assembly,rt);
			printf("memory assembly is %s\n", memory->assembly);
		} else if (binary[13] == '0' & binary[14]=='1' & binary[15]=='0'){
			printf("rt is r2");
			//copy rd into memeory assembly
			char rt[4];
			strcpy(rt, " R2");
			strcat(memory->assembly,rt);
			printf("memory assembly is %s\n", memory->assembly);
		} else if (binary[13] == '0' & binary[14]=='1' & binary[15]=='1'){
			printf("rt is r3");
			//copy rd into memeory assembly
			char rt[4];
			strcpy(rt, " R3");
			strcat(memory->assembly,rt);
			printf("memory assembly is %s\n", memory->assembly);
		} else if (binary[13] == '1' & binary[14]=='0' & binary[15]=='0'){
			printf("rt is r4");
			//copy rd into memeory assembly
			char rt[4];
			strcpy(rt, " R4");
			strcat(memory->assembly,rt);
			printf("memory assembly is %s\n", memory->assembly);
		} else if (binary[13] == '1' & binary[14]=='0' & binary[15]=='1'){
			printf("rt is r5");
			//copy rd into memeory assembly
			char rt[4];
			strcpy(rt, " R5");
			strcat(memory->assembly,rt);
			printf("memory assembly is %s\n", memory->assembly);
		} else if (binary[13] == '1' & binary[14]=='1' & binary[15]=='0'){
			printf("rt is r6");
			//copy rd into memeory assembly
			char rt[4];
			strcpy(rt, " R6");
			strcat(memory->assembly,rt);
			printf("memory assembly is %s\n", memory->assembly);
		} else if (binary[13] == '1' & binary[14]=='1' & binary[15]=='1'){
			printf("rt is r7");
			//copy rd into memeory assembly
			char rt[4];
			strcpy(rt, " R7");
			strcat(memory->assembly,rt);
			printf("memory assembly is %s\n", memory->assembly);
		}



	//call search_opcode in lc4_memory

	return 0 ;
}

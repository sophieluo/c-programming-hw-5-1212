/************************************************************************/
/* File Name : lc4.c 													*/
/* Purpose   : This file contains the main() for this project			*/
/*             main() will call the loader and disassembler functions	*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include "lc4_memory.h"
#include "lc4_loader.h"
#include "lc4_disassembler.h"

/* program to mimic pennsim loader and disassemble object files */

int main (int argc, char** argv) {

	/**
	 * main() holds the linked list &
	 * only calls functions in other files
	 */

	/* step 1: create head pointer to linked list: memory 	*/
	row_of_memory* memory = NULL ;


	/* step 2: determine filename, then open it		*/
	/*   TODO: extract filename from argv, pass it to open_file() */
  char* file_name = argv[1];
  printf("file name is %s \n", file_name);
//     file_name = "'" + file_name + "'";
//     printf("file name after cat is %s\n", file_name);

  //call open_file and pass in arg file_name
  FILE* test_file = open_file(file_name);

	/* step 3: call function: parse_file() in lc4_loader.c 	*/
	/*   TODO: call function & check for errors		*/
  parse_file(test_file, &memory);

	/* step 4: call function: reverse_assemble() in lc4_disassembler.c */
	/*   TODO: call function & check for errors		*/


	/* step 5: call function: print_list() in lc4_memory.c 	*/
	/*   TODO: call function 				*/


	/* step 6: call function: delete_list() in lc4_memory.c */
	/*   TODO: call function & check for errors		*/


	/* only return 0 if everything works properly */
	return 0 ;
}

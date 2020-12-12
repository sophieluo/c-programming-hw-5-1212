/************************************************************************/
/* File Name : lc4_loader.c		 										*/
/* Purpose   : This file implements the loader (ld) from PennSim		*/
/*             It will be called by main()								*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include "lc4_memory.h"

/* declarations of functions that must defined in lc4_loader.c */

FILE* open_file(char* file_name)
{
    FILE *my_file;

    printf("hello i'm opening the file %s\n", file_name);
	//open file
	my_file = fopen(file_name, "rb");

//     if my_file is null, return null
	if (my_file == NULL) {return NULL; }

    // if open_file successful, return my_file. which is the pointer to the file opened
	return my_file ;
}

int get_next_character(FILE * file) {
  unsigned char buffer; // note: 1 byte
  int result = fread(&buffer, 1, 1, file);
  if (result == 1) {
    return buffer;
  }
  return -1;
}

int get_next_4_bytes(FILE * file) {
  int result = get_next_character(file);
  if (result == -1) return -1;
  result = result * 256 + get_next_character(file);
  return result;
}

int parse_file (FILE* my_obj_file, row_of_memory** memory) {
	printf("hello i'm parsing the file\n");

//     initialize linked list
     *memory = NULL;
//     *head = (row_of_memory*)malloc(sizeof(row_of_memory));

    //read in a string from the open file
    // printf("file is &s", fgets(memory, 100, my_obj_file));
    while (1) {
      // at the start,  we get <code> <address> <n>, all of them are 4 bytes
      int code = get_next_4_bytes(my_obj_file);
      if (code == -1) {
        // we reach the end of the obj file
        break;
      }
      int address = get_next_4_bytes(my_obj_file);
      int n = get_next_4_bytes(my_obj_file);
      // if 0xcade is CODE, then the next n words are code instructions
      // so we find all those n words and attach to linked list
      // the content of the memory will be the word retrieved
      // if its 0xdada, then next n words are data, logic is exactly th same
      if (code == 0xcade || code == 0xdada) {
        while (n > 0) {
          int contents = get_next_4_bytes(my_obj_file);

          //test if parameters passed to add_to_list are correct
          printf("memory is %x\n", memory );
          printf("address is %x\n", address );
          printf("contents is %x\n", contents );
          add_to_list(memory, address++, contents);
          n--;
        }
      } else if (code == 0xc3b7) {
        // if code is 0xc3b7, it means, were are inside symbol block
        // the address is given a label specified by the next n characters
        // so we need to find the address and set its label as the label obtained by reading the n characters
        char * label = malloc((n + 1) * sizeof(char));
        char * nxt = label;
        while (n-- > 0) {
          *nxt++ = (char)get_next_character(my_obj_file);
        }
        *nxt = '\0';

        //find address in memory and set the label of the address
        search_address(*memory, address)->label = label;
      } else {
        puts("dafaq");
      }
    }

    print_list(*memory);
    fclose(my_obj_file);

    // printf("the populated string is %s\n", memory);

    free(*memory);

//     int add_to_list (row_of_memory** head,
// 		 short unsigned int address,
// 		 short unsigned int contents)
//     {

    return 0 ;
}

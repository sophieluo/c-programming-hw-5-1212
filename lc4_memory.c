/************************************************************************/
/* File Name : lc4_memory.c		 										*/
/* Purpose   : This file implements the linked_list helper functions	*/
/* 			   to manage the LC4 memory									*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include "lc4_memory.h"


/*
 * adds a new node to linked list pointed to by head
 */
int add_to_list (row_of_memory** head,
		 short unsigned int address,
		 short unsigned int contents)
{

	/* allocate memory for a single node */
    row_of_memory* new_row = malloc (sizeof (row_of_memory));
    //return -1 if malloc fails
    if (new_row == NULL) return -1;

	/* populate fields in newly allocated node w/ address&contents */
		new_row->address = address;
		new_row->contents = contents;
		new_row->label = NULL;
		new_row->next = NULL;
		new_row->assembly = NULL;

	/* if head==NULL, node created is the new head of the list! */
    if (*head == NULL) {
        *head = new_row;
        return 0;
    }
	/* otherwise, traverse linked list until reach the right spot to insert this node */
		else {
			//set tail equal to current head
			row_of_memory *tail = *head;
			while (tail->next != NULL) {
				//set tail equal to next tail
				tail = tail->next;
			}
	/* insert node into the list - perform necessary "surgery" on this list */
			tail->next = new_row;
		}

	/* return 0 for success, -1 if malloc fails */
	return 0 ;
}

/*
 * search linked list by address field, returns node if found
 */
row_of_memory* search_address (row_of_memory* head,
			       short unsigned int address )
{
	/* traverse linked list, searching each node for "address"  */
    while((head != NULL) && (head->address != address))

	/* return pointer to node in the list if item is found */
       head = head->next;

	/* return head (works evenif list is empty or if "address" isn't found) */
	return (head) ;
}

/*
 * search linked list by opcode field, returns node if found
 */
row_of_memory* search_opcode  (row_of_memory* head,
				      short unsigned int opcode  )
{
	/* traverse linked list until node is found with matching opcode
	   AND "assembly" field of node is empty */
    while ((head != NULL) && (head->contents!= opcode))

	/* return pointer to node in the list if item is found */
        head = head->next;

	/* return head (works even if list is empty or if no matching nodes)*/
	return (head) ;
}


void print_list (row_of_memory* head )
{
	/* make sure head isn't NULL */
    while (head != NULL){
	/* print out a header */
    printf("address = %x contents=%x label=%s\n", head->address, head->contents, head->label);
	/* traverse linked list, print contents of each node */
		head = head->next;
	}
}

/*
 * delete entire linked list
//  */
// int delete_list    (row_of_memory** head )
// {
// 	// /* delete entire list node by node */
// 	// /* if no errors, set head = NULL upon deletion */
//   //   row_of_memory * temp1 = temp2 = head;
//   //   temp1->next = temp2->next;
// 	//
//   //   free(temp2->address);
//   //   free(temp2);
// 	//
// 	// /* return 0 if no error, -1 for any errors that may arise */
// 	// return 0 ;
// }

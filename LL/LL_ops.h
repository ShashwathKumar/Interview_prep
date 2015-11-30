/*
 * LL_ops.h
 *
 *  Created on: Nov 14, 2015
 *      Author: Shashwath
 */

#ifndef LL_OPS_H_
#define LL_OPS_H_

//#include <iostream>
#include <stdlib.h>
/*
#ifndef NULL
#define NULL ((void*) 0)
#endif
*/
//struct Node;
//#define NULL -1
struct Node{
	int data;
	struct Node* next;
};
//extern Node *HEAD;
struct Node* init_node(int);
void insert(struct Node* newNode, int position);
void print_list();

void del_dups();
int find_equal(Node**, Node**, int);
void del_dups_nonrecur();
void swap();

#endif

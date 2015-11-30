//============================================================================
// Name        : LL.cpp
// Author      : Shashwath
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "LL_ops.h"
#include <iostream>
using namespace std;

int LL_elements[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
        //HEAD=NULL;
	Node* node;
	int in, position, choice;
	char decision;
/*
	do{
		cout<<"Please enter the character to insert :";
		cin>>in;
                cout<<"Please enter the position where you want to insert :";
                cin>>position;
		node = (Node*)init_node(in);
		insert(node, position);
		cout<<"would you like to enter more data (y/n) :";
		cin>>decision;
            
	}while (decision == 'y' || decision == 'Y');
*/
        
//code for automatic LL insertion
            position = 1;
            for(int i=8; i>=0; --i){
                in = LL_elements[i];
                node = (Node*)init_node(in);
                insert(node, position);        
            }
//--------------------------------------------------------            
        
        print_list();
        
        cout<<"\n Please select which deletion opn u wud like to perform : ";
        cout<<"\n 1. Delete duplicates : ";
        cout<<"\n 2. Delete duplicates recursively : ";
        cout<<"\n 3. Swap adjacent nodes : ";
        cin>>choice;
        cout<<"\n choice was :"<<choice;
        if(choice == 1) {del_dups_nonrecur();}
	else if(choice == 2) { del_dups(); }
        else if(choice == 3) {cout<<"\n calling swap"; swap();}
        cout<<"\n Printing list :"<<endl;
        print_list();
	return 0;
}
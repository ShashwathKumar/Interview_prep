//#include <Headers>

//#include <Headers>
/*
#include <iostream>
#include <stdlib.h>
*/
#include "LL_ops.h"
#include <iostream>
//#include <conio.h>
using namespace std;

struct Node* HEAD=NULL;
Node* init_node(int n)
{	struct Node* ptr = new Node;
	ptr->data = n;
	ptr->next = NULL;
	return ptr;
}

void insert(Node* newNode, int position)
{
    Node *p=HEAD, *q; int k =1;
    if(HEAD == NULL && position == 1) HEAD = newNode;    
    else if(position == 1)
        {
            newNode->next = HEAD;
            HEAD = newNode;
        }
	else 
	{
            while(k<position && p!=NULL)
            {
                k++;
                q=p;
                p=p->next;
            }
            
            q->next = newNode;
            newNode->next = p;
	}
}
void print_list()
{
        cout<<"\n";
	Node* node = HEAD;
	do{
		cout<<" "<<node->data;
		node = node->next;
	}while(node != NULL);
        cout<<"\n";
}
void del_dups()
{
    Node* node = HEAD, *p, *q, *temp;
    int data, found=0;
    
    while(node->next != NULL)
    {
        cout<<"Node value :"<<node->data<<endl<<endl;
        q = node;
        p = node->next;
        data = node->data;
        while(p!=NULL)
       {
        found = find_equal(&q,&p,data);
            if(found == 1)
            {
                cout<<"Before deletion : p "<<p->data<<" q "<<q->data<<" Data "<<data<<endl;
                temp = p;
                q->next = p->next;
                p=p->next;
                cout<<"About to delete : p "<<p->data<<" q "<<q->data<<" Temp "<<temp->data<<endl<<endl;
                if(temp!=NULL) free(temp);
                found = 0;
                print_list();
            }
       } 
        node = node->next;
        cout<<"Node value :"<<node->data<<endl<<endl;
    }
}
int find_equal(Node **q, Node **p, int data)
    {
    cout<<"p "<<(*p)->data<<" q "<<(*q)->data<<" Data "<<data<<endl;
        if((*p)->data == data) return 1;
        //else if((*p)==NULL) return 0;
        else{
            *q=*p;
            *p=(*p)->next;
            if(*p == NULL) return 0;
            return find_equal(q,p,data);
        }
    }
void del_dups_nonrecur()
{
    Node* node = HEAD, *p, *q, *temp;
    int data;
    
    while(node->next != NULL)
    {
        q = node;
        p = node->next;
        data = node->data;
        while(p!=NULL)
       {
        if(p->data == data)
            {
                temp = p;
                q->next = p->next;
                p=p->next;
                free(temp);
            }
        else
        {
            q=p;
            p=p->next;    
        }    
       } 
        node = node->next;
    }
}

void swap()
{
       Node *q, *p, *t1, *t2;
   cout<<"\n In swap ..!!";
   
  if(HEAD != NULL && HEAD->next != NULL)  
  { 
    q = HEAD;
    p = HEAD->next;
    HEAD = p;
    
    while(p->next != NULL && p->next->next != NULL)
        //it is very imp that above code is in this order
        //else in the last condition p->next->next will try to calculate NULL->next
        //which is undefined and will crash the execution
    {
        t1 = p->next;
        t2 = p->next->next;
      cout<<"\n t1 : "<<t1->data<<" t2 : "<<t2->data<<" q : "<<q->data<<" p : "<<p->data;
        q->next = p->next->next;
        p->next = q;
        q = t1;
        p = t2;
        //for(int i=0; i<1000000; ++i);
    }
    
    if(p->next == NULL)
    {
        cout<<"\n p->next is NULL";
        cout<<"\n q : "<<q->data<<" p : "<<p->data;
        q->next = NULL;
        p->next = q;
    }
    else if(p->next->next == NULL)
    {
        cout<<"\n p->next->next is NULL";
        cout<<"\n q : "<<q->data<<" p : "<<p->data;
        q->next = p->next;
        p->next = q;
    }
  }
}
            
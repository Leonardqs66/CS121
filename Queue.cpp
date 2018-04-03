

//=======================================
//	Qamron Leonard
//	cs 121 assignment 3
//	queue.h
//=======================================

#include<iostream>
#include<cstdlib>
using namespace std;


/////////////////////////
//------NODE CLASS-----//
/////////////////////////
class node{
    public:
//-----Data-----//
		int Eta;
		string Name;
		double NumItems;
		node * Next;
		node * Prev;
//-----Constructor-----//
		node(){Eta =-100; Name = "Qamron"; NumItems= -100; Next = NULL; Prev = NULL;}
//-----Methods-----//
		void PrintNode(){
		cout << " (" << Eta << " " << Name << " " << NumItems << ") ";
		}
	};

/////////////////////////
//-----QUEUE CLASS-----//
/////////////////////////
class Queue{

//NOTE: I used a doubly linked list for my queues

public:
//-----Data-----//
    node * Front;
    node * Tail;

//-----Constructor-----//
	Queue(){
    Front = NULL;
    Tail = Front;
	};

//-----Methods-----//
	void PrintQueue(){      // prints the contents of queue
	node* curr;
	curr = Tail;
        while (curr != NULL){
        curr->PrintNode();
        curr = curr->Next;
        }
	};

	void Enqueue(node *Node2Add){   //add node to end of list

        if(  Front == NULL&& Tail == NULL){
            Front = Node2Add;
            Tail = Node2Add;
        }else{
            Node2Add->Next = Tail;
            Tail->Prev = Node2Add;
            Tail = Node2Add;
	    }
	};

	void Dequeue(){     // removes node from front of list
        node * TempNode;
        TempNode = Front;
        if(Front->Prev != NULL){
            Front = Front->Prev;
            Front->Next = NULL;
        }
        else{
            Front = NULL;
            Tail = NULL;
        }

        delete TempNode;
	};

	node * DequeueR(){     // removes node from front of list
        node * TempNode;
        TempNode = Tail;
        Tail = Tail->Next;
        Tail->Prev = NULL;
        return TempNode;
	};

	int Length(){   //returns the length of the queue
	    int count = 0;
	    node* curr;
        curr = Tail;
        if (curr!=NULL){
            count = 1;
            while (curr->Next != NULL){
            count++;
            curr = curr->Next;
            }
            return count;
        }else{
        return 0;
        }
	};

};



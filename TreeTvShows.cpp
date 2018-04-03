#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

class Node{
    public:
    string Title;
    int StartDate;
    int EndDate;
    string Genre;
    string Link;
    string Actors[20];
    Node * Left;
    Node * Right;
    Node(){
        Title = "Cheesecake";
        StartDate = 6;
        EndDate = 6;
        Genre = "Chzcake";
        Link = "www.Cheesecake.org";
        for(int i = 0; i < 20; i++){
        Actors[i] = "Qamron";
        }
        Left = NULL;
        Right = NULL;

    };
    void PrintTitle(){
        cout << Title;
    }
    void PrintRunDates(){
        cout << StartDate<< '-' << EndDate;
    }
    void PrintGenre(){
        cout << Genre;
    }
    void PrintURL(){
        cout << Link;
    }
    void PrintActors(){
        for(int i = 0; i<20; i++){
            if(Actors[i] != "Qamron"){
            cout << Actors[i];
            }
        }
    }

};
//typedef Node * = nodePtr;
class TVTree{
    public:
    Node* RootPtr= NULL;

    Search(Node *Show2Find){ //searches for a node

    }
    void PrintByTitle(){

    }
    void PrintActors(){

    }
    PrintAllShowsOfActor(){

    }
    GetDates(){

    }
    PrintByReleaseDate(){

    }
    AddTVShow(Node* Show2Add){
        if(RootPtr == NULL){
            RootPtr = Show2Add;
        }else{
            Node * TreePtr;
            TreePtr = RootPtr;
            Node * TargetNodePtr;
            while(TreePtr !=NULL){
                TargetNodePtr = TreePtr;
                if(Show2Add->StartDate <= TreePtr->StartDate){
                    TreePtr = TreePtr->Left;
                }else if(Show2Add->StartDate > TreePtr->StartDate){
                    TreePtr = TreePtr->Right;
                }
            }
        }
    }

};

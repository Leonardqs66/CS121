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
        cout << endl << Title;
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
            cout << Actors[i] << endl;
            }
        }
    }
    void Print(){
        PrintTitle();
        cout << " " << '(';
        PrintRunDates();
        cout << ')' << endl;
        PrintGenre();
        cout << endl;
        PrintURL();
        cout << endl;
        PrintActors();

    }
};
//typedef Node * = nodePtr;
class TVTree{
    public:
    Node* RootPtr= NULL;
    TVTree(){

    }
    void Print1992Decade(Node * t){
        if(t != NULL){
            Print1992Decade(t->Left);
            int temp1 = t->StartDate;
            if(temp1 >= 1992 && temp1 < 2002){
            t->PrintTitle();
            cout << t->StartDate;
            cout << endl;
            }
            else{}
            Print1992Decade(t->Right);
        }
    }
    void Print1972Decade(Node * t){
        if(t != NULL){
            Print1972Decade(t->Left);
            int temp1 = t->StartDate;
            if(temp1 >= 1972 && temp1 < 1982){
            t->PrintTitle();
            cout << t->StartDate;
            cout << endl;
            }
            else{}
            Print1972Decade(t->Right);
        }
    }
    void PrintByTitleY(Node * t){
        if(t != NULL){
            PrintByTitleY(t->Left);
            t->PrintTitle();
            cout << t->StartDate;
            cout << endl;
            PrintByTitleY(t->Right);
        }
    }
    void PrintByTitle(Node * t){
        if(t != NULL){
            PrintByTitle(t->Left);
            cout << t->Title << endl;
            PrintByTitle(t->Right);
        }
    }
/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////

//FIX ACTORSINSHOW() !!!!!!!!!!!!!!!!!!!
    void ActorsInShow(string ShowName,Node * t){
        if(t !=NULL){
            ActorsInShow(ShowName, t->Left);
            if(t->Title == ShowName){
                t->PrintActors();
            }
            ActorsInShow(ShowName, t->Right);
        }
    }
    void PrintAllShowsOfActor(string Actor, Node * t){
        if(t !=NULL){
            PrintAllShowsOfActor(Actor, t->Left);
            for(int i =0; i < 15; i++){
                if(t->Actors[i] == Actor ){
                    t->PrintTitle();
                    cout << endl;
                }
            }
            PrintAllShowsOfActor(Actor, t->Right);
        }
    }


    void AddTVShow(Node* Show2Add){
        Node * newPtr;

        if(RootPtr == NULL){
            RootPtr = Show2Add; //Show2Add;
        }else{
            Node * TreePtr;
            TreePtr = RootPtr;
            Node * TargetNodePtr;
            //--Traverse Tree--
            while(TreePtr != NULL){
                TargetNodePtr = TreePtr;
                if(Show2Add->StartDate < TreePtr->StartDate){
                    TreePtr = TreePtr->Left;
                }else{ //if(Show2Add->StartDate > TreePtr->StartDate){
                    TreePtr = TreePtr->Right;
                }
            }
            //--AddNode--
                if( Show2Add->StartDate < TargetNodePtr->StartDate){
                    TargetNodePtr->Left = newPtr;
                } else{
                    TargetNodePtr->Right = newPtr;
                }

        }
    }

};

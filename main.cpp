#include "TreeTvShows.cpp"
//#include "TVDat.txt"
using namespace std;
void ReadInFile(string FileName);
TVTree BST;
int main()
{
ReadInFile("TVDat.txt");
cout << endl << endl;
cout << "By Title" << endl;
BST.PrintByTitle(BST.RootPtr);
cout << "===============================================" << endl << endl;
cout << "Shows between 1972 and 1982" << endl;
BST.Print1972Decade(BST.RootPtr);
cout << "===============================================" << endl << endl;
cout << "Shows between 1992 and 2002" << endl;
BST.Print1992Decade(BST.RootPtr);
cout << "===============================================" << endl << endl;
cout << "Actors in a show" << endl;
BST.ActorsInShow("The Andy Griffith Show", BST.RootPtr);
cout << "===============================================" << endl << endl;

cout << "===============================================" << endl << endl;

cout << "===============================================" << endl << endl;

cout << "===============================================" << endl << endl;
cout << "All Shows of Actor: Andy Griffith" << endl;
BST.PrintAllShowsOfActor("Andy Griffith", BST.RootPtr);
cout << "===============================================" << endl << endl;
cout << "All Shows of Actor: Burt Reynolds" << endl;
BST.PrintAllShowsOfActor("Burt Reynolds", BST.RootPtr);
cout << "===============================================" << endl << endl;
cout << "All Shows of Actor: Bill Mumy" << endl;
BST.PrintAllShowsOfActor("Bill Mumy", BST.RootPtr);
cout << "===============================================" << endl << endl;
cout << "All Shows of Actor: Mark Harmon" << endl;
BST.PrintAllShowsOfActor("Mark Harmon", BST.RootPtr);
cout << "===============================================" << endl << endl;
cout << "All Shows of Actor: Angela Cartwrigh" << endl;
BST.PrintAllShowsOfActor("Angela Cartwrigh", BST.RootPtr);
cout << "===============================================" << endl << endl;
cout << "All Shows of Actor: Majel Barrett" << endl;
BST.PrintAllShowsOfActor("Majel Barrett", BST.RootPtr);
cout << "===============================================" << endl << endl;
}


void ReadInFile(string FileName){
        ifstream infile;
        infile.open(FileName);
        char waste;
        string temp;
        while(!infile.eof()){
            Node * tempNode = new Node;
            getline(infile,tempNode->Title ,'(');
            infile >> tempNode->StartDate;
            infile >> waste; // for '-'
            infile >> tempNode->EndDate;
            infile >> waste; // for ')'

            getline(infile,tempNode->Genre);
            getline(infile,tempNode->Link);
            for (int i = 0; i <20; i++){
                getline(infile, temp);
                if(temp==""){
                    i=20;
                }else{
                        tempNode->Actors[i]=temp;
                }
            }
            tempNode->Print();

            BST.AddTVShow(tempNode);

        }

}

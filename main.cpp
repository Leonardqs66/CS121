#include "TreeTvShows.cpp"
//#include "TVDat.txt"
using namespace std;
void ReadInFile(string FileName);

int main()
{
ReadInFile("TVDat.txt");
}


void ReadInFile(string FileName){
        ifstream infile;
        infile.open(FileName);
        Node *tempNode;
        string waste;
        string temp;
        while(!infile.eof()){
            tempNode = new Node;
            getline(infile,tempNode->Title ,'(');
            //getline(infile,tempNode->StartDate, '-' );
            //getline(infile,tempNode->EndDate,')');
            infile >> tempNode->StartDate;
            infile >> waste; // for '-'
            infile >> tempNode->EndDate;
            infile >> waste; // for ')'

            getline(infile,tempNode->Genre);
            getline(infile,tempNode->Link);
            for (int i = 0; i <10; i++){
                getline(infile, temp);
                if(temp==""){
                    i=10;
                }else{
                        tempNode->Actors[i]=temp;
                }
            }

            /*while((infile.peek() != '/n')){
                const int ActorCount = 0;
                getline(infile,tempNode->Actors[ActorCount]);
                ActorCount++;
            }*/
        }

}

#include <iostream>
using namespace std;
int main(){
  
    int b[8][8]={0};//initialzing the board
    int r,c=0;//initializing row and column
    b[0][0]=1;//placing queen on top left square
    int counter=1;//counter for solutions
    
    //Next Column
    NC: c++;
        if(c==8) goto print; //once it has found a solution
        r=-1;
    NR: r++;
        if(r==8) goto backtrack; //once none of the rows work
        //row test
        for(int i=0;i<c;i++){
            if(b[r][i]==1) goto NR;
        }
        //upward diagonal test
        for(int i=1;(r-i)>=0&&(c-i)>=0;i++){
            if(b[r-i][c-i]==1) goto NR;
        }
        //downward diagonal test
        for(int i=1;((r+i)<8)&&((c-i)>=0);i++){
            if(b[r+i][c-i]==1) goto NR;
        }
            b[r][c]=1;
            goto NC;
        
    backtrack: c--;
        if(c==-1) return 0;
        r=0;
        while(b[r][c]!=1) r++;
        b[r][c]=0;
        goto NR;
    print:
        cout<<endl<<"Solution: "<<counter<<endl;
        for(int i=0;i<=7;i++){
            for(int j=0;j<=7;j++){
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
        counter++;
        goto backtrack;

    return 0;
}

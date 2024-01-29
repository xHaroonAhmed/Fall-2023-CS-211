#include <iostream>
using namespace std;
int main()
{
    int q[8]{0};//initialize 1-D array
    int c=0;
    int counter=1;//for solutions
    q[0]=0;//set first index to 0
    
    NC: c++;
        if(c==8) goto print;//once you find a solution
        q[c]=-1;
    NR: q[c]++;
        if(q[c]==8) goto backtrack;//go back if can't find a solution
        //up+down+row test
        for(int i=0;i<c;i++){
            if((q[i]==q[c])||(c-i==abs(q[c]-q[i]))) goto NR;
        }
        goto NC;
    backtrack: c--;
        if(c==-1) return 0;//no solution found
        goto NR;
    print: cout<<endl<<"Solution: "<<counter<<endl<<endl;
        for(int r=0;r<8;r++){
            for(int c=0;c<8;c++){
                if(q[r]==c) cout<<"X";
                else cout<<"O";
            }
            cout<<endl;
        }
        counter++;
        goto backtrack;
        
return 0;
}


#include <iostream>
using namespace std;

bool ok(int q[], int c){ //okay function checking for stability 
    
    static int mp[3][3]={ //setting men's preferences
        { 0, 2, 1 },     
        { 0, 2, 1 },
        { 1, 2, 0 }
        
    };   

    static int wp[3][3]={ //setting women's preferences
        { 2, 1, 0 },     
        { 0, 1, 2 },    
        { 2, 0, 1 }
    }; 

    for (int i = 0; i < c; i++){ //checking against every preference to assure stability
        if(q[c] == q[i] ||(mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) || (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]))   
        return false; 
        }
    return true;
}

void print(int q[]){  //print function
    static int solution=1;
    cout<<"Solution # "<<solution++<<"\nMan"<<"     "<<"Woman\n";
    for (int i=0;i<3;i++){
        cout<<i<<"       "<<q[i]<<endl;
    }
}

int main (){
    int q[3], c = 0; //initizalization 1D array with starting position at 0
    q[0] = 0; //setting first element to 0

        while (c>=0) { //outer while loop, position check
            c++; //increment man column
            if (c == 3) { //position check
                print(q); //print function
                c--; //backtrack
            } else
                q[c] = -1; 

            while (c >= 0) { // inner while loop, position check
                q[c]++; // increment woman row
                if (q[c] == 3) //end of values
                    c--; //backtrack
                else if (ok(q, c)) //check for stability
                    break;
            } 
        } 

return 0;
}

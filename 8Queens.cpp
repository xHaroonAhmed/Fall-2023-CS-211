#include <cmath>
#include <iostream>
using namespace std;

int counter=1;//solutions counter
bool ok(int q[], int c){
    for (int i = 0; i < c; i++) {
        if ((q[i] == q[c])||((c-i) == abs(q[c]-q[i])))//up+down+row test
            return false; 
    }
    return true; 
}

void print(int q[]){
    //print out solutions
    cout<<"Solution: "<<counter<<endl;
    for (int r = 0; r < 8; r++){
        for (int c = 0; c < 8; c++){
            if (q[r] == c) cout<<"X";
            else cout<<"O";
        }
        cout << endl;
    }
    counter++;
}

int main(){
    int q[8]{0}, c = 0;//board set-up
    q[0] = 0;

        while(c>=0){
            c++; // increment column
            if (c==8){//found a solution
                print(q);//print functions
                c--; 
            } else
                q[c] = -1; 
            while (c>=0) { //inner while loop, position check
                q[c]++; // increment row
                if (q[c] == 8)
                    c--; 
                else if (ok(q, c)) 
                    break; 
            }
        }
        
return 0;
}

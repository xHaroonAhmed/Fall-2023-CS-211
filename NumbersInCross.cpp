#include<iostream>
#include<cmath>
using namespace std;

bool ok(int cross[], int x) {
    static int helper[8][5]={
		{-1},
		{0,-1},
		{0,-1},
		{0,1,2,-1},
		{0,1,3,-1},
		{1,4,-1},
		{2,3,4,-1},
		{3,4,5,6,-1},
	};
	
	//row test
    for(int c=0;c<x;c++){
        if(cross[c]==cross[x]) return false;
    }
    
    int i=0;
    while(helper[x][i]!=-1){
        if(abs(cross[x]-cross[helper[x][i]])==1) return false;
        i++;
    }
    return true;
}


void print(int cross[]) {
	static int count = 0;
	cout << "Solution number: " << ++count << endl;
	cout << " " << cross[0] << cross[1] << endl;
	cout << cross[2] << cross[3] << cross[4] << cross[5] << endl;
	cout << " " << cross[6] << cross[7] << endl;
	return;
}

int main() {
	int crossArr[8]{0};//set up cross as a 1=D array
    
    crossArr[0] = 1;
    int column=0;
    while (column>=0){  // outer while loop, position check
        column++;    // increment the column. 
        if (column==8) // position check 
        {
            print(crossArr); 
            column--; 
        } else
        crossArr[column] = 0; 
        while (column>=0)  // inner while loop, position check
        {
            crossArr[column]++; // increment the 'row' 
            if (crossArr[column] > 8)  // position check
            {
                column--; 
                } else if (ok(crossArr,column)) { 
            break; 
            }
        } // inner loop
    } // outer loop

return 0; 
} 

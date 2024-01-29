#include <iostream>
using namespace std;
int main()
{
   
    for(int i=0;i>=0;i++){
        i*i;
        int first, second;
        first=((i*i)%10);
        second=((i*i)%100);
            if((first/2==1)&&(second/2==1)) cout<<i<<endl;
    }

    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    
    int v[4];
    int i;

    for(i = 0; i<4; i++)
        v[i] = i;

    i = 0;
    while(i<4)
    {
        cout<<v[i++]<<endl;
    }
    cout<<(i+=1)<<endl;
    cout<<i<<endl;
}
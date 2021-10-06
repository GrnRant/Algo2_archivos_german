#include <iostream>

using namespace std;

static size_t i = 0;

static int mcCarthy(int n)
{
i++;
//cout<<n<<endl;
if (n > 100)
return n - 10;
else
return mcCarthy(mcCarthy(n + 11));
}

int main()
{
    cout<<mcCarthy(50)<<endl;
    cout<<"Llamadas: "<<i<<endl;
}
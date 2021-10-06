#include <iostream>

using namespace std;

double powerD(double num, size_t n);
double power(double num, size_t n);

int main()
{
    cout<<power(12,1000)<<endl;
    //cout<<powerD(12, 1000)<<endl;

}

double powerD(double num, size_t n)
{
    double acum;

    if(n == 0)
        return 1;
    else if(n == 1)
        return num;
    acum = powerD(num, n/2);
    acum *= acum;
    if(n&1)
        acum *= num;
    return acum;
}

double power(double num, size_t n)
{
    if(n == 0)
        return 1;
    else if(n == 1)
        return num;
    return power(num, n - 1)*num;
}
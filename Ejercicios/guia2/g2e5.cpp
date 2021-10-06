#include <iostream>
#include <cstdlib>

using namespace std;

int det(int *[], size_t);
int **delete_col(int *[], const size_t &, int);
int get_signo(int);
void printMatrix(int **, size_t size);

int main()
{
    int p[4][4] = {{2, 3 , 4, 5},
                  {1, 2, 3, 5},
                  {6, 4, 7, 7},
                  {8, 9, 10, 11}
                };
    int **m = new int *[4];
    for(int i = 0; i<4; i++)
        m[i] = new int[4];

    for(int i = 0; i<4; i++)
        for(int j = 0; j<4; j++)
            m[i][j] = p[i][j];

    //printMatrix(m, 3);
    cout<<det(m, 4)<<endl;
}

int **delete_col(int *orig[], const size_t &size, size_t col)
{
    int **aux;
    size_t l, j, k, i;

    aux = new int*[size - 1];
    for(i = 0; i<(size - 1); i++)
        aux[i] = new int[size - 1];

    for(i = 1, l = 0; i<size; i++, l++)
    {   
        for(j = 0, k = 0; j<(size - 1); j++, k++)
        {
            if(j == col)
                j++;
            aux[l][k] = orig[i][j];
        }
        if(col != (size - 1))
            aux[l][k] = orig[i][j];
    }
    //printMatrix(aux, size - 1);
    return aux;
}

int get_signo(int pow)
{
    if(pow & 1)
        return -1;
    return 1;
}

int det(int *m[], size_t size)
{
    int acul = 0;
    int **aux = NULL;

    if(size == 1)
        return m[0][0];
    for(size_t k = 0; k < size; k++)
    {
        aux = delete_col(m, size, k);
        acul += get_signo(k)*m[0][k]*det(aux, size - 1);
        //cout<<"Acul: "<<acul<<endl;
    }
    return acul;
}

void printMatrix(int **m, size_t size)
{
    for(size_t i = 0; i<size; i++)
    {
        for(size_t j = 0; j<(size - 1); j++)
            cout<<m[i][j]<<'\t';
        cout<<m[i][size - 1]<<endl;
    }
}
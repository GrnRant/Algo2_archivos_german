#include <iostream>
#include <string>
#include "stack.h"

char str_open[] = {'{', '(', '['};
char str_close[] = {'}', ')', ']'};

bool is_balanced(const string &str);
bool is_open(char c);
bool is_close(char c);

int main()
{
        string str;

        cin>>str;
        if(is_balanced(str))
            cout<<"Balanceada"<<endl;
        else
            cout<<"No balanceada"<<endl;
}

bool is_balanced(const string &str)
{
    stack <char> p;
    size_t i = 0;

    while(str[i])
    {
        for(; is_open(str[i]) == true; i++)
            p.push(str[i]);
        if(is_close(str[i]) == false)
            return false;
        for(; is_close(str[i]) == true; i++)
        {
            if(str[i] == '}')
            {
                if(p.pull() != '{')
                    return false;
            }
            else if(str[i] == ']')
            {
                if(p.pull() != '[')
                    return false;
            }
            else if(str[i] == ')')
            {
                if(p.pull() != '(')
                    return false;
            }
        }
    }
    return true;
}

bool is_open(char c)
{
    if(c == '{' || c == '[' || c == '(')
        return true;
    return false;
}

bool is_close(char c)
{
    if(c == '}' || c == ']' || c == ')')
        return true;
    return false;
}
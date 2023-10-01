#include <iostream>
using namespace std;
char to_lowercase(char ch)
{

    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {

        return ch;
    }

    else
    {

        return ch - 'A' + 'a';
    }
}
int main()
{
    char a;
    cout << "Enter char :"
         << " ";
    cin >> a;
    char re = to_lowercase(a);
    cout << re;
    return 0;
}
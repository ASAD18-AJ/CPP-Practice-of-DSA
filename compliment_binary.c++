#include <iostream>
using namespace std;

class binary
{
    string s;
    void chk_bin(void);

public:
    void read(void);

    void ones_compl(void);
    void display(void);
};
void binary ::read(void)
{
    cout << "Enter a binary no. " << endl;
    cin >> s;
}

void binary ::chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect binary format" << endl;
            exit(0);
        }
    }
}

void binary::ones_compl(void)
{
    chk_bin();
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
        else
        {
            s.at(i) = '0';
        }
    }
}

void binary ::display(void)
{
    cout << "Displaying your binary number" << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout << endl;
}

int main()
{

    binary b;
    b.read();

    b.display();
    b.ones_compl();
    b.display();
    return 0;
}
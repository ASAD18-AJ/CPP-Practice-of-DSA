#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char key[] = "mango";
    char buffer[20];
    do
    {
        cout << "what is my favourite fruit?";
        cin >> buffer;
    } while (strcmp(key, buffer) != 0);

    cout << "Answer is corr!!" << endl;

    return 0;
}
#include <iostream>
using namespace std;
bool ReachHome(int s, int e)
{
    if (s == e)
    {
        cout << "aagaya";
        return true;
    }
    s++;
    ReachHome(s, e);
}
int main()
{
    int s = 0;
    int e = 5;
    ReachHome(s, e);
}
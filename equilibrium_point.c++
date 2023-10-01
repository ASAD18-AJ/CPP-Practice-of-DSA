#include <iostream>
using namespace std;
class Solution
{
public:
    int equilp(long long a[], int n)
    {
        long long int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }
        long long int lsum = 0;
        long long int rsum = sum;
        for (int i = 0; i < n; i++)
        {
            rsum -= a[i];
            if (lsum == rsum)
                return i + 1;
            lsum += a[i];
        }
    }
};
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    long long a[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Solution solution;
    int equilibriumPoint = solution.equilp(a, n);

    if (equilibriumPoint != -1)
    {
        cout << "The equilibrium point is at index " << equilibriumPoint << endl;
    }
    else
    {
        cout << "There is no equilibrium point in the given array." << endl;
    }

    return 0;
}
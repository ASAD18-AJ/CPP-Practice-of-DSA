#include <iostream>
using namespace std;

void bubble_sort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    bubble_sort(A, n);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}
// void bubble_sort(int A[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n - 1 - i; j++)
//         {
//             if (A[j] > A[j + 1])
//             {
//                 int temp = A[j];
//                 A[j] = A[j + 1];
//                 A[j + 1] = temp;
//             }
//         }
//     }
// }
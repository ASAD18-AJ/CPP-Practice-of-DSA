#include <iostream>
using namespace std;
void print(int arr[], int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool binarySearch(int arr[], int s, int e, int k)
{
    cout << endl;
    print(arr, s, e);
    if (s > e)
        return false;
    int mid = (s + e) / 2;
    if (arr[mid] == k)
        return true;
    if (arr[mid] < k)
    {
        return binarySearch(arr, mid + 1, e, k);
    }
    else
    {
        return binarySearch(arr, s, mid - 1, k);
    }
}
int main()
{
    int arr[7] = {3, 5, 2, 1, 8, 54, 32};
    int size = 7;
    int key = 8;
    cout << "presnt or not " << binarySearch(arr, 0, size - 1, key) << endl;
}
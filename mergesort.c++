#include <stdio.h>
void merge(int arr[], int l, int m, int r)
{
  // Your code here
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];
  int i, j, k;
  for (i = 0; i < n1; i++)
  {
    L[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++)
  {
    R[j] = arr[m + 1 + j];
  }
  L[i] = 99999;
  R[j] = 99999;
  i = 0;
  j = 0;
  for (k = l; k <= r; k++)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
  }
}
void mergeSort(int arr[], int l, int r)
{
  // code here
  int m;
  if (l < r)
  {
    m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}
int main()
{
  int n;
  printf("Enter the length of array: ");
  scanf("%d", &n);
  int i, A[n];
  printf("Enter the element for the array: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  int l = 0, r = n - 1;
  mergeSort(A, l, r);
  for (i = 0; i < n; i++)
  {
    printf("%d", A[i]);
    printf("\n");
  }
  return 0;
}

// class Solution
// {
// public:
//     void merge(int arr[], int l, int mid, int r)
//     {
//         int i = 0;
//         int temp[r - l + 1];
//         int left = l;
//         int right = mid + 1;
//         while (left <= mid && right <= r)
//         {
//             if (arr[left] <= arr[right])
//                 temp[i++] = arr[left++];
//             else
//                 temp[i++] = arr[right++];
//         }
//         while (left <= mid)
//         {
//             temp[i++] = arr[left++];
//         }
//         while (right <= r)
//         {
//             temp[i++] = arr[right++];
//         }
//         for (int j = l; j <= r; j++)
//         {
//             arr[j] = temp[j - l];
//         }
//     }

// public:
//     void mergeSort(int arr[], int l, int r)
//     {
//         // code here
//         if (r > l)
//         {
//             int m = l + (r - l) / 2;

//             mergeSort(arr, l, m);

//             mergeSort(arr, m + 1, r);

//             merge(arr, l, m, r);
//         }
//     }
// };

// //{ Driver Code Starts.

// int main()
// {
//     int n, T, i;

//     scanf("%d", &T);

//     while (T--)
//     {

//         scanf("%d", &n);
//         int arr[n + 1];
//         for (i = 0; i < n; i++)
//             scanf("%d", &arr[i]);

//         Solution ob;
//         ob.mergeSort(arr, 0, n - 1);
//         printArray(arr, n);
//     }
//     return 0;
// }
// // } Driver Code
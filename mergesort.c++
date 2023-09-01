#include <stdio.h>
void Merge(int A[], int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[10], R[10];
  int i, j, k;
  for (i = 0; i < n1; i++)
  {
    L[i] = A[p + i];
  }
  for (j = 0; j < n2; j++)
  {
    R[j] = A[q + j + 1];
  }
  L[i] = 9999;
  R[j] = 9999;
  i = 0;
  j = 0;
  for (k = p; k < r; k++)
  {

    if (L[i] < R[j])
    {
      A[k] = L[i];
      i++;
    }
    else
    {
      A[k] = L[j];
      j++;
    }
  }
}
void Merge_sort(int A[], int p, int r)
{
  int q;
  if (p < r)
  {
    q = (p + r) / 2;
    Merge_sort(A, p, q);
    Merge_sort(A, q + 1, r);
    Merge(A, p, q, r);
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
  int p = 0, r = n - 1;
  Merge_sort(A, p, r);
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
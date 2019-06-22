#include <bits/stdc++.h>

using namespace std;

void Merge(int arr[], int l, int mid, int h)
{

    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = h - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
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
        k++;
    }

    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int h)
{

    if (l < h)
    {

        int mid = (l + h) / 2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, h);
        Merge(arr, l, mid, h);
    }
}

int main()
{

    int arr[] = {3, 4, 6, 1, 2, 90, 86, 45};
    int l = 0;
    int high = 7;
    cout << "Before Sorting " << endl;
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    MergeSort(arr, l, high);

    cout << "After Sorting " << endl;
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}
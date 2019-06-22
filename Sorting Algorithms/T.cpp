#include <bits/stdc++.h>
using namespace std;
int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int mid = (0 + 5) / 2;
    vector<int> left(arr, arr + mid);
    vector<int> right(arr + mid, arr + 5);
    for (int x : left)
        cout << x << " ";
    cout << endl;
    for (int x : right)
        cout << x << " ";

    return 0;
}
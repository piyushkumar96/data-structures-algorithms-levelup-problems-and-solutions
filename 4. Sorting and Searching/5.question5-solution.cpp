#include <iostream>
#include <vector>

using namespace std;

void insertionSortRec(vector<int>& arr, int n)
{
    if (n <= 1)
        return;
    insertionSortRec(arr, n-1);

    int lastEle = arr[n-1];
    int j = n -2;
    while(j>=0 && arr[j] > lastEle) {
            arr[j+1] = arr[j];
            j--;
    }
    arr[j+1] = lastEle;
}

int main()
{
    vector<int> arr { 6, 3, 7, 1, 5, 8, 9, 2, 5 };

    insertionSortRec(arr, arr.size());

    cout << "The sorted array is ";
    for (auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
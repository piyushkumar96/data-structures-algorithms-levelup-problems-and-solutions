#include <iostream>
#include <vector>

using namespace std;

void bubbleSortRec(vector<int>& arr, int n)
{
    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

    bubbleSortRec(arr, n - 1);
}

int main()
{
    vector<int> arr { 6, 3, 7, 1, 5, 8, 9, 2, 5 };

    bubbleSortRec(arr, arr.size());

    cout << "The sorted array is ";
    for (auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
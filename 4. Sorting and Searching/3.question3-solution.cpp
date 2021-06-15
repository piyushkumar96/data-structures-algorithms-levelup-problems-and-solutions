#include <climits>
#include <iostream>
#include <vector>

using namespace std;

vector<int> selectionSort(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int min_index = i;
        int j = i + 1;
        while (j < n) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
            j++;
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    return arr;
}

int main()
{
    vector<int> arr { 6, 3, 7, 1, 5, 8, 9, 2, 5 };

    vector<int> res = selectionSort(arr);

    cout << "The sorted array is ";
    for (auto ele : res) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
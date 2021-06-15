#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int> arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j=i-1;
        while(j>=0 && arr[j] > temp) {

            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    return arr;
}

int main()
{
    vector<int> arr { 6, 3, 7, 1, 5, 8, 9, 2, 5 };

    vector<int> res = insertionSort(arr);

    cout << "The sorted array is ";
    for (auto ele : res) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
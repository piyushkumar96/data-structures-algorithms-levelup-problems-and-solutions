#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int start, int last)
{
    int pivot = arr[start];
    int i = start;

    for (int j = start + 1; j <= last; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[start]);

    return (i);
}

void quickSort(vector<int>& arr, int start, int last)
{
    if (last <= start)
        return;
    else {
        int partKey = partition(arr, start, last);
        quickSort(arr, start, partKey - 1);
        quickSort(arr, partKey + 1, last);
    }
}

int main()
{
    vector<int> arr { 6, 3, 7, 1, 5, 8, 9, 2, 5 };

    quickSort(arr, 0, arr.size() - 1);

    cout << "The sorted array is ";
    for (auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
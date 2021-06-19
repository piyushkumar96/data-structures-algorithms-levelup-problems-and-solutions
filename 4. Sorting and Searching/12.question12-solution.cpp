#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);

        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int main()
{
    vector<int> arr { 6, 3, 7, 1, 5, 8, 9, 2, 5 };

    heapSort(arr);

    cout << "The sorted array is ";
    for (auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
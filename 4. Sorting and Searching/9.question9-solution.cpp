#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int>& arr, int start, int mid, int last)
{
    int tempArr[start + last];
    int k = 0;
    int i = start, j = mid + 1;
    while (i <= mid && j <= last) {
        if (arr[i] <= arr[j]) {
            tempArr[k] = arr[i];
            i++;
        } else {
            tempArr[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        tempArr[k] = arr[i];
        i++;
        k++;
    }

    while (j <= last) {
        tempArr[k] = arr[j];
        j++;
        k++;
    }

    k = 0;
    for (int i = start; i <= last; i++) {
        arr[i] = tempArr[k++];
    }
}
void mergeSortIterative(vector<int>& arr, int start, int last)
{
    if (last <= start)
        return;
    else {
        // divide the array into blocks of size `i`
        // i = [1, 2, 4, 8, 16…]
        for (int i = 1; i <= (last - start); i = 2 * i) {
            // for i = 1, j = 0, 2, 4, 6, 8…
            // for i = 2, j = 0, 4, 8…
            // for i = 4, j = 0, 8…
            for (int j = start; j <= last; j += 2 * i) {
                int from = j;
                int mid = j + i - 1;
                int to = min(j + 2 * i - 1, last);

                merge(arr, from, mid, to);
            }
        }
    }
}

int main()
{
    vector<int> arr { 6, 3, 7, 1, 5, 8, 9, 2, 5 };

    mergeSortIterative(arr, 0, arr.size() - 1);

    cout << "The sorted array is ";
    for (auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
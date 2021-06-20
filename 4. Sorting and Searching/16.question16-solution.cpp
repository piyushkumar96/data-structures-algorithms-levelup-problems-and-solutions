#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& arr, int s, int m, int l)
{
    int i = s;
    int j = m + 1;
    int invCount = 0;
    vector<int> temp(l - s + 1);
    int k = 0;
    while (i <= m && j <= l) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount = invCount + m - i + 1;
        }
    }

    while (i <= m) {
        temp[k++] = arr[i++];
    }
    while (j <= l) {
        temp[k++] = arr[j++];
    }
    k = 0;
    for (int i = s; i <= l; i++) {
        arr[i] = temp[k++];
    }

    return invCount;
}

int mergeSort(vector<int>& arr, int start, int last)
{
    int invCount = 0;
    if (start >= last)
        return 0;
    else {
        int mid = (start + last) / 2;

        /* Inversion count will be sum of
           inversions in left-part, right-part
           and number of inversions in merging
        */
        invCount += mergeSort(arr, start, mid);
        invCount += mergeSort(arr, mid + 1, last);
        invCount += merge(arr, start, mid, last);
    }

    return invCount;
}

int inversionCount(vector<int>& arr, int start, int last)
{
    return mergeSort(arr, start, last);
}

int main()
{
    vector<int> arr { 0, 5, 2, 3, 1, 1 };

    int res = inversionCount(arr, 0, arr.size() - 1);

    cout << "The number of inversion count is " << res << endl;
    return 0;
}
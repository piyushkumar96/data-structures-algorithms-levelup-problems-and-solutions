#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int s, int l)
{
    int pivot = arr[l];
    int i = s - 1;
    for (int j = s; j < l; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[l]);

    return i + 1;
}

int quickSelectKthSmallestEle(vector<int>& arr, int start, int last, int k)
{

    int partIndex = partition(arr, start, last);
    if (partIndex == k) {
        return arr[partIndex];
    } else if (partIndex > k) {
        return quickSelectKthSmallestEle(arr, start, partIndex - 1, k);

    } else {
        return quickSelectKthSmallestEle(arr, partIndex + 1, last, k);
    }
}

int main()
{

    vector<int> arr { 1, 0, 6, 7, 2, 4, 5, 3 };
    int k = 4;

    int res = quickSelectKthSmallestEle(arr, 0, arr.size() - 1, k - 1);
    cout << "The " << k << "th smallest number is " << res << endl;
    return 0;
}
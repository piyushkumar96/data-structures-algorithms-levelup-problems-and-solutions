#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void countSort(vector<int>& arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());

    int range = max - min + 1;
    vector<int> count(range);
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i <= range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr)
{
    int max = *max_element(arr.begin(), arr.end());

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}
int main()
{
    vector<int> arr { 170, 45, 75, 90, 802, 24, 2, 66 };

    radixSort(arr);

    cout << "The sorted array is ";
    for (auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
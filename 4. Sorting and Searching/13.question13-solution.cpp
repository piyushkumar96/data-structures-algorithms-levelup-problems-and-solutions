#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void countSort(vector<int>& arr)
{
    int n = arr.size();
    vector<int> output(n);
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());

    int range = max - min + 1;
    vector<int> count(range);
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main()
{
    vector<int> arr { 1, 4, 1, 2, 7, 5, 2 };

    countSort(arr);

    cout << "The sorted array is ";
    for (auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
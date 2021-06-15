#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> arr)
{
    int n = arr.size();
    int flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;
            }
        }
        if (flag == false)
            break;
    }

    return arr;
}

int main()
{
    vector<int> arr { 6, 3, 7, 1, 5, 8, 9, 2, 5 };

    vector<int> res = bubbleSort(arr);

    cout << "The sorted array is ";
    for (auto ele : res) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr)
{

    int n = arr.size();
    vector<int> output(n, 1);

    vector<int> left(n, 1);
    for (int i = 1; i < n; i++) {
        left[i] = arr[i - 1] * left[i - 1];
    }

    vector<int> right(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        right[i] = right[i + 1] * arr[i + 1];
    }

    for (int i = 0; i < n; i++) {
        output[i] = left[i] * right[i];
    }

    return output;
}

int main()
{
    vector<int> v { 1, 2, 3, 4, 5 };

    vector<int> output = productArray(v);

    cout << "The product array is ";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}
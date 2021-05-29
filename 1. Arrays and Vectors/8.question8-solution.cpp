#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> arr)
{
    int n = arr.size();
    int sum(0), maxSum(0);

    for (int i = 0; i < n; i++) {
        if (sum + arr[i] < 0) {
            sum = 0;
            continue;
        }
        sum = sum + arr[i];
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main()
{
    vector<int> arr { -1, 2, 3, 4, -2, 6, -8, 3 };

    int maxSum = maxSubarraySum(arr);
    cout << "The max subarray sum is " << maxSum << endl;

    return 0;
}
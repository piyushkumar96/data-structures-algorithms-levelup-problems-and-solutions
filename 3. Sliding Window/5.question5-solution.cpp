#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int cntSubarrays(vector<int> arr, int k)
{
    int currSum = 0;
    unordered_map<int, int> prevSum;
    int res = 0;

    for (int i = 0; i < arr.size(); i++) {
        currSum += arr[i];

        if (currSum == k)
            res++;

        if (prevSum.find(currSum - k) != prevSum.end()) {
            res += prevSum[currSum - k];
        }

        prevSum[currSum]++;
    }

    return res;
}

int main()
{
    vector<int> input { 10, 2, -2, -20, 10 };
    int k = -10;

    int res = cntSubarrays(input, k);

    cout << "The number of sub array with given sum i.e. " << k << " is " << res << endl;
    return 0;
}
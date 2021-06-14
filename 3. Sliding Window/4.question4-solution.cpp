#include <climits>
#include <iostream>
#include <vector>

using namespace std;

vector<int> maxInWindow(vector<int> input, int k)
{
    if (k <= 1) {
        return input;
    }
    int n = input.size();
    vector<int> result;
    int i = 0, j = k, l = i;
    int max = INT_MIN;
    while (j <= n) {
        if (input[i] > max) {
            max = input[i];
        }
        i++;
        if (i == j) {
            result.push_back(max);
            l++;
            max = input[l];
            i = l;
            j++;
        }
    }
    return result;
}

int main()
{
    vector<int> input { 1, 2, 3, 1, 4, 5, 2, 3, 6 };
    int k = 3;

    vector<int> res = maxInWindow(input, k);
    for (auto v : res) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
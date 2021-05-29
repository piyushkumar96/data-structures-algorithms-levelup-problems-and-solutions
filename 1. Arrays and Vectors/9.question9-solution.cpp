#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> minDifference(vector<int> a, vector<int> b)
{
    int asize = a.size();
    int bsize = b.size();

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    pair<int, int> pa;
    int minDiff(INT_MAX), i(0), j(0);
    while (i < asize && j < bsize) {
        if (minDiff >= abs(a[i] - b[j])) {
            minDiff = abs(a[i] - b[j]);
            if (a[i] <= b[i]) {
                pa.first = a[i];
                pa.second = b[j];
            } else {
                pa.first = b[j];
                pa.second = a[i];
            }
        }
        if (a[i] >= b[j]) {
            j++;
        } else {
            i++;
        }
    }

    return pa;
}

int main()
{
    vector<int> a { 23, 5, 10, 17, 30 };
    vector<int> b { 26, 134, 135, 14, 19 };

    pair<int, int> minDiffEle = minDifference(a, b);
    cout << "The minimum  difference pair is [" << minDiffEle.first << "," << minDiffEle.second << "]" << endl;
    return 0;
}
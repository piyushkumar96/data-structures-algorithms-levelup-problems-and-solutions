#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> subArraySum(vector<int> v, int k)
{
    int i(0), j(0), sum(0);
    int n = v.size();
    vector<pair<int, int>> vpa;
    while (i < n) {
        sum = sum + v[i];
        while (j < i && sum > k) {
            sum = sum - v[j];
            j++;
        }
        if (k == sum) {
            vpa.push_back({ j, i });
        }
        i++;
    }

    return vpa;
}

int main()
{
    vector<int> v { 1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 1 };
    int k = 8;

    vector<pair<int, int>> vpa = subArraySum(v, k);
    for (auto pa : vpa) {
        cout << "The sub array with sum " << k << " is [" << pa.first << "," << pa.second << "]" << endl;
    }

    return 0;
}
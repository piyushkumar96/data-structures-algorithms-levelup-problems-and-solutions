#include <climits>
#include <iostream>
#include <vector>

using namespace std;

vector<int> subArraySort(vector<int> v)
{
    int vsize = v.size();
    vector<int> result(2, -1);
    int smallest = INT_MAX;
    int largest = INT_MIN;
    for (int i = 1; i < vsize - 1; i++) {
        if ((v[i - 1] < v[i] && v[i] > v[i + 1]) || (v[i - 1] > v[i] && v[i] < v[i + 1])) {
            smallest = min(smallest, v[i]);
            largest = max(largest, v[i]);
        }
    }
    for (int i = 0; i < vsize; i++) {
        if (v[i] > smallest) {
            result[0] = i;
            break;
        }
    }

    for (int i = vsize - 1; i > 0; i--) {
        if (v[i] < largest) {
            result[1] = i;
            break;
        }
    }

    return result;
}

int main()
{
    vector<int> v { 1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11 };

    vector<int> result = subArraySort(v);
    cout << "The subarray is [" << result[0] << "," << result[1] << "]" << endl;

    return 0;
}
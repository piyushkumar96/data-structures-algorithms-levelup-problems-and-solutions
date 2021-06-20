#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmpFunc(const string x, const string y)
{

    return (x + y <= y + x);
}

void smallestString(vector<string>& arr)
{
    sort(arr.begin(), arr.end(), cmpFunc);
}

int main()
{

    vector<string> arr { "abb", "a", "aaa", "bsbalj", "c" };

    smallestString(arr);
    cout << "The smallest string is ";
    for (auto ele : arr) {
        cout << ele;
    }
    cout << endl;
    return 0;
}
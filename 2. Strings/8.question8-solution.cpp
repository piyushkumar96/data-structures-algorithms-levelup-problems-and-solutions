#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool comparatorFunc(const int& a, const int& b)
{
    string s1 = to_string(a).append(to_string(b));
    string s2 = to_string(b).append(to_string(a));

    return (s1 > s2) ? 1 : 0;
}

string BiggestNumberString(vector<int> numbers)
{
    string str = "";
    sort(numbers.begin(), numbers.end(), comparatorFunc);
    for (auto item : numbers) {
        str = str + to_string(item);
    }

    return str;
}

int main()
{
    vector<int> nums { 54, 546, 548, 60 };

    string result = BiggestNumberString(nums);
    cout << "The maximum number is " << result << endl;

    return 0;
}

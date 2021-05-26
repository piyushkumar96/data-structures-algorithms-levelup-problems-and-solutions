#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int longestBand(vector<int> v)
{
    unordered_set<int> s;
    for (int ele : v) {
        s.insert(ele);
    }

    int longestLen = 1;
    for (auto ele : s) {
        int parent = ele - 1;
        if (s.find(parent) == s.end()) {
            int count = 1;
            int next_no = ele + 1;
            while (s.find(next_no) != s.end()) {
                count++;
                next_no++;
            }

            if (count > longestLen) {
                longestLen = count;
            }
        }
    }

    return longestLen;
}

int main()
{
    vector<int> v { 1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6 };

    int result = longestBand(v);
    cout << "The longest band for consecutive sequence is " << result << endl;

    return 0;
}
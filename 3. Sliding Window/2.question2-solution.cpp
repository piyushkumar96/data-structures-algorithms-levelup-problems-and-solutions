#include <iostream>
#include <unordered_map>

using namespace std;

string uniqueSubString(string str)
{
    unordered_map<char, int> mp;
    int currStart(0), start, maxlen(0), i(0);
    for (; i < str.length(); i++) {
        if (mp.find(str[i]) == mp.end()) {
            mp[str[i]] = i;
        } else {
            if (mp[str[i]] >= currStart) {
                if (maxlen < (i - currStart)) {
                    maxlen = (i - currStart);
                    start = currStart;
                }
                currStart = mp[str[i]] + 1;
            }
            mp[str[i]] = i;
        }
    }
    if (maxlen < (i - currStart)) {
        maxlen = (i - currStart);
        start = currStart;
    }
    string outStr = str.substr(start, maxlen);

    return outStr;
}
int main()
{
    string str;
    cin >> str;

    string result = uniqueSubString(str);
    cout << "The longest unique sub string: " << result << endl;

    return 0;
}
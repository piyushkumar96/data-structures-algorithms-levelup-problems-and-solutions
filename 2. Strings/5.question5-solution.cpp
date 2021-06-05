#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

bool numericCmptr(const pair<string, string>& s1, const pair<string, string>& s2)
{
    return stoi(s1.second) > stoi(s2.second);
}

bool lexicalCmptr(const pair<string, string>& s1, const pair<string, string>& s2)
{
    return s1.second > s2.second;
}

string getStringAtKey(string s, int key)
{
    char* token = strtok((char*)s.c_str(), " ");

    while (key > 1) {
        token = strtok(NULL, " ");
        key--;
    }

    return (string)token;
}

int main()
{
    int t;
    cin >> t;

    cin.get(); // to consume the enter \n

    vector<string> strList;

    for (int i = 0; i < t; i++) {
        string str;
        getline(cin, str);
        strList.push_back(str);
    }

    int key;
    string reversal, cmpType;
    cin >> key >> reversal >> cmpType;

    vector<pair<string, string>> strKeyList;
    for (int i = 0; i < t; i++) {
        string temp = getStringAtKey(strList[i], key);
        strKeyList.push_back(make_pair(strList[i], temp));
    }

    if (cmpType == "numeric") {
        sort(strKeyList.begin(), strKeyList.end(), numericCmptr);
    } else {
        sort(strKeyList.begin(), strKeyList.end(), lexicalCmptr);
    }

    if (reversal == "false") {
        reverse(strKeyList.begin(), strKeyList.end());
    }

    cout << "The resultant string list order is " << endl;
    for (int i = 0; i < t; i++) {
        cout << strKeyList[i].first << endl;
    }

    return 0;
}

#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> tokenizeString(string str)
{
    vector<string> resStr;
    int strLen = str.size();
    stringstream ss(str);

    string word;
    while (getline(ss, word, ' ')) {
        resStr.push_back(word);
    }

    return resStr;
}

int main()
{
    string str = "My name is Piyush Kumar";

    vector<string> res = tokenizeString(str);
    for (auto str : res) {
        cout << str << ",";
    }
    cout << endl;

    return 0;
}
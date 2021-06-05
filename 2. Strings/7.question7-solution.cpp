#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void getAllSubSequence(string inpStr, string outStr, vector<string>& subSeqs)
{
    if (inpStr.empty()) {
        subSeqs.push_back(outStr);
        return;
    }

    // including first char
    getAllSubSequence(inpStr.substr(1), outStr + inpStr[0], subSeqs);

    // excluding first char
    getAllSubSequence(inpStr.substr(1), outStr, subSeqs);
}

bool comparator(string s1, string s2)
{
    if (s1.length() == s2.length()) {
        return s1 < s2;
    }

    return s1.length() < s2.length();
}

int main()
{
    string inpStr;
    cin >> inpStr;

    string outStr = "";
    vector<string> subSeqs;

    getAllSubSequence(inpStr, outStr, subSeqs);

    sort(subSeqs.begin(), subSeqs.end(), comparator);

    for (int i = 0; i < subSeqs.size(); i++) {
        cout << subSeqs[i] << ", ";
    }
    cout << endl;

    return 0;
}
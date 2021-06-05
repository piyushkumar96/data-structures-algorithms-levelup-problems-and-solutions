#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<string> tokenizeString(char* arr)
{
    vector<string> res;
    char* token = strtok(arr, " ");
    while (token != NULL) {
        res.push_back(string(token));
        token = strtok(NULL, " ");
    }

    return res;
}

int main()
{
    string str = "My name is Piyush Kumar";
    int strLen = str.length();

    char arr[strLen + 1];
    strcpy(arr, str.c_str());

    vector<string> res = tokenizeString(arr);

    for (auto str : res) {
        cout << str << ",";
    }
    cout << endl;

    return 0;
}
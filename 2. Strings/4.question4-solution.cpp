#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

char* myStrTok(char* str, char delim)
{
    static char* input = NULL;
    if (str != NULL) {
        input = str;
    }

    if (input == NULL) {
        return NULL;
    }

    char* token = new char[strlen(input) + 1];
    int i = 0;

    for (; input[i] != '\0'; i++) {
        if (input[i] != delim) {
            token[i] = input[i];
        } else {
            token[i] = '\0';
            input = input + i + 1;
            return token;
        }
    }

    token[i] = '\0';

    // when the whole string is processed
    input = NULL;

    return token;
}

vector<string> tokenizeString(char* arr)
{
    vector<string> res;
    char* token = myStrTok(arr, ' ');
    while (token != NULL) {
        res.push_back(string(token));
        token = myStrTok(NULL, ' ');
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
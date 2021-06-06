#include <iostream>

using namespace std;

string compressString(const string& str)
{
    string resStr = "";
    bool flag = false;
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != str[i + 1]) {
            count++;
            resStr = resStr + str[i] + to_string(count);
            count = 0;
        } else {
            flag = true;
            count++;
        }
    }

    return flag ? resStr : str;
}

int main()
{
    string str;
    cin >> str;

    string runEncodedString = compressString(str);
    cout << "The compressed string is " << runEncodedString << endl;

    return 0;
}
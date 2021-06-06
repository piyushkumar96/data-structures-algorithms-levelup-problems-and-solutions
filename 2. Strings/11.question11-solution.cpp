#include <iostream>

using namespace std;

string normalize(const string& sentence)
{
    string copy = sentence;

    for (int i = 0; i < copy.length(); i++) {
        if ((i == 0 && copy[i] != ' ') || (copy[i - 1] == ' ' && copy[i] != ' ')) {
            if ((copy[i] >= 'a') && (copy[i] <= 'z'))
                copy[i] = (char)(copy[i] - 'a' + 'A');
        } else if ((copy[i] >= 'A') && (copy[i] <= 'Z')) {
            copy[i] = (char)(copy[i] + 'a' - 'A');
        }
    }

    return copy;
}

int main()
{
    string str = "Make the chanGEs in copy,  and reTUrn it";

    string result = normalize(str);
    cout << "The resultant normalize string: " << result << endl;

    return 0;
}
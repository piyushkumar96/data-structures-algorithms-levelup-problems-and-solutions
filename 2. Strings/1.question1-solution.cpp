#include <cstring>
#include <iostream>

using namespace std;

void replaceSpaces(char* str)
{
    int spaces = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            spaces = spaces + 1;
        }
    }

    int index = strlen(str) + 2 * spaces;
    str[index] = '\0';

    for (int i = strlen(str) - 1; i >= 0; i--) {

        if (str[i] == ' ') {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index = index - 3;
        } else {
            str[index - 1] = str[i];
            index--;
        }
    }
}

int main()
{
    char inputStr[100000];
    cin.getline(inputStr, 10000);

    replaceSpaces(inputStr);
    cout << "The resultant string is " << inputStr << endl;

    return 0;
}

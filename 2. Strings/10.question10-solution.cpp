#include <iostream>

using namespace std;

string breakPalindrome(string palindrome)
{
    int n = palindrome.length();
    for (int i = 0; i < n / 2; i++) {
        if (palindrome[i] != 'a') {
            palindrome[i] = 'a';

            return palindrome;
        }
    }

    palindrome[n - 1] = 'b';
    return n < 2 ? "" : palindrome;
}

int main()
{
    string str;
    cin >> str;

    string result = breakPalindrome(str);
    if (result != "")
        cout << "The new non palindromic string is " << result << endl;
    else
        cout<<"The string cannot modified to non palindrome"<<endl;

    return 0;
}
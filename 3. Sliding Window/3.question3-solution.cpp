#include <climits>
#include <iostream>

using namespace std;

string stringWindow(string str, string pat)
{
    int FCS[256] = { 0 };
    int FCP[256] = { 0 };
    int start = 0, currStart = -1;
    int min_so_far = INT_MAX;
    for (int i = 0; i < pat.length(); i++) {
        FCP[pat[i]]++;
    }

    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        // expanding the window
        FCS[str[i]]++;

        // increase the count if the chars matches
        if (FCP[str[i]] != 0 && FCS[str[i]] <= FCP[str[i]]) {
            count++;
        }

        // when length matches, check for contraction
        if (count == pat.length()) {

            // contracting the window if that char is not there in pattern or if its frequency in string is more than freq in pattern
            while (FCP[str[start]] == 0 || FCS[str[start]] > FCP[str[start]]) {
                FCS[str[start]]--;
                start++;
            }

            // calculating the window size;
            int window_size = i - start + 1;
            if (window_size < min_so_far) {
                min_so_far = window_size;
                currStart = start;
            }
        }
    }

    if (currStart == -1) {
        return "NO WINDOW FOUND";
    }

    return str.substr(currStart, min_so_far);
}

int main()
{
    string bigStr, smallStr;
    cin >> bigStr >> smallStr;

    string result = stringWindow(bigStr, smallStr);
    cout << "The string window containing all chars of pattern is: " << result << endl;

    return 0;
}
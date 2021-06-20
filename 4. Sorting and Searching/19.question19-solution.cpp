#include <iostream>
#include <vector>

using namespace std;

int sparseSearch(vector<string>& arr, int start, int last, string k)
{
    if (start <= last) {

        int mid = (last + start) / 2;
        if (arr[mid] == "") {
            int left_mid = mid - 1;
            int right_mid = mid + 1;
            while (1) {
                if (left_mid < start && right_mid > last) {
                    return -1;
                } else if (right_mid <= last && arr[right_mid] != "") {
                    mid = right_mid;
                    break;
                } else if (left_mid >= start && arr[left_mid] != "") {
                    mid = left_mid;
                    break;
                }

                right_mid++;
                left_mid--;
            }
        }
        if (arr[mid] == k) {
            return mid;
        } else if (arr[mid] > k) {
            return sparseSearch(arr, start, mid - 1, k);
        } else {
            return sparseSearch(arr, mid + 1, last, k);
        }
    }

    return -1;
}

int main()
{
    vector<string> arr { "ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", "e" };
    string k = "bat";

    int index = sparseSearch(arr, 0, arr.size() - 1, k);
    if (index == -1) {
        cout << "The string " << k << " not found in given array" << endl;
    } else {
        cout << "The string " << k << " is found at index " << index + 1 << endl;
    }
    return 0;
}
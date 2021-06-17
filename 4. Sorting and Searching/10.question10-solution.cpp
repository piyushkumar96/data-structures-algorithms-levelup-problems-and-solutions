#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int start, int last)
{
    int pivot = arr[last];
    int i = start - 1;

    for (int j = start; j < last; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[last]);

    return (i + 1);
}

void quickSortIterative(vector<int>& arr, int start, int last)
{
    if (last <= start)
        return;
    else {
        stack<int> st;
        st.push(start);
        st.push(last);

        while (!st.empty()) {
            int l = st.top();
            st.pop();
            int s = st.top();
            st.pop();

            int partKey = partition(arr, s, l);

            // If there are elements on left side of pivot,
            // then push left side to stack
            if ((partKey - 1) > s) {
                st.push(s);
                st.push(partKey - 1);
            }
            // If there are elements on right side of pivot,
            // then push right side to stack
            if ((partKey + 1) < l) {
                st.push(partKey + 1);
                st.push(l);
            }
        }
    }
}

int main()
{
    vector<int> arr { 6, 3, 7, 1, 5, 8, 9, 2, 5 };

    quickSortIterative(arr, 0, arr.size() - 1);

    cout << "The sorted array is ";
    for (auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
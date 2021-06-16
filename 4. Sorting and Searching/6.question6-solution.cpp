#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int>& arr, int start, int mid, int last) {
    int tempArr[start + last];
    int k=0;
    int i = start, j = mid +1 ;
    while(i<= mid && j <= last) {
        if(arr[i] <= arr[j]) {
            tempArr[k] = arr[i];
            i++;
        }else {
            tempArr[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= mid) {
        tempArr[k] = arr[i];
        i++;
        k++;
    }

    while(j <= last) {
        tempArr[k] = arr[j];
        j++;
        k++;
    }

    k=0;
    for(int i=start; i<=last; i++) {
        arr[i] = tempArr[k++];
    }
}
void mergeSort(vector<int>& arr, int start, int last)
{
    if(last <= start)
        return;
    else {
        int mid = (last + start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, last);
        merge(arr, start, mid, last);
    }
}

int main()
{
    vector<int> arr { 6, 3, 7, 1, 5, 8, 9, 2, 5 };

    mergeSort(arr, 0, arr.size() - 1);

    cout << "The sorted array is ";
    for (auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
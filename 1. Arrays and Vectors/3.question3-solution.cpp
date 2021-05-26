#include<iostream>

using namespace std;

int mountainPeak(int arr[], int n) {
    int maxSize = 0;
    for(int i=1; i<n-1; i++) {
        int count = 1;
        if ((arr[i-1] < arr[i]) && (arr[i] > arr[i+1])) {
            int ld = i;
            int rd = i;
            while((ld > 0) && (arr[ld] > arr[ld-1])) {
                ld--;
                count++;

            }
            while((rd < (n-1)) && (arr[rd+1] < arr[rd])) {
                rd++;
                count++;

            }
            i = rd;

        }
        if (maxSize < count) {
             maxSize = count;
        }

    }

    return maxSize;
}

int main() {
    int arr[] = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    int arrLen = *(&arr + 1) - arr;
    int result = mountainPeak(arr, arrLen);

    cout<<"The max peak of mountain is "<<result<<endl;
    return 0;
}
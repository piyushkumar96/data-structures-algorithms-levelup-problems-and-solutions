#include <iostream>
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

int partitionRandom(vector<int>& arr, int start, int last)
{
    srand(time(NULL));
    int random = start + rand() % (last - start);

    swap(arr[random], arr[last]);

    return partition(arr, start, last);
}

void quickSortRandomize(vector<int>& arr, int start, int last)
{
    if (last <= start)
        return;
    else {
        int partKey = partitionRandom(arr, start, last);
        quickSortRandomize(arr, start, partKey - 1);
        quickSortRandomize(arr, partKey + 1, last);
    }
}

int main()
{
    vector<int> arr { 6, 3, 7, 1, 5, 8, 9, 2, 5 };

    quickSortRandomize(arr, 0, arr.size() - 1);

    cout << "The sorted array is ";
    for (auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
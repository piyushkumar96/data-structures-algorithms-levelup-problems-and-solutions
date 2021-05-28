#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int minSwapToSort(vector<int> v)
{
    int vsize = v.size();

    pair<int, int> pa[vsize];
    for (int i = 0; i < vsize; i++) {
        pa[i].first = v[i];
        pa[i].second = i;
    }

    sort(pa, pa + vsize);
    int minSwapCount = 0;
    vector<bool> visited(vsize, false);
    for (int i = 0; i < vsize; i++) {
        int oldPos = pa[i].second;
        if (visited[i] == true || oldPos == i) {
            continue;
        }
        int node = i;
        int noOfCycle = 0;

        while (!visited[node]) {
            noOfCycle++;
            visited[node] = true;
            node = pa[node].second;
        }

        minSwapCount = minSwapCount + noOfCycle - 1;
    }

    return minSwapCount;
}

int main()
{
    vector<int> v { 5, 4, 3, 2, 1 };

    int minCount = minSwapToSort(v);
    cout << "The minimum number of swap to sort the array " << minCount << endl;
    return 0;
}
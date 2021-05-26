#include <iostream>
#include <vector>

using namespace std;

int rainWaterTrapped(vector<int> v)
{
    int vsize = v.size();
    vector<int> lmaxHeight(vsize, 0);
    lmaxHeight[0] = v[0];
    for (int i = 1; i < vsize; i++) {

        lmaxHeight[i] = max(v[i - 1], lmaxHeight[i - 1]);
    }

    vector<int> rmaxHeight(vsize, 0);
    rmaxHeight[vsize - 1] = v[vsize - 1];
    for (int i = vsize - 2; i > 0; i--) {
        rmaxHeight[i] = max(rmaxHeight[i + 1], v[i + 1]);
    }

    int total = 0;
    for (int i = 0; i < vsize; i++) {
        total = total + max(min(lmaxHeight[i], rmaxHeight[i]) - v[i], 0);
    }

    return total;
}

int main()
{
    vector<int> v { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

    int result = rainWaterTrapped(v);
    cout << "The total water trapped is " << result << endl;

    return 0;
}
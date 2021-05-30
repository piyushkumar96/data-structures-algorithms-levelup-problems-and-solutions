#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool sortBySecond(const pair<int,int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int countActivites(vector<pair<int,int> > activities){
    sort(activities.begin(), activities.end(), sortBySecond);
    int count(1), j(0);

    for(int i=1; i<activities.size();i++) {
        if (activities[j].second <= activities[i].first) {
            count++;
            j=i;
        }
    }
    cout<<endl;

    return count ;
}

int main()
{
    vector<pair<int,int>> v { {7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7} };

    int countAct = countActivites(v);
    cout << "The maximum number of activities can be completed is "<<countAct<<endl;

    return 0;
}
#include<iostream>
#include<vector>
#include<unordered_set>


using namespace std;

vector<int> pairSum(vector<int> v, int targetSum) {
    unordered_set<int> s;
    vector<int> result;

    for(int i=0; i<v.size(); i++) {
        if (s.find(targetSum - v[i]) != s.end()) {
            result.push_back(targetSum - v[i]);
            result.push_back(v[i]);
            return result;
        } else {
            s.insert(v[i]);
        }
    }

    return {};
}

int main() {
    vector<int> v{10, 5, 2, 3, -6, 9, 11};
    int targetSum = -3;

    vector<int> pair = pairSum(v, targetSum);

    if (pair.size() == 0) {
        cout<<"No pairs found"<<endl;
    } else {
        cout<<"Pair: ["<<pair[0]<<","<<pair[1]<<"]"<<endl;
    }

    return 0;
}
#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

vector<tuple<int,int,int>> tripletsSum(vector<int> v, int targetSum) {
    vector<tuple<int,int,int>> result;

    sort(v.begin(), v.end());
    int vsize = v.size();

    for(int i=0; i<vsize-2; i++) {
        int j = i+1;
        int k = vsize-1;
        while(j<k) {
            if (targetSum == (v[i] + v[j] + v[k])) {
                result.push_back(make_tuple(v[i], v[j], v[k]));
                j++;
                k--;
            }else if (targetSum > (v[i] + v[j] + v[k])) {
                j++;
            }else {
                k--;
            }
        }
    }

    return result;
}

int main() {

    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int targetSum = 18;

    vector<tuple<int,int,int>> response = tripletsSum(v, targetSum);

    if (response.size() == 0) {
        cout<<"No triplets are found"<<endl;
    } else {
        cout<<"Triplets:- "<<endl;
        for(int i=0; i<response.size(); i++) {
          cout<<"["<<get<0>(response[i])<<","<<get<1>(response[i])<<","<<get<2>(response[i])<<"]"<<endl;
        }
    }

    return 0;
}
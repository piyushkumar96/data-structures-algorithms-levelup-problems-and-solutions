#include<iostream>
#include<cstring>

using namespace std;

bool isSubSequence(string s1, string s2) {

   int l1 = s1.length();
   int l2 = s2.length();
   int i,j = 0;
   for(i=0; i<l2;) {
        if (s1[j] != s2[i]) {
            j++;
        }else {
            j++;
            i++;
        }

        if(j>=l1) {
            break;
        }
   }
    return (i == l2);
}

int main() {
    string s1, s2;

    cin>> s1 >> s2;

    bool result = isSubSequence(s1, s2);
    if( result) {
        cout<<"String 2 is sub sequence of String 1"<<endl;
    }else {
        cout<<"String 2 is not sub sequence of String 1"<<endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    for (int l=0; l<n; l++){
        string str1, str2;
        cin >> str1;
        cin >> str2;

        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        vector<char> diff(str1.size()+str2.size());
        auto it = set_intersection(str1.begin(), str1.end(), str2.begin(), str2.end(), diff.begin());
        diff.resize(it-diff.begin());

        cout << (diff.size()?"YES":"NO") << "\n";
    }
}
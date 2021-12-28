#include <bits/stdc++.h>
using namespace std;

string choice(vector<string> countries){
    int n = countries.size();

    vector<string> ans;
    int maxval = 0;
    for (int i = 0; i<n; i++){
        set<char> a(countries[i].begin(), countries[i].end());
        int s = a.size();
        if (s>maxval){
            ans.clear();
            ans.push_back(countries[i]);
            maxval = s;
        } else if (s == maxval){
            ans.push_back(countries[i]);
        }
    }
    if (ans.size() == 1) return ans[0];
    string largest = ans[0];
    for (int i = 0, n = ans.size(); i<n; i++){
        if (largest<ans[i]){
            largest = ans[i];
        }
    }
    return largest;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        int n;
        cin >> n;
        cin.ignore();
        if (!n) continue;
        vector<string> countries;
        for (int j=0; j<n; j++){
            string a;
            getline(cin, a);
            countries.push_back(a);
        }
        string result = choice(countries);
        cout << "Case #" << i+1 << ": " << result << "\n";
    }
    return 0;
}

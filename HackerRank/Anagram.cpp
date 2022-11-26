#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    for (int i = 0; i<n; i++){
        string str;
        cin >> str;

        int s = str.size();
        if (s%2){
            cout << "-1\n";
            continue;
        }

        map<char, int> f_freq;
        map<char, int> b_freq;
        set<char> alphabets;

        int mid = s/2 - 1;
        for(int j=0, k=s-1; j<=mid, k>mid; j++, k--){
            char f = str[j], b = str[k];
            // cout << "j: " << j << " k: " << k << " f: " << f << " b: " << b << endl;
            f_freq[f]++;
            b_freq[b]++;
            alphabets.insert(f);
            alphabets.insert(b);
        }

        int changes = 0;
        for (char x: alphabets){
            changes += abs(f_freq[x]-b_freq[x]);
            // cout << "checking alphabet " << x << " f_freq: " << f_freq[x] << " b_freq: " << b_freq[x] << " changes: " << changes << endl;
        }
        cout << changes/2 << "\n";
    }
}
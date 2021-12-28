#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    cin.ignore();

    string s;
    for (int i=0; n>0; i++){
        s += to_string(n%2);
        n/=2;
    }
    reverse(s.begin(), s.end());

    n = s.size();

    if (n == 0){
        cout << -1;
        return 0;
    }

    // cout << "Binary: " << s << " N: " << n << endl;
    
    int p;
    for (p=1; p<=n; p++){
        // cout << "Testing Period: " << p << endl;
        bool period = true;
        for (int k=0; k<n-p; k++){
            // cout << "K: " << k << endl;
            if (s[k] != s[k+p]){
                // cout << "This is not the period!" << endl;
                period = false;
                break;
            }
        }
        if (period) break;
    }
    cout << p;
    return 0;
}

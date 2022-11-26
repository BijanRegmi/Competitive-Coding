#include <bits/stdc++.h>
using namespace std;
#define fo(i,n)             for (int i=0; i<n; i++)
#define FO(i,j,n)           for (int i=j ; i<n ; i++)
#define rfo(i,n)            for (int i=n ; i>=0 ; i--)
#define RFO(i,j,n)          for (int i=n; i>=j; i--)
#define foit(it, x)         for (auto it = x.begin(); it != x.end(); it++)
#define foa(x, a)           for (auto x: a)
#define deb(x)              cout << #x << ": " << x << std::endl;
#define debb(x, y)          cout << #x << ": " << x << "  " << #y << ": " << y << std::endl;
#define debarr(x)           cout << #x << "["; for(auto a: x) cout << " " << a; cout << " ]" << endl;
#define ct(t, x)            t x; cin >> x;
#define ca(t, a, n)         t a[n]; fo(i, n){t x; cin >> x; a[i] = x;}
#define cv(t, a, n)         vector<t> a; fo(i, n){t x; cin >> x; a.push_back(x);}
#define ll                  long long
#define all(obj)            obj.begin(), obj.end()
typedef pair<int, int>      pii;
typedef pair<ll, ll>        pll;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef vector<vi>          vvi;
typedef vector<vl>          vvl;
typedef vector<pii>         vpii;
typedef vector<string>      vs;
typedef map<int, int>       mii;

// =============[ Solution Begin ]=============
void solve(){
    ct(string, str1);
    ct(string, str2);

    int n = str1.size();
    
    int left=-1, right=-1;
    fo(i, n){
        if (str1[i] != str2[i]){
            left = i;
            break;
        }
    }

    rfo(i, n-1){
        if (str1[i] != str2[i]){
            right = i;
            break;
        }
    }
    if (left == right){
        cout << 0;
        return;
    }
    // debb(left, right);
    int len = right - left;
    int idx1, idx2;
    bool found;
    for (int rot = 1; rot <= len; rot++){
        found = true;
        // deb(rot);
        // cout << endl;
        fo(i, len){
            idx1 = left + i;
            idx2 = i - rot;
            // deb(idx2);
            if (idx2 < 0) idx2 += len+1;
            // deb(idx2);
            idx2 += left;
            // debb(idx1, idx2);
            // debb(str1[idx1], str2[idx2]);
            if (str1[idx1] != str2[idx2]){
                found = false;
                break;
            }
        }
        if (found){
            cout << rot;
            return;
        }

    }
}
// =============[ Solution End ]=============

int main(){
    bool testcase = false;
    int t = 1;
    if (testcase) cin >> t;

    while(t--){
        solve();
        cout << endl;
    }
}
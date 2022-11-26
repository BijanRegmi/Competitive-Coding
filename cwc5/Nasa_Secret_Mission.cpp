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
    ct(int, n);
    if (n==0){cout << 0; return;}

    cv(int, arr, n);

    sort(all(arr));

    int min = arr[0], cost = 0;
    FO(i, 1, n){
        cost += arr[i]*min;
    }
    cout << cost;

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
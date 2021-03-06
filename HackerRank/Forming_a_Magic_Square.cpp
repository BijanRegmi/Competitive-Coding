#include <bits/stdc++.h>
using namespace std;
#define fo(i,n)             for (int i=0; i<n; i++)
#define FO(i,j,n)           for (int i=j ; i<n ; i++)
#define rfo(i,n)            for (int i=0 ; i>=n ; i--)
#define RFO(i,j,n)          for (int i=j; i>=n; i--)
#define foit(it, x)         for (auto it = x.begin(); it != x.end(); it++)
#define foa(x, a)           for (auto x: a)
#define deb(x)              cout << #x << ": " << x << std::endl;
#define debb(x, y)          cout << #x << ": " << x << "  " << #y << ": " << y << std::endl;
#define debarr(x)           cout << #x << "["; for(auto a: x) cout << " " << a; cout << " ]" << endl;
#define ci(x)               cin >> x;
#define cav(a, n)           fo(i, n){int x; cin >> x; a.push_back(x);}
#define caa(a, n)           fo(i, n){int x; cin >> x; a[i] = x;}
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

void solve(){
    int arr[9];
    fo(i, 9) ci(arr[i]);

    int possible[8][9] = {
        {4, 3, 8, 9, 5, 1, 2, 7, 6},
        {8, 3, 4, 1, 5, 9, 6, 7, 2},
        {8, 1, 6, 3, 5, 7, 4, 9, 2},
        {4, 9, 2, 3, 5, 7, 8, 1, 6},
        {2, 7, 6, 9, 5, 1, 4, 3, 8},
        {6, 7, 2, 1, 5, 9, 8, 3, 4},
        {6, 1, 8, 7, 5, 3, 2, 9, 4},
        {2, 9, 4, 7, 5, 3, 6, 1, 8}
    };

    int mincost = 1000, cost;

    fo(i, 8){
        cost = 0;
        fo(j, 9){
            cost += abs(possible[i][j]-arr[j]);
        }
        mincost = min(mincost, cost);
    }

    cout << mincost;
}

int main(){
    bool testcase = false;
    int t = 1;
    if (testcase) cin >> t;

    while(t--){
        solve();
    }
}

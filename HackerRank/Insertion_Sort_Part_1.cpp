#include <bits/stdc++.h>
using namespace std;
#define fo(i,n)             for (int i=0; i<n; i++)
#define Fo(i,j,n)           for (int i=j ; i<n ; i++)
#define rfo(i,n)            for (int i=0 ; i>=n ; i--)
#define rFo(i,j,n)          for (int i=j; i>=n; i--)
#define foit(it, x)         for (auto it = x.begin(); it != x.end(); it++)
#define foa(x, a)           for (auto x: a)
#define deb(x)              cout << #x << ": " << x << std::endl;
#define debb(x, y)          cout << #x << ": " << x << "  " << #y << ": " << y << std::endl;
#define debarr(x)           cout << #x << "["; for(auto a: x) cout << " " << a; cout << " ]" << endl;
#define ci(x)               cin >> x;
#define ca(a, n)            fo(i, n){int x; cin >> x; a.push_back(x);}
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
    int n;
    ci(n);

    int a[n], v;
    fo(i, n){
        ci(v);
        a[i] = v;
    }

    int i = n-2;
    while(i>=0 && a[i]>v){
        a[i+1] = a[i];
        foa(x, a) cout << x << " ";
        cout << endl;
        i--;
    }
    a[i+1] = v;
    foa(x, a) cout << x << " ";
}

int main(){
    bool testcase = false;
    int t = 1;
    if (testcase) cin >> t;

    while(t--){
        solve();
    }
}
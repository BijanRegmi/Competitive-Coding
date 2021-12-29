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
    string b;
    ci(b);

    bool hasbuffer = false, happy = true;
    mii occurence;
    fo(i, n){
        if (b[i] == '_'){
            hasbuffer = true;
            continue;
        }
        if (happy){
            bool left=false, right=false;
            if (i>0) left = (b[i-1] == b[i]);
            if (i<n-1) right = (b[i+1] == b[i]);
            happy = (left || right);
        }
        occurence[b[i]]++;
    }
    bool alone = false;
    foa(x, occurence){
        if(x.second == 1){
            alone = true;
            break;
        }
    }
    if(happy || (hasbuffer && !alone)) cout << "YES\n"; else cout << "NO\n";
}

int main(){
    bool testcase = true;
    int t = 1;
    if (testcase) cin >> t;

    while(t--){
        solve();
    }
}
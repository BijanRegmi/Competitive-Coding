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
    // Numbers [48, 57]
    // Lowercase [97, 122]
    // Uppercase [65, 90]
    // Special Character !33 @54 #35 $36 %37 ^94 &38 *42 (40 )41 -45 +43
    // Special Character {33, 35, 36, 37, 38, 40, 41, 42, 43, 45, 54, 94}

    int n;
    ci(n);
    string s;
    ci(s);

    int a;
    int d=1, l=1, u=1, sp=1;
    fo(i, n){
        a = s[i];
        if (a >= 48 && a <= 57) d=0;
        else if (a >= 97 && a<=122) l=0;
        else if (a >= 65 && a <= 90) u=0;
        else if ((a >= 33 && a <= 45 && a != 34 && a != 39 && a != 44) || a == 54 || a == 94) sp=0;
    }
    a = d+l+u+sp;
    a += max(0, 6-a-n);
    cout << a;
}

int main(){
    bool testcase = false;
    int t = 1;
    if (testcase) cin >> t;

    while(t--){
        solve();
    }
}
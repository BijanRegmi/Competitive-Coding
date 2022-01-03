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

int getlength(char a, char b, string s){
    int length=0;
    char lastread;
    foa(x, s){
        if (x==a){
            if (lastread==a) return -1;
            lastread = a;
            length++;
        } else if (x==b){
            if (lastread==b) return -1;
            lastread = b;
            length++;
        }
    }
    return length;
}

void solve(){
    int n;
    ci(n);
    string s;
    ci(s);

    set<char> alph(all(s));
    vector<char> alpharr(all(alph));

    int an = alpharr.size(), length, maxlength=0;
    fo(i, an){
        FO(j, i+1, an){
            length = getlength(alpharr[i], alpharr[j], s);
            maxlength = max(maxlength, length);
        }
    }
    cout << maxlength;
}

int main(){
    bool testcase = false;
    int t = 1;
    if (testcase) cin >> t;

    while(t--){
        solve();
    }
}
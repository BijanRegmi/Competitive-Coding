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

long num(string& s){
    int d = s.size();
    int c;
    long val=0;
    fo(i, d){
        c = s[i]-'0';
        if (i==0 && c==0) return -1;
        val = val*10+c;
    }
    return val;
}

void solve(){
    string s;
    ci(s);
    int n = s.size();

    long curr, startval=-1, prev=-1;
    string subs;
    FO(size, 1, n/2+1){
        subs = s.substr(0, size);
        startval = num(subs);
        if (size != 1 && startval==-1){
            // cout << "Double digit ma 0 xa break break\n";
            break;
        }
        prev = startval;
        // debb(size, startval);
        FO(i, size, n){
            // deb(i);
            bool foundnext = false;
            FO(nsize, size, size+2) {
                subs = s.substr(i, nsize);
                curr = num(subs);
                // debb(nsize, curr);
                if (curr <= 0){
                    // cout << "0 aayo next check garera matlab xaina\n";
                    break;
                }
                if (curr - prev == 1){
                    // cout << "Found Next\n";
                    i = i+nsize-1;
                    foundnext = true;
                    break;
                }
            }
            if (!foundnext){
                // cout << "No consecutive. check next size\n";
                prev = -1;
                break;
            }
            prev = curr;
        }
        if (prev != -1) {
            // cout << "sabai sakiyo ani consecutive ni xa\n";
            break;
        }
        // cout << endl;
    }
    if (prev == -1){ cout << "NO";}
    else { cout << "YES " << startval; }
}

int main(){
    bool testcase = true;
    int t = 1;
    if (testcase) cin >> t;

    while(t--){
        solve();
        cout << endl;
    }
}
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
    int r, c, n;
    cin >> r >> c >> n;

    // deb(r); deb(c); deb(n);
    if (!(n%2)){
        fo(i, r){
            fo(j, c)
                cout << 'O';
            cout << endl;
        }
        return;
    }

    string init[r];
    fo(i, r){
        string s;
        cin >> s;
        init[i] = s;
    }

    if (n==1) { foa(x, init) cout << x << endl; return; }

    int N = n%4+(n%4<=2)*4;
    int k = (N==3)+2*(N==5);
    // debb(N, k);
    while(k--){
        // deb(k);
        fo(j, r){
            fo(l, c){
                if (init[j][l] == 'O'){
                    // cout << "Found O at j: " << j << " l: " << l << endl;
                    if (j>0)    { if(init[j-1][l]!='O') init[j-1][l]='a'; }
                    if (j<r-1)  { if(init[j+1][l]!='O') init[j+1][l]='a'; }
                    if (l>0)    { if(init[j][l-1]!='O') init[j][l-1]='a'; }
                    if (l<c-1)  { if(init[j][l+1]!='O') init[j][l+1]='a'; }
                }
            }
        }
        // cout << endl << "Installed a's" << endl;
        // foa(x, init) cout << x << endl; cout << endl;
        fo(j, r){
            fo(l, c){
                if (init[j][l]=='.'){ init[j][l] = 'O'; continue;}
                init[j][l] = '.';
            }
        }
        // foa(x, init) cout << x << endl;
    }

    // cout << "Final Answer: " << endl;
    foa(x, init){
        cout << x << endl;
    }
    
}

int main(){
    bool testcase = false;
    int t = 1;
    if (testcase) cin >> t;

    while(t--){
        solve();
    }
}
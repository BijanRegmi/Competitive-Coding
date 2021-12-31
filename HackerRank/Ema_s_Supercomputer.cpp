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
    int n, m;
    cin >> n >> m;

    // Take input
    int grid[n][m];
    fo(i, n){
        string a;
        cin >> a;
        fo(j, m) if(a[j]=='B') grid[i][j]=-1; else grid[i][j]=0;
    }
    
    // Assign possible plus lengths
    FO(i, 1, n-1){
        FO(j, 1, m-1){
            if (grid[i][j]==-1) continue;
            int left=0, right=0, up=0, down=0;
            while(j-left-1>=0 && grid[i][j-left-1]!=-1) left++;
            while(j+right+1<m && grid[i][j+right+1]!=-1) right++;
            while(i-up-1>=0 && grid[i-up-1][j]!=-1) up++;
            while(i+down+1<n && grid[i+down+1][j]!=-1) down++;
            // cout << "i: " << i << " j: " << j << " l: " << left << " r: " << right << " d: " << down << " u: " << up << endl;
            grid[i][j] = min(min(left, right), min(down, up));
        }
    }

    // cout << "Possible Plus lengths: " << endl;
    // fo(i, n){ fo(j, m) cout << setw(2) << grid[i][j] << " "; cout << endl; }
    // cout << endl;

    // Find max pluses
    int first=0, second, product=0;
    fo(i, n){
        fo(j, m){
            // debb(i, j);
            second = 0;
            if (grid[i][j]<0) continue;
            int firstmax = grid[i][j];
            RFO(h, firstmax, 0){
            first = h;
            // deb(first);
            // Recalculate the grid's possible plus to remove overlaps
            int temp[n][m];
            fo(a, n) fo(b, m) temp[a][b]=grid[a][b];
            // temp[i][j]=-1;
            fo(k, first+1){
                temp[i+k][j]=-1;
                temp[i-k][j]=-1;
                temp[i][j+k]=-1;
                temp[i][j-k]=-1;
            }
            // fo(a, n){ fo(b, m) cout << setw(2) << temp[a][b] << " "; cout << endl;}
            // cout << endl;
            FO(a, 1, n-1){
                FO(b, 1, m-1){
                    if (temp[a][b]==-1) continue;
                    int left=0, right=0, up=0, down=0;
                    while(b-left-1>=0 && temp[a][b-left-1]!=-1) left++;
                    while(b+right+1<m && temp[a][b+right+1]!=-1) right++;
                    while(a-up-1>=0 && temp[a-up-1][b]!=-1) up++;
                    while(a+down+1<n && temp[a+down+1][b]!=-1) down++;
                    // cout << "a: " << a << " b: " << b << " l: " << left << " r: " << right << " d: " << down << " u: " << up << endl;
                    temp[a][b] = min(min(left, right), min(down, up));
                }
            }
            // cout << "\nRecalculation done" << endl;
            // fo(a, n){ fo(b, m) cout << setw(2) << temp[a][b] << " "; cout << endl; } cout << endl;
            // Find the largest plus among the remaining plus for second plus
            fo(a, n) fo(b, m) second = max(second, temp[a][b]);
            // int p = (4*first+1)*(4*second+1);
            // debb(second, p);
            product = max(product, (4*first+1)*(4*second+1));
            // deb(product);
            }
            // cout << endl << endl;
        }
    }
    // deb(product);
    // fo(i, n){ fo(j, m) cout << grid[i][j] << " "; cout << endl;}
    cout << product;
}

int main(){
    bool testcase = false;
    int t = 1;
    if (testcase) cin >> t;

    while(t--){
        solve();
    }
}
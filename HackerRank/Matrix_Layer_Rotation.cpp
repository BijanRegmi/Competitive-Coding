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
    int m, n, r;
    cin >> m >> n >> r;

    int arr[m][n];

    int du, dd, dl, dr, d, l, b, p, k, ni, nj, nr, x;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            ci(x);

            du = i, dd = (m-1)-i, dl = j, dr = (n-1)-j;
            d = min(min(du, dd), min(dl, dr));          // Depth
            l = m-2*d, b = n-2*d;                       // Length and breadth of the inner layer
            p = 2*(l+b-2);                              // Perimeter or the amount of numbers in that layer
            if (i==d || j==b+d-1) k = i+j-d-d;          // Position in the 1D array of the layer
            else k = p-(i+j)+d+d;

            nr = r % p;                                 // Canceled out full rotations
            k = ((k+p)-nr)%p;                           // New position in the circle after nr rotation

            // Finding new position in array after nr rotations
            if (k<=p/2){
                if (k<b){
                    ni = 0;
                    nj = k;
                } else {
                    ni = k-b+1;
                    nj = b-1;
                }
            } else {
                k = p - k;
                if (k<l){
                    ni = k;
                    nj = 0;
                } else {
                    ni = l-1;
                    nj = k-l+1;
                }
            }

            ni += d, nj += d;

            arr[ni][nj] = x;
        }
    }

    fo(i, m){
        fo(j, n) cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main(){
    bool testcase = false;
    int t = 1;
    if (testcase) cin >> t;

    while(t--){
        solve();
        cout << endl;
    }
}
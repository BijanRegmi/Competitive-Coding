#include <bits/stdc++.h>
using namespace std;
#define fo(i,n)             for (int i=0; i<n; i++)
#define FO(i,j,n)           for (int i=j ; i<n ; i++)
#define rfo(i,n)            for (int i=n-1 ; i>=0 ; i--)
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
    int n;
    ci(n);

    vi arr;
    cav(arr, n);

    if (is_sorted(all(arr))){ cout << "yes"; return; } 

    int left=-1, right=-1;
    fo(i, n-1){
        if (arr[i] > arr[i+1]){
            left = i;
            break;
        }
    }
    RFO(i, n-1, 1){
        if (arr[i]<arr[i-1]){
            right = i;
            break;
        }
    }

    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;

    if (is_sorted(all(arr))){ cout << "yes\nswap " << left+1 << " " << right+1; return; }

    reverse(arr.begin()+left+1, arr.begin()+right);

    if (is_sorted(all(arr))){ cout << "yes\nreverse " << left+1 << " " << right+1; return; }
    cout << "no";

}

int main(){
    bool testcase = false;
    int t = 1;
    if (testcase) cin >> t;

    while(t--){
        solve();
    }
}
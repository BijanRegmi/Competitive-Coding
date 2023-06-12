#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define deb(x) cout << #x << ": " << x << std::endl;

#define debb(x, y)                                                             \
    cout << #x << ": " << x << "  " << #y << ": " << y << std::endl;

#define debarr(x)                                                              \
    cout << #x << "[";                                                         \
    for (auto a : x)                                                           \
        cout << " " << a;                                                      \
    cout << " ]" << endl;

#define ll long long
#define all(obj) obj.begin(), obj.end()

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef map<int, int> mii;

// =============[ Solution Begin ]=============
void solve() {
    int n, min = INT_MAX;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    int minops = INT_MAX;
    for (int j = 0; j < 5; j++) {
        int ops = 0;
        for (int i = 0; i < arr.size(); i++) {
            int t = arr[i] - (min - j);
            ops += t / 5 + t % 5 / 2 + t % 5 % 2;
        }
        if (ops < minops)
            minops = ops;
    }
    cout << minops;
}
// =============[ Solution End ]=============

int main() {
    bool testcase = true;
    int t = 1;
    if (testcase)
        cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }
}

#include <bits/stdc++.h>
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
ll countWays(int n, int k, int x, map<pii, int> &lookup) {
    if (n == 1) {
        if (x == 1)
            return 1;
        else
            return 0;
    }
    if (lookup.find({n, x}) != lookup.end()) {
        return lookup[{n, x}];
    }
    ll c1 = countWays(n - 1, k, 1, lookup);
    ll c2 = countWays(n - 1, k, 2, lookup);
    ll cnt = x == 1 ? c2 * (k - 1) : c1 + c2 * (k - 2);
    cnt %= 1000000007;
    lookup[{n, x}] = cnt;
    return cnt;
}
void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    map<pii, int> lookup;
    cout << countWays(n, k, x, lookup);
}
// =============[ Solution End ]=============

int main() {
    bool testcase = false;
    int t = 1;
    if (testcase)
        cin >> t;

    while (t--) {
        solve();
        cout << endl;
    }
}

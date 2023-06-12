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
ll findChange(vector<int> &c, int m, int n, map<pii, ll> &lookup) {
    if (m <= 0)
        return 0;
    else if (n == 0)
        return 1;
    else if (n < 0)
        return 0;
    else if (lookup.find({m, n}) != lookup.end()) {
        return lookup[{m, n}];
    } else {
        return lookup[{m, n}] = findChange(c, m - 1, n, lookup) +
                                findChange(c, m, n - c[m - 1], lookup);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++)
        cin >> c[i];
    sort(all(c));
    map<pair<int, int>, ll> lookup;
    cout << findChange(c, m, n, lookup);
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

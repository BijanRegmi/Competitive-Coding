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
unsigned ll mfib(int t1, int t2, int n, map<int, unsigned ll> &lookup) {
    if (n == 1)
        return t1;
    else if (n == 2)
        return t2;
    else if (lookup.find(n) != lookup.end())
        return lookup[n];
    else
        return lookup[n] = mfib(t1, t2, n - 2, lookup) +
                           pow(mfib(t1, t2, n - 1, lookup), 2);
}

void solve() {
    int t1, t2, n;
    cin >> t1 >> t2 >> n;
    map<int, unsigned ll> lookup;
    // Fck bigint problems
    cout << mfib(t1, t2, n, lookup);
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

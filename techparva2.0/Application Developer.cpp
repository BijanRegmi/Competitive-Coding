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
void solve() {
    int n;
    cin >> n;

    vector<int> userIds(n);
    vector<int> timeSpent(n);

    for (int i = 0; i < n; i++) {
        cin >> userIds[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> timeSpent[i];
    }

    map<int, int> spent;
    for (int i = 0; i < n; i++) {
        spent[userIds[i]] += timeSpent[i];
    }

    int highId, highSpent = 0;
    for (auto s : spent) {
        if (s.second >= highSpent) {
            highId = s.first;
            highSpent = s.second;
        }
    }
    cout << highId << endl << highSpent;
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

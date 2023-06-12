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
    int r, p, x, i, j;

    cin >> r;

    vector<int> ranked;
    for (i = 0; i < r; i++) {
        cin >> x;
        ranked.push_back(x);
    }
    ranked.erase(unique(all(ranked)), ranked.end());

    cin >> p;

    j = ranked.size() - 1;
    for (i = 0; i < p; i++) {
        cin >> x;

        int rank = 1;
        for (; j >= 0;) {
            if (x < ranked[j]) {
                rank = j + 2;
                break;
            } else if (x == ranked[j]) {
                rank = j + 1;
                break;
            } else {
                j--;
            }
        }
        cout << rank << endl;
    }
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

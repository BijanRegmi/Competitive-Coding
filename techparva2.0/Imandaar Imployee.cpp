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

    if (n == 0) {
        cout << 0;
        return;
    }

    vector<int> documents(n);
    for (int i = 0; i < n; i++) {
        cin >> documents[i];
    }

    int dipInterval;
    cin >> dipInterval;

    // Even if the constraint says that the array
    // is already sorted. There were some testcases
    // where the array wasn't sorted.
    sort(documents.begin(), documents.end());

    int dip_count = 0;
    int curr = -1;

    for (int i = 0; i < n; i++) {
        if (documents[i] > curr) {
            dip_count++;
            curr = documents[i] + dipInterval;
        }
    }

    cout << dip_count;
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

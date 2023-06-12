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

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int total = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == i + 1)
            continue;
        if (arr[i - 1] == i + 1) {
            total += 1;
            arr[i - 1] = arr[i];
        } else if (arr[i - 2] == i + 1) {
            total += 2;
            arr[i - 2] = arr[i - 1];
            arr[i - 1] = arr[i];
        } else {
            cout << "Too chaotic";
            return;
        }
    }
    cout << total;
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

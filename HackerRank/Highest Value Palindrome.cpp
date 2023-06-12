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
    int n, k;
    string str;

    cin >> n >> k >> str;

    int mid = -1;
    vpii changes;

    for (int i = 0, j = n - 1; i <= j; i++, j--) {
        if (i == j) {
            mid = i;
            continue;
        }
        char f = str[i], b = str[j];
        if (f != b) {
            changes.push_back({i, j});
        }
    }
    int delta = changes.size();
    if (delta > k) {
        cout << -1;
        return;
    }
    for (int i = 0; i < delta; i++) {
        char f = str[changes[i].first], b = str[changes[i].second];
        int maxCost = f == '9' || b == '9' ? 1 : 2;
        // debb(i, maxCost);
        // debb(f, b);
        // debb(delta - i - 1, k);
        if (delta - i - 1 <= k - maxCost) {
            k = k - maxCost;
            str[changes[i].first] = str[changes[i].second] = '9';
        } else {
            k = k - 1;
            str[changes[i].first] = str[changes[i].second] = max(f, b);
        }
    }
    deb(k);
    for (int i = 0, j = n - 1; i <= j && k >= 2; i++, j--) {
        if (i == 17) {
            debb(i, str[i]);
            debb(j, str[j]);
            // cout << "17=> f: " << str[i] << " b: " << str[j] << endl;
        }
        if (str[i] != '9') {
            if (i == 17) {
                cout << "17=> Changing to 9" << endl;
            }
            str[i] = str[j] = '9';
            k -= 2;
        }
    }
    if (k >= 1 && mid != -1) {
        str[mid] = '9';
    }
    cout << str << endl;
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

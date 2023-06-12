#include <bits/stdc++.h>
#include <cmath>
#include <string>
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
    string num;
    cin >> num;
    int n = num.length();
    unsigned ll sum = 0;
    unsigned ll f = 1;
    for (int i = n - 1; i >= 0; i--) {
        unsigned ll tmp = (num[i] - '0') * (i + 1) * f;
        tmp %= 1000000007;
        sum += tmp;
        sum %= 1000000007;
        f = (f * 10 + 1) % 1000000007;
    }
    cout << sum;
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

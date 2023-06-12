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
    string s;
    cin >> s;
    int freq[26] = {};
    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;
    }
    bool removed = false;
    map<int, int> hist;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0)
            continue;
        if (hist.find(freq[i]) == hist.end()) {
            hist[freq[i]] = 1;
        } else {
            hist[freq[i]]++;
        }
    }
    if (hist.size() == 1) {
        cout << "YES";
        return;
    } else if (hist.size() > 2) {
        cout << "NO";
        return;
    } else if (hist.size() == 2) {
        int f1 = 0, f2 = 0, f1h = 0, f2h = 0;
        for (auto i : hist) {
            if (f1 == 0) {
                f1 = i.first;
                f1h = i.second;
            } else if (f2 == 0) {
                f2 = i.first;
                f2h = i.second;
            }
        }
        if ((f1h == 1 && (f1 - 1 == f2 || f1 - 1 == 0)) ||
            (f2h == 1 && (f2 - 1 == f1 || f2 - 1 == 0))) {
            cout << "YES";
            return;
        }
        cout << "NO";
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

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

    vector<pair<int, int>> meetings;

    for (int i = 0; i <= n; i++) {
        int start, end;
        cin >> start >> end;

        meetings.push_back(make_pair(start, end));
    }

    sort(meetings.begin(), meetings.end());

    vector<pair<int, int>> merged;

    for (auto meet : meetings) {
        if (merged.empty() || merged.back().second < meet.first) {
            merged.push_back(meet);
        } else {
            merged.back().second = max(merged.back().second, meet.second);
        }
    }

    for (auto meet : merged) {
        cout << meet.first << " " << meet.second << endl;
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

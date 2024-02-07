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

    string answer = "";
    string encrypted;
    for (int i = 0; i < n; i++) {
        cin >> encrypted;
        int mid = encrypted.length() / 2;

        set<char> first_half(encrypted.begin(), encrypted.begin() + mid);
        set<char> second_half(encrypted.begin() + mid, encrypted.end());

        set<char> intersection;
        set_intersection(first_half.begin(), first_half.end(),
                         second_half.begin(), second_half.end(),
                         inserter(intersection, intersection.begin()));
        if (intersection.empty()) {
            continue;
        } else {
            answer += *intersection.begin();
        }
    }

    cout << answer;
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

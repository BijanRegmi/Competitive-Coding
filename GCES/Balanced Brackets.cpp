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
    string str;
    cin >> str;
    if (str.size() % 2 == 1) {
        cout << "NO";
        return;
    }
    stack<char> stck;
    stck.push('0');
    for (int i = 0; i < str.size(); i++) {
        char top = stck.top();
        if ((top == '(' && str[i] == ')') || (top == '{' && str[i] == '}') ||
            (top == '[' && str[i] == ']')) {
            stck.pop();
        } else {
            stck.push(str[i]);
        }
    }
    cout << (stck.size() > 1 ? "NO" : "YES");
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

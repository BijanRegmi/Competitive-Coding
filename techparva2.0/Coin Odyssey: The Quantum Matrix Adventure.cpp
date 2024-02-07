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
map<pair<int, int>, int> memo; // Even with this memoization the 1000x1000 input will timeout

int getMax(vector<vector<int>> grid, pair<int, int> cord) {
    if (memo.count(cord))
        return memo[cord];

    int right = 0, down = 0;
    if (cord.first + 1 < grid.size())
        down = getMax(grid, make_pair(cord.first + 1, cord.second));
    if (cord.second + 1 < grid[0].size())
        right = getMax(grid, make_pair(cord.first, cord.second + 1));

    int ans = grid[cord.first][cord.second] + max(right, down);
    memo[cord] = ans;
    return ans;
}

void solve() {
    int m, n, t;
    cin >> m >> n;

    if (m == 0 || n == 0) {
        cout << 0;
        return;
    }

    vector<vector<int>> grid;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            cin >> t;
            row.push_back(t);
        }
        grid.push_back(row);
    }

    cout << getMax(grid, {0, 0});
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

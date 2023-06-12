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
    int m, n, r;
    cin >> m >> n >> r;
    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    int rotated[m][n];
    int ni, nj, du, dl, dd, dr, d, l, b, p, nr, k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            du = i, dd = (m - 1) - i, dl = j, dr = (n - 1) - j;
            d = min(min(du, dd), min(dl, dr)); // Depth
            l = m - 2 * d, b = n - 2 * d;
            p = 2 * (l + b - 2);

            if (i == d || j == b + d - 1)
                k = i + j - d - d;
            else
                k = p - (i + j) + d + d;

            nr = r % p;
            k = ((k + p) - nr) % p;

            if (k <= p / 2) {
                if (k < b) {
                    ni = 0;
                    nj = k;
                } else {
                    ni = k - b + 1;
                    nj = b - 1;
                }
            } else {
                k = p - k;
                if (k < l) {
                    ni = k;
                    nj = 0;
                } else {
                    ni = l - 1;
                    nj = k - l + 1;
                }
            }
            ni += d, nj += d;

            rotated[ni][nj] = matrix[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
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

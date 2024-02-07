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

    vector<string> wins(n);
    for (int i = 0; i < n; i++) {
        cin >> wins[i];
    }

    string currentTeam = "";
    int currentStreak = 0;
    string maxStreakTeam = "";
    int maxStreak = 0;

    for (int i = 0; i < n; i++) {
        string team = wins[i];
        if (team == currentTeam) {
            currentStreak++;
        } else {
            if (currentStreak > maxStreak) {
                maxStreak = currentStreak;
                maxStreakTeam = currentTeam;
            }
            currentTeam = team;
            currentStreak = 1;
        }
    }
    if (maxStreak == 1) {
        // This is completely weird. If the input is something
        // like 'A B C D E' then in this case since all the
        // teams had a streak of 1, no team has the highest
        // streak so we print empty string and 0.
        cout << "" << endl << 0 << endl;
    } else {
        cout << maxStreakTeam << endl << maxStreak;
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

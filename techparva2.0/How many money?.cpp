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

    if (n == 0)
        return;

    deque<int> stackone;
    deque<int> stacktwo;

    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        stackone.push_front(t);
    }
    for (int i = 0; i < n; i++) {
        cin >> t;
        stacktwo.push_front(t);
    }

    int answer = 0;
    bool turn = true;
    while (!stackone.empty() && !stacktwo.empty()) {
        if (stackone.back() > stacktwo.back()) {
            if (turn)
                answer += stackone.back();
            stackone.pop_back();

        } else {
            if (turn)
                answer += stacktwo.back();
            stacktwo.pop_back();
        }
        turn = !turn;
    }

    while (!stackone.empty()) {
        if (turn)
            answer += stackone.back();
        stackone.pop_back();
        turn = !turn;
    }

    while (!stacktwo.empty()) {
        if (turn)
            answer += stacktwo.back();
        stacktwo.pop_back();
        turn = !turn;
    }

    std::cout << answer << std::endl;
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

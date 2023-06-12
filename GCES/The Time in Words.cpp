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
    int h, m;
    cin >> h >> m;

    map<int, string> n = {
        {1, "one"},           {2, "two"},           {3, "three"},
        {4, "four"},          {5, "five"},          {6, "six"},
        {7, "seven"},         {8, "eight"},         {9, "nine"},
        {10, "ten"},          {11, "eleven"},       {12, "twelve"},
        {13, "thirteen"},     {14, "fourteen"},     {15, "fifteen"},
        {16, "sixteen"},      {17, "seventeen"},    {18, "eighteen"},
        {19, "nineteen"},     {20, "twenty"},       {21, "twenty one"},
        {22, "twenty two"},   {23, "twenty three"}, {24, "twenty four"},
        {25, "twenty five"},  {26, "twenty six"},   {27, "twenty seven"},
        {28, "twenty eight"}, {29, "twenty nine"},  {30, "thirty"},
    };

    if (m == 0)
        cout << n[h] << " o' clock";
    else if (m <= 30) {
        if (m == 1)
            cout << "one minute past " << n[h];
        else if (m == 15)
            cout << "quarter past " << n[h];
        else if (m == 30)
            cout << "half past " << n[h];
        else
            cout << n[m] << " minutes past " << n[h];
    } else {
        if (m == 45)
            cout << "quarter to " << n[(h + 1) % 12];
        else if (m == 59)
            cout << "one minute to " << n[(h + 1) % 12];
        else
            cout << n[60 - m] << " minutes to " << n[(h + 1) % 12];
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

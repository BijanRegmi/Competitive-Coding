#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'appendAndDelete' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 *  3. INTEGER k
 */

string appendAndDelete(string s, string t, int k) {
    int ss = s.size(), ts = t.size(), diffidx = -1;
    if (ss+ts<=k) return "Yes";

    int minlen = min(ss, ts);
    for (int i=0; i<minlen; i++){
        if (s[i] != t[i]){
            diffidx = i;
            break;
        }
    }

    if (diffidx == -1){
        if (ss == ts) return "Yes";
        else diffidx = minlen;
    }

    int remcount = ss - diffidx;
    int addcount = ts - diffidx;
    int remoper = k - remcount - addcount;

    if (remoper < 0) return "No";
    if (remoper == 0 || remoper%2 == 0) return "Yes";
    return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = appendAndDelete(s, t, k);

    cout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

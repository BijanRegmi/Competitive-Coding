#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

long long getdigit(long long n){
    long long temp = n, count = 0;
    while(temp){
        count++;
        temp/=10;
    }
    return count;
}

void kaprekarNumbers(int p, int q) {
    bool found = false;
    for (long i=p; i<=q; i++){
        long long s = i*i;

        int d = getdigit(i);
        int sd = getdigit(s);

        string ss = to_string(s);
        string r = ss.substr(sd-d, d);
        string l = ss.substr(0, sd-d);

        if (l=="") l = "0";

        int ri = stoi(r);
        int li = stoi(l);

        if (ri+li == i){
            cout << i << " ";
            found = true;
        }
    }
    if (!found) cout << "INVALID RANGE";
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

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

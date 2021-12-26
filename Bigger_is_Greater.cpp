#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

string biggerIsGreater(string w) {
    int n = w.size();

    int pivot=-1;
    for (int i=n-1; i>0; i--){
        if (w[i-1] < w[i]){
            pivot = i;
            break;
        }
    }

    if (pivot == -1) return "no answer";
    
    int swapidx=-1;
    for (int i=n-1; i>=pivot; i--){
        if (w[i] > w[pivot-1]){
            swapidx = i;
            break;
        }
    }

    swap(w[pivot-1], w[swapidx]);
    reverse(w.begin()+pivot, w.end());

    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        cout << result << "\n";
    }

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

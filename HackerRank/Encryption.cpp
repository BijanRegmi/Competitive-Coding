#include <bits/stdc++.h>
#include <sstream>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    for (int i=0, j=s.size(); i<j; i++) if (s[i] == ' ') s.replace(i, 1, "");

    int L = s.length();
    float sr = sqrt(L);
    int col = ceil(sr);
    int row = ceil(float(L)/col);

    stringstream encp;
    for (int i=0; i<col; i++){
        for (int j=0; j<row; j++){
            if (i+j*col < L) encp << s[i+j*col];
        }
        encp << " ";
    }
    return encp.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    cout << result << "\n";

    fout.close();

    return 0;
}

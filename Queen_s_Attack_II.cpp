#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int up_limit = n+1, down_limit = 0, left_limit = 0, right_limit = n+1;
    int ul_limit = min(n-r_q, c_q-1), ur_limit = min(n-r_q, n-c_q), dl_limit = min(r_q-1, c_q-1), dr_limit = min(r_q-1, n-c_q);
    for (auto x: obstacles){
        int dr = x[0] - r_q, dc = x[1] - c_q;
        if (dr>0 && !dc)
            up_limit = min(up_limit, x[0]);
        else if (dr<0 && !dc)
            down_limit = max(down_limit, x[0]);
        else if (!dr && dc>0)
            right_limit = min(right_limit, x[1]);
        else if (!dr && dc<0)
            left_limit = max(left_limit, x[1]);
        else if (dr>0 && dc>0 && dr==dc)
            ur_limit = min(ur_limit, min(x[0]-r_q-1, x[1]-c_q-1));
        else if (dr>0 && dc<0 && dr==-dc)
            ul_limit = min(ul_limit, min(x[0]-r_q-1, c_q-x[1]-1));
        else if (dr<0 && dc>0 && dr==-dc)
            dr_limit = min(dr_limit, min(r_q-x[0]-1, x[1]-c_q-1));
        else if (dr<0 && dc<0 && dr==dc)
            dl_limit = min(dl_limit, min(r_q-x[0]-1, c_q-x[1]-1));
    }
    int up = up_limit-r_q-1;
    int down = r_q - down_limit-1;
    int left = c_q - left_limit-1;
    int right = right_limit-c_q-1;

    return up+down+left+right+ul_limit+ur_limit+dl_limit+dr_limit;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

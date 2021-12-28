#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

vector<int> add(vector<int> a, vector<int> b){
    int n = min(a.size(), b.size());
    vector<int> ans;
    int carry = 0, sum;
    for (int i=0; i<n; i++){
        sum = a[i]+b[i]+carry;
        ans.push_back(sum%10);
        carry = sum/10;
    }
    if (a.size()>n){
        for (int i=n, s=a.size(); i<s; i++){
            sum = a[i] + carry;
            ans.push_back(sum%10);
            carry = sum/10;
        }
    }

    if (b.size()>n){
        for (int i=n, s=b.size(); i<s; i++){
            sum = b[i] + carry;
            ans.push_back(sum%10);
            carry = sum/10;
        }
    }
    if (carry) ans.push_back(carry);
    return ans;
}

void extraLongFactorials(int n) {
    vector<int> product{1};
    for (int i=1; i<=n; i++){
        vector<int> buffer;
        for (int j=0; j<i; j++)
            buffer = add(buffer, product);
        product = buffer;
    }
    for (int i=product.size()-1; i>=0; --i)
        cout << product[i];
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

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

#include <bits/stdc++.h>
using namespace std;

int check_palindrome(string str){
    int n = str.size();
    int mid = n/2 - 1;

    for (int i=0, j=n-1; i<=mid && j>mid; i++, j--)
        if (str[i] != str[j]) return i;

    return -1;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        string str;
        cin >> str;

        int n = str.size();
        
        int diff = check_palindrome(str);
        if (diff == -1){
            cout << "-1\n";
        } else {
            string bak_str = str;
            bak_str.erase(bak_str.begin()+diff);
            if (check_palindrome(bak_str) == -1){
                cout << diff << "\n";
                continue;
            }

            bak_str = str;
            bak_str.erase(bak_str.begin()+n-diff-1);
            if (check_palindrome(bak_str) == -1){
                cout << n-diff-1 << "\n";
                continue;
            }
        }
    }
}
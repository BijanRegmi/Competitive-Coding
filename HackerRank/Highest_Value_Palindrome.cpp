#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    string str;

    cin >> n;
    cin >> k;
    cin >> str;

    int mid = n/2 - 1;
    int delta = 0;

    std::vector<std::array<int, 2>> costs;

    for (int i=0, j=n-1; i<=mid, j>mid; i++, j--){
        char f = str[i], b = str[j];
        std::array<int, 2> cost{0, 0};
        if (f != b){
            delta++;
            cost[1] = 1;
        }
        cost[0] = !(f == '9') + !(b == '9');
        if (i==j) cost[0] = cost[0]/2;
        // cout << "i: " << i << " j: " << j << " " << f << " and " << b << " cost: [" << cost[0] << ", " << cost[1] << "]\n";
    }

    if (delta > k){
        std::cout << -1;
        return 0;
    }

    for (int i=mid, j=n-1; i>=0, j>mid; i--, j--){
        char f = str[i], b = str[j];
        
    }
}
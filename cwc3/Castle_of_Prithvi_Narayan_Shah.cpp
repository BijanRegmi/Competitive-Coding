#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    cin.ignore();

    string arrstr;
    getline(cin, arrstr);

    if (!n){
        cout << 0;
        return 0;
    }
    
    vector<int> heightmap;

    // Converting ip string to array of integers
    int sn = arrstr.size();
    string stackstr;
    for (int i=0; i<sn; i++){
        if (arrstr[i] == ' '){
            heightmap.push_back(stoi(stackstr));
            stackstr = "";
            continue;
        }
        stackstr += arrstr[i];
    }
    heightmap.push_back(stoi(stackstr));

    // Actual program
    int castlecounter = 0;
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            bool valley = true, hill = true;
            bool plain = true;
            int prev = heightmap[i];
            for (int k=i; k<=j; k++){
                if (prev != heightmap[k]){
                    plain = false;
                    break;
                }
            }
            if (!plain) continue;
            if (i>0){
                if (heightmap[i-1]>=heightmap[i]) hill = false;
                if (heightmap[i-1]<=heightmap[i]) valley = false;
            }
            if (j<n-1){
                if (heightmap[j+1]>=heightmap[j]) hill = false;
                if (heightmap[j+1]<=heightmap[j]) valley = false;
            }
            if (valley || hill){
                castlecounter++;
                // cout << "#" << castlecounter << ": i: " << i << " j: " << j << " P: " << plain << " H: " << hill << " V: " << valley << endl;
            }
        }
    }
    cout << castlecounter;
    return 0;
}

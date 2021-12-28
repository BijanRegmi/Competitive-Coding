#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    cin.ignore();

    map<string, pair<int, int>> mapip;
    int totalcost = 0;
    for (int i=0; i<n; i++){
        string input;
        getline(cin, input);

        int h, m, s;
        string hs = input.substr(0,2), ms = input.substr(3,2), ss = input.substr(6,2), ns = input.substr(9,10);
        h = stoi(hs);
        m = stoi(ms);
        s = stoi(ss);

        int time = h*60*60+m*60+s, cost = 0;
        if (time < 300) cost = 3*time;
        else cost = 150*(ceil(time/60.f));

        mapip[ns].first += time;
        mapip[ns].second += cost;
        totalcost+=cost;
    }

    int largetime = 0, largecost = 0;
    for (auto x: mapip){
        if (largetime<x.second.first){
            largetime = x.second.first;
            largecost = x.second.second;
        }
    }
    cout << totalcost-largecost;
    return 0;
}

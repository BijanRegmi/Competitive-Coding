#include <bits/stdc++.h>

int get_min(std::vector<int> arr, bool rev){
    int n = arr.size();

    std::vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    if (rev) std::reverse(sorted.begin(), sorted.end());

    std::map<int, int> maparr;
    for (int i=0; i<n; i++) maparr[arr[i]] = i;

    int swaps = 0;
    for (int i=0; i<n; i++){
        int cv = arr[i], scv = sorted[i];
        if (cv != scv){
            swaps++;
            int idx = maparr[scv];
            arr[idx] = cv;
            maparr[cv] = idx;
        }
    }
    return swaps;

}

int main(){
    int n;
    std::cin >> n;

    int t;
    std::vector<int> arr;

    for (int i=0; i<n; i++){
        std::cin >> t;
        arr.push_back(t);
    }

    int s = get_min(arr, false);
    int sr = get_min(arr, true);

    std::cout << std::min(s, sr);
}
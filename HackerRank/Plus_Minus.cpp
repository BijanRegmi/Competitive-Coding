#include <bits/stdc++.h>

int main(){
    float n;
    std::cin >> n;

    int po = 0, ne = 0, ze = 0;

    std::setprecision(6);

    int tmp;
    for (int i = 0; i<n; i++){
        std::cin >> tmp;
        if (!tmp){
            ze++;
        } else if (tmp < 0) {
            ne++;
        } else {
            po++;
        }
    }
    std::cout << std::fixed << po/n << "\n" << ne/n << "\n" << ze/n;
}
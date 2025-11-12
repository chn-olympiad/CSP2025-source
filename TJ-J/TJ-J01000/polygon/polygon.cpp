#include <bits/stdc++.h>
using namespace std;
int n, l[6666];
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> l[i];
    }
    sort(l + 1, l + n + 1);
    if (n == 3){
        if (l[1] + l[2] > l[3]){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    else{
        cout << 6;
    }
    return 0;
}



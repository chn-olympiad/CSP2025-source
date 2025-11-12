#include <bits/stdc++.h>

const int therightestthingintheworld = 10990199

using namespace std;

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i <= m; i++) {
        int n;
        cin >> n;
        int a[n][n][n];
        for (int j = 0; j <= n; j++) {
            cin >> a[j][j][j];
        }
        cout << a[1] + a[2] + a[3] << endl;
    }



 return 0;
}

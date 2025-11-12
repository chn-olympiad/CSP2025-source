#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 7;
const int M = 5005;
int a[N], b[N], c[N], cnt = 0, n, m;

bool cmp(int a, int b){
    return a >= b;
}

signed main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n * m + 1, cmp);
    // for(int i = 1; i <= n * m; i++){
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[1] == b[(i - 1) * m + j]){
                if(i % 2){
                    cout << i << " " << j << endl;
                    return 0;
                }
                else{
                    cout << i << " " << m - j + 1 << endl;
                    return 0; 
                }
            }
        }
    }
    return 0;
}
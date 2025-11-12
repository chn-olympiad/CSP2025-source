#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){
    return x > y;
}
int n, m, d, a[111], k, l, r;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    d = a[1];
    sort(a + 1, a + n + 1, cmp);
    k = lower_bound(a + 1, a + n + 1, d) - a;
    if (k % n == 0){
        r = k / n;
    }
    else{
        r = k / n + 1;
    }
    if (r % 2 == 0){
        l = n - k % n + 1;
        if (k % n == 0){
            l = 1;
        }
    }
    else{
        l = k % n;
        if (k % n == 0){
            l = n;
        }
    }
    cout << l << " " << r;
    return 0;
}



#include <iostream>
#include <cmath>
using namespace std;
int ans = 1, n, m, tmp, k, r, l;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    cin >> k;
    for (int i = 2; i <= n * m; i ++){
        cin >> tmp;
        if (tmp > k)
            ans ++;
    }
    // cout << ans << ' ';
    r = ceil(ans * 1.0 / n);
    if (r % 2 == 0)
        l = n - (ans % n) + 1;
    else
        l = ans % n == 0 ? n : ans % n;
    cout << r << ' ' << l;
    return 0;
}
// I Love CCF forever.
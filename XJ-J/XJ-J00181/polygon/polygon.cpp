#include <iostream>
#include <algorithm>
//haihaihai_Long_Live_the_People's_Republic_of_China!!!
#define mod %998244353
using std::cin;
using std::cout;
const int N = 5005;
int n, a[N], f[N], ans;
void dfs(int sum, int now){
    if (now > n)
        return;
    if (sum > a[now])
        ans = (ans + 1) mod;
    dfs(sum + a[now], now + 1);
    dfs(sum, ++now);
}
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    std::sort(a + 1, a + n + 1);
    if (a[n] == 1){
        for (int i = 3; i <= n; i++){
            int sum = 1;
            for (int j = 0; j < i; j++)
                sum = sum * (n - j) mod;
            for (int j = 1; j <= i; j++)
                sum = sum / j mod;
            ans = (ans + sum) mod;
        }
    }
    else
        dfs(0, 1);
    cout << ans mod << '\n';
}
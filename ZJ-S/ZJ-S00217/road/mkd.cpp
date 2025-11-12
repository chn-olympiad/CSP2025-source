#include <bits/stdc++.h>
using namespace std;
mt19937 mt(time(0));
int rnd(int l, int r){
    return uniform_int_distribution<int>{l, r}(mt);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n = 1e4, m = 1e6, k = 10;
    cout << n << " " << m << " " << k << endl;
    while (m--)
        cout << rnd(1, n) << " " << rnd(1, n) << " " << rnd(1, 1e9) << endl;
    while (k--){
        cout << rnd(1, 1e9) << " ";
        for (int i = 1; i <= n; ++i)cout << rnd(1, 1e9) << " ";
        cout << endl;
    }
    return 0;
}
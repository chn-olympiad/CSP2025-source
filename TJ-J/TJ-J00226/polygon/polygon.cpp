#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int n;
int a[N];
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    if (n == 3){
        int sum = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            sum += a[i];
        }
        sort(a + 1, a + n + 1, greater<int>());
        if (a[1] * 2 < sum){
            cout << 1 % 998244353;
        }else {
            cout << 0 % 998244353;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
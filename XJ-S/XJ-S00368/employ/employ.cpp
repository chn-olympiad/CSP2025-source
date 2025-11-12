#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m;
char ch[505];
int c[505];
bool cmp(int x, int y){
    return x > y;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> ch;
    int flag1 = 0;
    for(int i = 1; i <= n; ++ i){
        cin >> c[i];
        if(c[i] != 0) flag1 ++;
    }
    int flag = 0;
    for(int i = 0; i < strlen(ch); ++ i){
        if(ch[i] == '0'){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        if(flag1 < m){
            cout << 0;
            return 0;
        }
        long long ans = 1;
        for(int j = m; j <= flag1; ++ j){
            for(int i = flag1 - j + 1; i <= flag1 - 1; ++ i){
                ans *= i;
                ans %= mod;
            }
        }
        ans *= (n - flag1);
        ans *= mod;
        cout << ans;
    }
    return 0;
}
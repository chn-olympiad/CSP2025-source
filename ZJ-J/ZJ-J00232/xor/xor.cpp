#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define endl '\n'

using namespace std;
using LL = long long;

const int N = 5e5+5;
LL a[N], n, k;

int main(){

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    IOS
    cin >> n >> k;
    for(int i = 1; i <= n; i ++)cin >> a[i];
    LL ans = 0, l = 1;//左指针从1开始
    for(int i = 1; i <= n; i ++){
        LL x = a[i];
        if(x == k){
            ans ++;
            l = i+1;
            continue;
        }
        for(int j = i-1; j >= l; j--){
            x ^= a[j];
            if(x == k){
                ans ++;
                l = i+1;
                break;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
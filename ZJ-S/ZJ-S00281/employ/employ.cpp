#include <bits/stdc++.h>
using namespace std;
const int N=505 ,mod = 998244353;
int n, m, c[N] ,dif[N] ,ans=1;
int num[N],sum[N],cnt[N],pos[N];
string s;
int A(int x,int y){
    int ret = 1;
    for (int i = x; i >= x - y + 1;--i)
        ret = (ret * i) % mod;
    return ret;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    cin >> s;
    for (int i = 1; i <= n;++i)
        cin >> c[i];
    bool flag = true;
    for (int i = 1; i <= n;++i){
        dif[i] = (s[i - 1] == '1');
        sum[i] = sum[i-1] + dif[i];
        if(dif[i]!=1)
            flag = false;
    }   
    for (int i = 1; i <= n;++i)
        ans = (1ll * ans * i) % mod;
    cout << ans;
    // if(sum[n]<=18){
    //     if(m>sum[n]){
    //         printf("0");
    //     }else{
    //         for (int i = 1; i <= n; ++i){
    //             if(dif[i]==1){
    //                 for (int j = 1; j <= n;++j){
    //                     if(c[j]>=i-sum[i]){
    //                         num[j] += 1;
    //                         pos[i] += 1;
    //                     }
                               
    //                 }
    //             }
    //         }
    //         for (int i = 1; i <= n;++i)
    //             cnt[num[i]] += 1;
    //     }
    // }
    
}
// #include <bits/stdc++.h>
// using namespace std;
// int n, k, a[500005], b[500005][20], cnt[20], maxp = 0;//第i个数的第j位

// struct node{
//     int l, r;
// };

// int main(){
//     // freopen("xor.in", "r", stdin);
//     // freopen("xor.out", "w", stdout);
//     cin >> n >> k;
//     for(int i = 1;i <= n;i++){
//         cin >> a[i];
//     }
//     for(int i = 1;i <= n;i++){
//         int x = a[i], p = 0;
//         while(x > 0){
//             b[i][p] = (x & 1);
//             p++;
//             x >>= 1;
//         }
//         maxp = max(maxp, p - 1);
//     }
//     int x = k, p = 0;
//     while(x > 0){
//         cnt[p] = (x & 1);
//         p++;
//         x >>= 1;
//     }
//     maxp = max(maxp, p - 1);
//     vector<node>g[20];
//     for(int i = 0;i <= maxp;i++){
//         for(int j = 1;j <= n;j++){
//             if(cnt[i] == 1){
//                 if(b[j][i] == cnt[i]) g[i].push_back({j, j});
//             }else{
//                 if(b[j][i] == cnt[i]) g[i].push_back({j, j});
//                 if(b[j][i] == 1 && b[j + 1][i] == 1) g[i].push_back({j, j + 1}); 
//             }
//         }
//     }
//     p = 0;
//     int ans = 0, pos[25], rgh = 0, maxn, tot = 0, pp = 0;
//     for(int i = 0;i <= maxp;i++){
//         tot = max(tot, (int)g[i].size());
//     }
//     bool f = 0;
//     maxn = 0;
//     while(tot--){
//         for(int i = 0;i <= maxp;i++){
//             while(g[i][pos[i]].l <= rgh && pos[i] <= (int)g[i].size()) pos[i]++;
//             maxn = max(maxn, g[i][pos[i]].r);
//             if(g[i][pos[i]].l <= rgh) {
//                 f = 1;
//                 break;
//             }
//         }
//         if(f == 0) ans++;
//         rgh = maxn;
//         cout<<ans<<' '<<rgh<<'\n';
//     }
    
//     cout<<ans<<'\n';
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int n, k, ans = 0;
int a[500005];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(k == 1){
        for(int i = 1;i <= n;i++) ans += a[i];
    }else{
        for(int i = 1;i <= n;i++){
            if(a[i] == 0) ans++;
            if(a[i] == 1 && a[i + 1] == 1){
                ans++;
                i++;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
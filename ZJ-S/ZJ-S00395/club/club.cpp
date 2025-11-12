// 真的要AFO了 

#include <bits/stdc++.h>
#define fr {freopen("club.in","r",stdin);freopen("club.out","w",stdout);}
#define qr {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define int long long
#define N 100005
using namespace std;

int n;
int sa[N][4];
int vis[N];

int dfs(int k1,int k2,int k3,int ans_n){
    int nxt_ans = ans_n;
    if(k1 + k2 + k3 >= n) return ans_n;
    for(int i = 1;i <= n;i++){
        if(vis[i]) continue;
        if(k1 <= (n/2)-1){
            vis[i] = 1;
            int res = dfs(k1+1,k2,k3,ans_n + sa[i][1]);
            nxt_ans = max(nxt_ans,res);
            vis[i] = 0;
        }
        if(k2 <= (n/2)-1){
            vis[i] = 1;
            int res = dfs(k1+1,k2,k3,ans_n + sa[i][1]);
            nxt_ans = max(nxt_ans,res);
            vis[i] = 0;
        }
        if(k3 <= (n/2)-1){
            vis[i] = 1;
            int res = dfs(k1+1,k2,k3,ans_n + sa[i][1]);
            nxt_ans = max(nxt_ans,res);
            vis[i] = 0;
        }
    }
    return nxt_ans;
}

signed main(){
    fr;
    qr;
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 3;j++) cin >> sa[i][j];
        }
        memset(vis,0,sizeof vis);
        cout << dfs(0,0,0,0) << '\n';
    }
    return 0;
}

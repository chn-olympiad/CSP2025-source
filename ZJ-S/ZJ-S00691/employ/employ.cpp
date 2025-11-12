#include<bits/stdc++.h>
using namespace std;
// const int N = 1e5 + 5;
#define LL long long
const int N = 2e3 + 5;
LL n,m;
LL c[N], a[N], b[N];
bool vis[N];
LL ans = 0;
void dfs(int x){
    if(x==n+1){
        int lst = 0, w = 0;
        for (int i = 1; i <= n;i++){
            if(!a[i]||w>=c[b[i]]) w++;
            if(i-w==m){ans++;return;}
        }
        return;
        // if(n-w==m){ans++;return ;}
    }
    for (int i = 1; i <= n;i++)
        if(!vis[i])
            b[x] = i, vis[i] = 1, dfs(x + 1), vis[i] = 0;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    bool fl = 1;
    for (int i = 1; i <= n;i++){
        char s;
        cin >> s;
        a[i] = s - '0';
        if(a[i])
            fl = 0;
    }
    if(fl){
        if(m==0){
            int ans=1;
            for (int i = 1; i <= n;i++)
                ans = 1ll * ans * i % 998244353;
        }
        else cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    dfs(1);
    cout << ans;
    return 0;
}
/*
3 2
101
1 1 2


10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/

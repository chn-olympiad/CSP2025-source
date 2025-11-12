#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,e[100005][3],ans;
void dfs(int p,int num,int a,int b,int c) {
    if (p == n + 1) {
        ans = max(ans,num);
        return ;
    }
    if (a < (n / 2)) {
        dfs(p + 1,num + e[p][0],a + 1,b,c);
    }
    if (b < (n / 2)) {
        dfs(p + 1,num + e[p][1],a,b + 1,c);
    }
    if (c < (n / 2)) {
        dfs(p + 1,num + e[p][2],a,b,c + 1);
    }
}
signed main() {
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> e[i][0] >> e[i][1] >> e[i][2];
        }
        dfs(1,0,0,0,0);
        cout << ans << "\n";
    }
    return 0;
}
//written by Lxsh1203

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5 + 5;
int t, n, a[N][3], diff[N];
vector<int> v[3];
bool cmp(int x, int y) { return diff[x] < diff[y]; }
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 0; i < 3;i++) v[i].clear();
        int ans = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
            int mx = max({a[i][0], a[i][1], a[i][2]});
            int mn = min({a[i][0], a[i][1], a[i][2]}), md = a[i][0] + a[i][1] + a[i][2] - mx - mn;
            ans += mx;
            for (int j = 0; j < 3;j++)
                if(mx==a[i][j]) {
                    v[j].pb(i), diff[i] = mx - md;
                    break;
                }
        }
        int pos = -1;
        for (int i = 0; i < 3;i++) if(v[i].size()>n/2) pos = i;
        if(pos!=-1){
            sort(v[pos].begin(), v[pos].end(), cmp);
            for (int i = 0; i < v[pos].size() - n / 2;i++)
                ans -= diff[v[pos][i]];
        }
        printf("%d\n", ans);
    }
    return 0;
}
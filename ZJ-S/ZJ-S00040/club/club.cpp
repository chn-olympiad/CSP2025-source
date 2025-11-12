#include<bits/stdc++.h>
#define PII pair<int,int>
#define pb push_back
using namespace std;
const int Maxn = 1e5 + 10;
int a[Maxn][4];
int b[Maxn];
int d[Maxn], D[Maxn];
int f[Maxn];
bool cmp(int a, int b){
    return a > b;
}
void work(){
    int n;
    cin >> n;
    int c[4];
    c[1] = c[2] = c[3] = 0;
    vector<int> p[4];
    for(int i = 1; i <= n; i++){
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        int mx=max({a[i][1], a[i][2],a[i][3]});
        if(mx == a[i][1]){
            b[i] = 1; c[1]++;
            p[1].pb(i);
        }
        else if(mx == a[i][2]){
            b[i] = 2; c[2]++;
            p[2].pb(i);
        }else {
            b[i] = 3; c[3]++;
            p[3].pb(i);
        }
    }
    if(c[1] <= n / 2 and c[2] <= n / 2 and c[3] <= n / 2){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int mx=max({a[i][1], a[i][2],a[i][3]});
            ans += mx;
        }
        cout << ans << '\n'; return ;
    } 
    int ans = 0;
    for(int k = 1; k <= 3; k++){
        if(c[k] > n / 2){
            int cnt = 0;
            for(int i = 1; i <= n; i++){
                if(b[i] == k){
                    if(b[i] == 1){
                        d[++cnt] = a[i][b[i]] - max(a[i][2], a[i][3]);
                        D[i] = a[i][b[i]] - max(a[i][2], a[i][3]);
                    }else if(b[i] == 2){
                        d[++cnt] = a[i][2] - max(a[i][1], a[i][3]);
                        D[i] = a[i][2] - max(a[i][1], a[i][3]);
                    }else {
                        d[++cnt] = a[i][3] - max(a[i][2], a[i][1]);
                        D[i] = a[i][3] - max(a[i][2], a[i][1]);
                    }
                }
            }
            sort(p[k].begin(), p[k].end(), [&](int a, int b){return D[a] > D[b];});
            cnt = 0;
            int i;
            for(int i = 0; i < n / 2; i++){
                ans += a[p[k][i]][k];
            }
            for(int i = n / 2; i < c[k]; i++){
                ans += a[p[k][i]][k] - D[p[k][i]];
            }
            for(int i = 1; i <= n; i++){
                if(b[i] != k)
                    ans += a[i][b[i]];
            }
            cout << ans << '\n'; return ;
        }
    }
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        work();
    }
}
// 来玩『魔法少女的魔女审判』xxm.
// freopen freopen("club.in","w",stdin);
//freopen("club.in",'r',stdin);
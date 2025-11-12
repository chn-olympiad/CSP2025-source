#include<bits/stdc++.h>
// #define int long long
using namespace std;
int read(){
    int s = 0, f = 1;
    signed c = getchar();
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -f;
    for(; isdigit(c); c = getchar()) s = (s * 10) + (c ^ 48);
    return s * f;
}
void write(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar('0' + x % 10);
    return;
}
const int N = 1e5 + 10,
        inf = 1e9;
int n, a[N][3], mx[N], se[N];
priority_queue<pair<int, int> > pq[3];
void solve(){
    n = read();
    for(int i = 0; i < 3; ++ i)
        for(; pq[i].size();) pq[i].pop();
    for(int i = 1; i <= n; ++ i)
        a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        int mxid = 0, seid = 0, mxv = -1, sev = -1;
        for(int j = 0; j < 3; ++ j){
            if(a[i][j] > mxv){
                sev = mxv;
                seid = mxid;
                mxv = a[i][j];
                mxid = j;
            }else if(a[i][j] > sev){
                sev = a[i][j];
                seid = j;
            }
        }
        mx[i] = mxid, se[i] = seid;
    }
    for(int i = 1, tid; i <= n; ++ i){
        pq[mx[i]].emplace(a[i][se[i]] - a[i][mx[i]], i);
        ans += a[i][mx[i]];
        if(pq[mx[i]].size() > (n >> 1)){
            tid = pq[mx[i]].top().second; 
            ans += pq[mx[i]].top().first;
            pq[mx[i]].pop();
            pq[se[tid]].emplace(-inf, tid);
        }
    }
    write(ans);
    puts("");
    return;
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    for(int T = read(); T --;)
        solve();
    return 0;
}
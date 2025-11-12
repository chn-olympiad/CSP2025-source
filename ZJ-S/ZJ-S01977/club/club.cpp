#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, a[N][3], buc[3], ans, bel[N];
priority_queue<int> pq;
inline void chkmax(int &x, int y) {
    if(x < y) x = y;
}
inline void solve() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
        int p = max_element(a[i], a[i] + 3) - a[i];
        buc[p]++, ans += a[i][p];
        bel[i] = p;
    }
    int p = max_element(buc, buc + 3) - buc;
    int tar = buc[p] - (n / 2);
    for(int i = 1; i <= n; i++) if(bel[i] == p){
        int semx = 0;
        for(int o : {0, 1, 2}) if(o ^ p) chkmax(semx, a[i][o]);
        pq.emplace(semx - a[i][p]);
    }
    while(tar > 0 && !pq.empty()) {
        ans += pq.top(), pq.pop(), tar--;
    }
    printf("%d\n", ans);
}
inline void clr() {
    while(!pq.empty()) pq.pop();
    buc[0] = buc[1] = buc[2] = 0;
    ans = 0;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--) {
        solve(), clr();
    }
    return 0;
}
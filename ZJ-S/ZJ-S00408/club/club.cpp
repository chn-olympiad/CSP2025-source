#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, t, sa, sb, sc, ans;
struct node {
    int x, y, z, s, id;
}a[N];
bool cmp(node p, node q) {
    return p.s > q.s;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
            if(a[i].x >= a[i].y && a[i].x >= a[i].z) {
                a[i].id = 1;
                a[i].s = a[i].x - max(a[i].y, a[i].z);
            }
            if(a[i].y >= a[i].x && a[i].y >= a[i].z) {
                a[i].id = 2;
                a[i].s = a[i].y - max(a[i].x, a[i].z);
            }
            if(a[i].z >= a[i].x && a[i].z >= a[i].y) {
                a[i].id = 3;
                a[i].s = a[i].z - max(a[i].x, a[i].y);
            }
        }
        sort(a + 1, a + n + 1, cmp);
        sa = sb = sc = ans = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i].id == 1) {
                if(sa == n / 2) ans += max(a[i].y, a[i].z);
                else sa++, ans += a[i].x;
            }
            if(a[i].id == 2) {
                if(sb == n / 2) ans += max(a[i].x, a[i].z);
                else sb++, ans += a[i].y;
            }
            if(a[i].id == 3) {
                if(sc == n / 2) ans += max(a[i].x, a[i].y);
                else sc++, ans += a[i].z;
            }
//            printf("%d %d %d\n", ans, a[i].id, a[i].s);
        }
        printf("%d\n", ans);
    }
}
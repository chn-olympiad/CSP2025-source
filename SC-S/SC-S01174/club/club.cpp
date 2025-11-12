#include <bits/stdc++.h>
#define db(x...) fprintf(stderr,x)
const int N = 1e5 + 10;
struct Node {
    int x, y, z;
}stk[4][N], tmp[4];
int tot[4], n, T;
bool cmp1 (Node x, Node y) { return x.x > y.x; }
bool cmp2 (Node x, Node y) { return x.x - x.y > y.x - y.y; }
int main () {
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    scanf ("%d", &T);
    while (T--) {
        tot[1] = tot[2] = tot[3] = 0;
        int ans = 0;
        scanf ("%d", &n);
        for (int i = 1; i <= n; i++) {
            int x, y, z;
            scanf ("%d%d%d", &x, &y, &z);
            tmp[1] = (Node) {x, 0, 1}, tmp[2] = (Node) {y, 0, 2}, tmp[3] = (Node) {z, 0, 3};
            std::sort (tmp + 1, tmp + 3 + 1, cmp1);
            stk[tmp[1].z][++tot[tmp[1].z]] = (Node) {tmp[1].x, tmp[2].x};
            // printf ("i = %d  x = %d\n", i, tmp[1].x);
            ans += tmp[1].x;
        }
        for (int i = 1; i <= 3; i++) {
            if (tot[i] > n / 2) {
                std::sort (stk[i] + 1, stk[i] + tot[i] + 1, cmp2);
                while (tot[i] > n / 2) {
                    ans = ans - stk[i][tot[i]].x + stk[i][tot[i]].y;
                    // printf ("%d %d\n", stk[i][tot[i]].x, stk[i][tot[i]].y);
                    tot[i]--;
                }
                break;
            }
        }
        printf ("%d\n", ans);
    }
    fclose (stdin);
    fclose (stdout);
    return 0;
}
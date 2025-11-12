#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1001];

bool cmp(int x, int y) {
    return x > y;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++) {
        scanf ("%d", &a[i]);
    }
    int rr = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = 1; i <= n * m; i++) {
        if (a[i] == rr) {
            rr = i;
        }
    }
    int xn = 0, ym = 1, change = 0;
    for (int i = 1; i <= rr; i++) {
        if (change == 0) {
            xn++;
        }
        else if (change == 1) {
            xn--;
        }
        if (xn == n + 1) {
            xn = n;
            ym++;
            change = 1;
        }
        else if (xn == 0) {
            xn = 1;
            ym++;
            change = 0;
        }
    }
    printf ("%d %d", ym, xn);
    return 0;
}


































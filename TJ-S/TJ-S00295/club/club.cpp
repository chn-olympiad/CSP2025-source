#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int T;
int n;
int a[N][3];
int c[N];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while (T -- ) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ ) scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);

        int sum = 0;

        int tot1 = 0, tot2 = 0, tot3 = 0;
        for (int i = 1; i <= n; i ++ ) {
            int k = max(a[i][0], max(a[i][1], a[i][2]));
            sum += k;
            if (k == a[i][0]) tot1 ++ ;
            else if (k == a[i][1]) tot2 ++ ;
            else tot3 ++ ;
        }

        int k = max(tot1, max(tot2, tot3));

        if (k <= n / 2) {printf("%d\n", sum); continue;}

        if (k == tot1) k = 0;
        else if (k == tot2) k = 1;
        else k = 2;

        int tot = 0;
        for (int i = 1; i <= n; i ++ ) {
            int tmp = max(a[i][0], max(a[i][1], a[i][2]));
            if (a[i][k] == tmp) c[ ++ tot] = tmp - max(a[i][(k + 1) % 3], a[i][(k + 2) % 3]);
        }

        sort(c + 1, c + tot + 1);
        for (int i = 1; i <= tot - n / 2; i ++ ) sum -= c[i];

        printf("%d\n", sum);
    }

    return 0;
}

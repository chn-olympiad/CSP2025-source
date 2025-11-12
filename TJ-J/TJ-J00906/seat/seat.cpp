#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, b[15][15], E;
struct qq {
    int x, i;
} a[105];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int u = n * m;
    for(int i = 1; i <= u; i++) {
        scanf("%d", &a[i].x);
        a[i].i = i;
    }
    sort(a + 1, a + u + 1, [](qq x, qq y) {return x.x > y.x;});
    for(int i = 1; i <= m; i++) {
        if(i & 1) {
            for(int j = 1; j <= n; j++)b[j][i] = ++E;
        } else for(int j = n; j >= 1; j--)b[j][i] = ++E;
    }
    int nw = 0;
    for(int i = 1; i <= u; i++) {
        if(a[i].i == 1) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= m; k++) {
                    if(b[j][k] == i) {
                        printf("%d %d\n", k, j);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}


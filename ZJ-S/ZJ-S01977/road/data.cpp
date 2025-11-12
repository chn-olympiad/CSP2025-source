#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(random_device{}());
uniform_int_distribution<int> rd(1, 10);
uniform_int_distribution<int> rd2(1, 1000000000);
int main() {
    freopen("road.in", "w", stdout);
    int n = 10000, m = 1000000, k = 10;
    srand(random_device{}());
    printf("%d %d %d\n", n, m, k);
    for(int i = 1; i < n; i++) {
        printf("%d %d %d\n", rand() % i + 1, i + 1, rd(rnd));
        m--;
    }
    while(m--) {
        printf("%d %d %d\n", rand() % n + 1, rand() % n + 1, rd(rnd));
    }
    while(k--) {
        printf("%d ", rd2(rnd));
        for(int i = 1; i <= n; i++) printf("%d ", rd2(rnd));puts("");
    }
    return 0;
}
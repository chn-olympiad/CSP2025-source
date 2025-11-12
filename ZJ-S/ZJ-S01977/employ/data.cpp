#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("employ.in", "w", stdout);
    srand(random_device{}());
    int n = rand() % 10 + 1, m = rand() % (n + 1);
    n = rand() % 3 + 1, m = rand() % n + 1;
    printf("%d %d\n", n, m);
    for(int i = 1; i <= n; i++) printf("%d", rand() & 1);puts("");
    // for(int i = 1; i <= n; i++) printf("%d", 1);puts("");
    for(int i = 1; i <= n; i++) printf("%d ", rand() % (n + 1));puts("");
    return 0;
}
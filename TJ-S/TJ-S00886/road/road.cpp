#include <bits/stdc++.h>
constexpr int N = 1e4 + 5;
constexpr int M = 1e6 + 5;

void add(int u, int v, int w)
{
    ;
}

int main ()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i=1; i<=m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    std::queue<> q;
    q.push();
}
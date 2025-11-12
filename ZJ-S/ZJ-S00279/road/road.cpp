#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long u64;
typedef long long i64;

u64 n, m, k, c[20];

struct edge {
    u64 v, w, next;
}e[20000010];

u64 head[10100];

void add(u64 u, u64 v, u64 w) {
    static u64 cnt = 0;
    cnt++;
    e[cnt] = {v, w, head[u]};
    head[u] = cnt;
}

struct node {
    u64 v, dis;
};

u64 dis[10100];

u64 getdis(const node &x) {
    u64 res = x.dis;
    if (x.v > n)
        res += c[x.v - n];
    return res;
}

u64 getsk(u64 cf) {
    u64 res = 0;
    for (u64 i = 1; i <= k; i++)
        if ((cf >> i) & 1)
            res += c[i];
    return res;
}

bool operator<(const node &a, const node &b) {
     return getdis(a) > getdis(b);
}

bitset<10100> vis;
u64 cnt, ans, cf;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%llu%llu%llu", &n, &m, &k);
    for (u64 i = 1, u, v, w; i <= m; i++)
        scanf("%llu%llu%llu", &u, &v, &w), add(u, v, w), add(v, u, w);
    for (u64 i = 1, a; i <= k; i++) {
        scanf("%llu", &c[i]);
        for (u64 j = 1; j <= n; j++)
            scanf("%llu", &a), add(n + i, j, a), add(j, n + i, a);
    }
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    priority_queue<node> q;
    q.push({1, 0});
    while (cnt < n) {
        node x = q.top();
        q.pop();
        if (cnt < n && !vis[x.v]) {
            ans += x.dis;
            cnt += x.v <= n;
            if (x.v > n)
                cf |= 1 << (x.v - n);
            vis[x.v] = true;
        } else continue;
        for (u64 j = head[x.v]; j; j = e[j].next) {
            u64 v = e[j].v, w = e[j].w;
            u64 ndis = w;
            q.push({v, ndis});
        }
    }
    printf("%llu\n", ans + getsk(cf));
}

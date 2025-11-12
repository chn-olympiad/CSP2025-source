// Go in my style.
// Not afraid to dark.
// Beat.

#include <bits/stdc++.h>
using namespace std;

#define int long long

namespace io {
    int pos;
    inline int read(int &p = pos) {
        static int v; static char c;
        p = 0, v = 1, c = getchar();
        while (!isdigit(c)) {
            if (c == '-') v = -1;
            c = getchar();
        }
        while (isdigit(c)) {
            p = (p << 1) + (p << 3) + (c - 48);
            c = getchar();
        }
        return p = v == 1 ? p : -p;
    }
    inline void write(int x) {
        static int sta[65], top;
        if (x < 0) x = -x, putchar('-');
        top = 0;
        do {
            sta[++top] = x % 10;
            x /= 10;
        } while(x);
        while (top) putchar(sta[top--] + 48);
    }
}

const int N = 2e4, M = 1.5e6, Q = 12;
int n, m, q;
struct Eg {
    int u, v, w;
    Eg(int _u_ = 0, int _v_ = 0, int _w_ = 0) {
        u = _u_;
        v = _v_;
        w = _w_;
    }
} Rd[M + 5], Fd[Q + 1][N + 5];
int cnt[Q + 1], idx[Q + 1], c[Q + 1];

auto cmp = [](const Eg &a, const Eg &b) { return a.w < b.w; };

int fa[N + Q + 5];
inline void init() {
    for (int i = 1; i <= n + q; ++i) fa[i] = i;
}
int find(int v) {
    if (v == fa[v]) return v;
    return fa[v] = find(fa[v]);
}
inline bool Merge(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
        fa[v] = u;
        return true;
    }
    return false;
}

inline void ARKNIGHTS() {
    io::read(n), io::read(m), io::read(q);
    for (int i = 1; i <= m; ++i)
        io::read(Rd[i].u), io::read(Rd[i].v), io::read(Rd[i].w);

    sort(Rd + 1, Rd + m + 1, cmp);
    init();
    for (int i = 1; i <= m; ++i)
        if (Merge(Rd[i].u, Rd[i].v))
            Fd[q][++cnt[q]] = Rd[i];

    for (int i = 0; i < q; ++i) {
        io::read(c[i]);
        for (int j = 1; j <= n; ++j) {
            Fd[i][j] = Eg(n + 1 + i, j, 0);
            io::read(Fd[i][j].w);
        }
        sort(Fd[i] + 1, Fd[i] + n + 1, cmp);
        cnt[i] = n;
    }

    int ans = 0x3f3f3f3f3f3f3f3f;
    for (int tmps = 0; tmps < (1 << q); ++tmps) {
        int s = (tmps | (1 << q));
        for (int i = 0; i <= q; ++i) idx[i] = 1;

        int res = 0;
        for (int i = 0; i < q; ++i) if (s >> i & 1) res += c[i];
        init();
        while (true) {
            for (int i = 0; i <= q; ++i)
                if (s >> i & 1) {
                    while (idx[i] <= cnt[i]) {
                        Eg e = Fd[i][idx[i]];
                        if (find(e.u) == find(e.v)) ++idx[i];
                        else break;
                    }
                }
            int mnw = 0x3f3f3f3f3f3f3f3f, mni = -1;
            for (int i = 0; i <= q; ++i)
                if ((s >> i & 1) && idx[i] <= cnt[i] && Fd[i][idx[i]].w < mnw) {
                    mnw = Fd[i][idx[i]].w;
                    mni = i;
                }
            if (mni == -1) break;
            res += mnw;
            Eg e = Fd[mni][idx[mni]];
            Merge(e.u, e.v);
            ++idx[mni];
        }
        ans = min(ans, res);
    }
    io::write(ans), putchar('\n');
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    for (int T = 1; T--; ARKNIGHTS()) ;
    return 0;
}
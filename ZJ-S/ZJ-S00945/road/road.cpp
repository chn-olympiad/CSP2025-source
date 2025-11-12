#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define REP(i, l, r)    for(int (i) = (l);(i) <= (r);(i)++)
#define DEP(i, r, l)    for(int (i) = (r);(i) >= (l);(i)--)
#define pb push_back

void read(){}
template<typename T1, typename ...T2>inline void read(T1 &x, T2 &...oth) {
    x = 0;
    int ch = getchar(), f = 0;
    while(ch < '0' or '9' < ch) {
        if (ch == '-')  f = 1;
        ch = getchar();
    }
    while('0' <= ch and ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    if (f)  x = -x;
    read(oth...);
    return;
}

void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x <= 9) return putchar(x + '0'), void();
    write(x / 10);
    putchar(x % 10 + '0');
    return;
}

namespace YZLK{
    const int N = 1e4 + 100;
    const int M = 2e6 + 100;
    int n, m, k;
    struct node{
        int u, v, w;
    }a[M], ans[M], ed[M];
    int len, ln;
    bool vis[15];
    struct nd{
        int c[N];
    }c[15];
    struct dsu{
        int fa[N];
        void init(int x) {
            REP(i, 0, x)    fa[i] = i;
            return;
        }
        int find(int x) {
            if (fa[x] == x) return fa[x];
            return fa[x] = find(fa[x]);
        }
        bool merge(int x, int y) {
            int u = find(x), v = find(y);
            if (u == v) return 0;
            fa[u] = v;
            return 1;
        }
    }d1;
    void solve1() {
        REP(i, 1, k) {
            REP(j, 1, n) {
                a[++m] = {i + n, j, c[i].c[j]};
            }
        }
        n += k;
        sort(a + 1, a + m + 1, [](node a, node b) {
            return a.w < b.w;
        });
        d1.init(n);
        int cnt = 0, sum = 0;
        REP(i, 1, m) {
            if (cnt == n - 1)   break;
            if (d1.merge(a[i].u, a[i].v)) {
                cnt++;
                sum += a[i].w;
            }
        }
        cout << sum << "\n";
        return;
    }
    void main() {
        read(n, m, k);
        REP(i, 1, m)    read(a[i].u, a[i].v, a[i].w);
        bool flag = 1;
        REP(i, 1, k) {
            REP(j, 0, n)    read(c[i].c[j]);
            if (c[i].c[0] != 0) flag = 0;
        }

        if (flag) {
            solve1();
            return;
        }

        sort(a + 1, a + m + 1, [](node a, node b) {
            return a.w < b.w;
        });
        d1.init(n);
        int cnt = 0, sum = 0, s1 = 0;
        len = 0;
        REP(i, 1, m) {
            if (cnt == n - 1)   break;
            if (d1.merge(a[i].u, a[i].v)) {
                cnt++;
                sum += a[i].w;
                ans[++len] = a[i];
            }
        }


        len = 0;
        REP(i, 1, m) {
            ans[++len] = a[i];
        }



        // s1 = sum;
        // REP(i, 1, k) {
        //     ln = 0;
        //     int ss = 0;
        //     ss += c[i].c[0];
        //     REP(p, 1, n) {
        //         ed[++ln] = {n + 1, p, c[i].c[p]};
        //     }
        //     if (ss >= sum)  continue;
        //     REP(j, 1, len)  ed[++ln] = ans[j];
        //     // cout << ln << "\n";
        //     sort(ed + 1, ed + ln + 1, [](node a, node b) {
        //         return a.w < b.w;
        //     });
        //     d.init(n + 1);
        //     cnt = 0;
        //     REP(j, 1, ln) {
        //         if (cnt == n)   break;
        //         if (ss >= sum)     break;
        //         if (d1.merge(ed[j].u, ed[j].v)) {
        //             cnt++;
        //             ss += ed[j].w;
        //         }
        //         // cout << ed[j].u << " " << ed[j].v << " " << ed[j].w << "\n";
        //     }
        //     if (ss < s1)    vis[i] = 1;
        //     sum = min(sum, ss);
        // }

        REP(i, 1, (1ll << k) - 1) {
            ln = 0;
            int ss = 0;
            // bool flag = 1;
            int cnt = 0;
            // REP(j, 1, k) {
            //     // if (((i >> (j - 1)) & 1) and !vis[j])   {flag = 0;break;}
            //     if ((i >> (j - 1)) & 1) cnt++;
            // }
            // if (!flag)      continue;
            // if (cnt == 1)   continue;
            // cnt = 0;
            REP(j, 1, k) {
                if ((i >> (j - 1)) & 1) {
                    cnt++;
                    ss += c[j].c[0];
                    REP(p, 1, n) {
                        ed[++ln] = {n + cnt, p, c[j].c[p]};
                    }
                }
            }
            if (ss >= sum)  continue;
            REP(j, 1, len)  ed[++ln] = ans[j];
            // cout << ln << "\n";
            sort(ed + 1, ed + ln + 1, [](node a, node b) {
                return a.w < b.w;
            });
            d1.init(n + cnt);
            REP(j, 1, ln) {
                if (cnt == n + cnt - 1)   break;
                if (ss >= sum)     break;
                if (d1.merge(ed[j].u, ed[j].v)) {
                    cnt++;
                    ss += ed[j].w;
                }
                // cout << ed[j].u << " " << ed[j].v << " " << ed[j].w << "\n";
            }
            // cout << i << " " << ss << "\n";
            sum = min(sum, ss);
        }
        cout << sum << "\n";
        return;
    }
}

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int T = 1;
    // read(T);
    while(T--) {
        YZLK::main();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
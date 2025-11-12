#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define int long long

// I tried to remove the log but I think maybe a log is fine.
// NO IT'S NOT FINE
// T2 finished: 47min.

inline bool checkchar(char c) {
    return isspace(c) || c == EOF;
}

template<typename T>
T qread_templ() {
    T val = 0;
    char c; bool inv = false;
    while (!isdigit(c = getchar()));
    if (c == '-') {
        inv = true;
        c = getchar();
    }
    do val = (val << 1) + (val << 3) + (c - '0');
    while (isdigit(c = getchar()));
    return inv ? (-val) : val;
}
char qwrite_buf[50];
template<typename T>
void qwrite(T val) {
    if (val < 0) {
        putchar('-');
        val = -val;
    }
    if (val < 10) {
        putchar('0' + val);
        return;
    }
    int n = 0;
    while (val) {
        T d = val / 10;
        qwrite_buf[n++] = (char) (val - (d << 1) - (d << 3) + '0');
        val = d;
    }
    while (n--) {
        putchar(qwrite_buf[n]);
    }
}
inline int qread() {
    return qread_templ<int>();
}
int readstr(char *s) {
    int n = 0; char c;
    while (isspace(c = getchar()));
    do s[n++] = c; while (!checkchar(c = getchar()));
    s[n] = '\0';
    return n;
}
char getgood() {
    char c;
    while (isspace(c = getchar()));
    return c;
}

#define MAXN (10000+4)
#define MAXM (1000000+4)
#define MAXK (12)

int n, m, k;
struct Road {
    int u, v, w;
    bool operator<(Road const &rhs) const {
        return w < rhs.w;
    }
} rd[MAXM];
int sel[MAXN], sl = 0;
int par[MAXN];
int findset(int x) {
    int p = x;
    while (par[p] != p) p = par[p];
    while (x != p) {
        int nxt = par[x];
        par[x] = p;
        x = nxt;
    }
    return p;
}
bool mergeset(int x, int y) {
    x = findset(x);
    y = findset(y);
    if (x == y) return false;
    else {
        par[x] = y;
        return true;
    }
}

int cost[MAXK];
struct ExRoad {
    int u, v, w;
    bool operator<(ExRoad const &rhs) const {
        return w < rhs.w;
    }
} ex[MAXK][MAXN];

int solve(int bmask) {
    std::vector<ExRoad> all;
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        if ((bmask >> i) & 1) {
            int j = i + 1;
            ans += cost[j];

            int allpos = 0, ruralpos = 0;
            std::vector<ExRoad> newall;
            while (allpos < all.size() && ruralpos < n) {
                if (all[allpos].w < ex[j][ruralpos].w) {
                    newall.push_back(all[allpos++]);
                } else {
                    newall.push_back(ex[j][ruralpos++]);
                }
            }
            while (allpos < all.size()) {
                newall.push_back(all[allpos++]);
            }
            while (ruralpos < n) {
                newall.push_back(ex[j][ruralpos++]);
            }
            all = newall;
        }
    }
    for (int u = 1; u <= n + k; ++u) {
        par[u] = u;
    }
    int ruralpos = 0, oripos = 0;
    while (ruralpos < all.size() && oripos < sl) {
        if (all[ruralpos].w < rd[sel[oripos]].w) {
            if (mergeset(all[ruralpos].u + n, all[ruralpos].v)) {
                ans += all[ruralpos].w;
            }
            ++ruralpos;
        } else {
            if (mergeset(rd[sel[oripos]].u, rd[sel[oripos]].v)) {
                ans += rd[sel[oripos]].w;
            }
            ++oripos;
        }
    }
    while (ruralpos < all.size()) {
        if (mergeset(all[ruralpos].u + n, all[ruralpos].v)) {
            ans += all[ruralpos].w;
        }
        ++ruralpos;
    }
    while (oripos < sl) {
        if (mergeset(rd[sel[oripos]].u, rd[sel[oripos]].v)) {
            ans += rd[sel[oripos]].w;
        }
        ++oripos;
    }
    return ans;
}

signed main() {
#define FILENAME "road"
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);

    n = qread();
    m = qread();
    k = qread();
    for (int i = 0; i < m; ++i) {
        rd[i].u = qread();
        rd[i].v = qread();
        rd[i].w = qread();
    }
    std::sort(rd, rd + m);
    for (int j = 1; j <= k; ++j) {
        cost[j] = qread();
        for (int i = 0, u = 1; u <= n; ++i, ++u) {
            ex[j][i].u = j;
            ex[j][i].v = u;
            ex[j][i].w = qread();
        }
        std::sort(ex[j], ex[j] + n);
    }
    for (int u = 1; u <= n; ++u) {
        par[u] = u;
    }
    sl = 0;
    int trueans = 0;
    for (int i = 0; i < m && sl < n - 1; ++i) {
        if (mergeset(rd[i].u, rd[i].v)) {
            sel[sl++] = i;
            trueans += rd[i].w;
        }
    }
    int maxk = (1ll << k) - 1;
    for (int bmask = 0; bmask <= maxk; ++bmask) {
        trueans = std::min(trueans, solve(bmask));
    }
    qwrite(trueans);
    putchar('\n');
    

    fclose(stdin);
    fclose(stdout);
    return 0;
}
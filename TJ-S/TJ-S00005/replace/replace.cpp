#include <bits/stdc++.h>
using namespace std;
namespace Main {
//#define int long long
#define pb push_back
#define endl '\n'
#ifdef LOCAL
void debug_out() { cerr << endl; }
template<typename Head, typename ...Tail>
void debug_out(Head H, Tail... T) {
    cerr << ' ' << H;
    debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif // LOCAL
const int N = 1.1e7 + 55;
int n, m, tot, posa[N], posb[N], posc[N], stk[N], top, ans[N], clen[N], bel[N];
struct node {
    int x, sgn;
};
vector<node> c[N];
string s, t;
namespace BIT {
    int a[N], n;
    void init(int x) {
        n = x + 5;
    }
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int x, int y) {
        x++;
        for (; x; x -= lowbit(x)) a[x] += y;
    }
    int sum(int x) {
        x = max(x, 1);
        int res = 0;
        for (; x <= n; x += lowbit(x)) res += a[x];
        return res;
    }
}
namespace SA {
    int s[N], rk[N], sa[N], tax[N], tp[N], height[N], n, maxrk, lmi[N], rmi[N];
    void rsort() {
        for (int i = 0; i <= maxrk; i++) tax[i] = 0;
        for (int i = 1; i <= n; i++) tax[rk[i]]++;
        for (int i = 1; i <= maxrk; i++) tax[i] += tax[i - 1];
        for (int i = n; i >= 1; i--) sa[tax[rk[tp[i]]]--] = i;
    }
    void suffixsort() {
        maxrk = tot;
        for (int i = 1; i <= n; i++) rk[i] = s[i], tp[i] = i;
        rsort();
        for (int w = 1; ; w <<= 1) {
            int p = 0;
            for (int i = 1; i <= w; i++)
                tp[++p] = n - i + 1;
            for (int i = 1; i <= n; i++)
                if (sa[i] > w) tp[++p] = sa[i] - w;
            rsort();
            swap(tp, rk);
            p = 0;
            rk[sa[1]] = ++p;
            for (int i = 2; i <= n; i++)
                rk[sa[i]] = (tp[sa[i]] == tp[sa[i - 1]] && tp[sa[i] + w] == tp[sa[i - 1] + w] ? p : ++p);
            maxrk = p;
            if (maxrk == n) break;
        }
    }
    void getheight() {
        for (int i = 1, h = 0; i <= n; i++, h = max(h - 1, 0)) {
            if (rk[i] == n) continue;
            while (s[i + h] == s[sa[rk[i] + 1] + h]) h++;
            height[i] = h;
        }
    }
    void solve() {
        top = 0;
        for (int i = 2; i <= n; i++) {
            debug(i, height[i - 1]);
            while (top && height[stk[top]] >= height[i - 1]) top--;
            if (top) lmi[i] = stk[top] + 1;
            else lmi[i] = i;
            stk[++top] = i;
        }
        top = 0;
        for (int i = n - 1; i >= 1; i--) {
            while (top && height[stk[top]] <= height[i]) top--;
            if (top) rmi[i] = stk[top] - 1;
            else rmi[i] = i;
            stk[++top] = i;
        }
        for (int i = 1; i <= Main::n; i++) {
            int y = posa[i], x = sa[y];
            c[max(lmi[x], 1)].pb({height[x - 1], 1});
                        c[x].pb({height[x - 1], -1});
                                    c[x].pb({height[x], 1});
            c[rmi[x] + 2].pb({height[x], -1});
        }
        BIT::init(n);
        for (int i = 1; i <= Main::m; i++) {
            for (int j = posb[i]; j <= posc[i]; j++)
                bel[sa[j]] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (auto [x, sgn] : c[i])
                BIT::add(x, sgn);
            if (!bel[i]) continue;
            ans[bel[i]] += BIT::sum(clen[i]);
        }
    }
}
signed main() {
    freopen("replace1.in", "r", stdin);
    //freopen("replace.out", "w", stdout);
    cin.tie(0), ios_base::sync_with_stdio(false);
    cin >> n >> m;
    tot = 26 * 26;
    for (int i = 1; i <= n; i++) {
        cin >> s >> t;
        posa[i] = SA::n + 1;
        for (int j = 0; j < s.size(); j++)
            SA::s[++SA::n] = (s[j] - 'a') * 26 + (t[j] - 'a') + 1;
        SA::s[++SA::n] = ++tot;
    }
    for (int i = 1; i <= m; i++) {
        cin >> s >> t;
        posb[i] = SA::n + 1;
        int p = posb[i] - 1, q = posb[i] + s.size();
        for (int j = s.size() - 1; j >= 0; j--) {
            if (s[j] != t[j]) {
                p = j + posb[i];
                break;
            }
        }
        for (int j = 0; j < s.size(); j++) {
            if (s[j] != t[j]) {
                q = j + posb[i];
                break;
            }
        }
        posc[i] = q;
        for (int j = 0; j < s.size(); j++) {
            SA::s[++SA::n] = (s[j] - 'a') * 26 + (t[j] - 'a') + 1;
            clen[SA::n] = p - SA::n + 1;
        }
        SA::s[++SA::n] = ++tot;
    }
    SA::suffixsort();
    SA::getheight();
    SA::solve();
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
    return 0;
}
}
signed main() {
    Main::main();
    return 0;
}

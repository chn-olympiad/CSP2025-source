#include <bits/stdc++.h>
typedef long long ll;
#define db(x...) fprintf(stderr,x)
int id (char x, char y) { return (x - 'a') * 26 + y - 'a'; }
const int N = 5e6 + 10, V = N + 23;
int hash (int x, int y) { return 395 * x + y + 11415; }
int head[V + 10], nex[N], fir[N], sec[N], val[N], tmp;
int find (int x, int y) {
    int H = hash (x, y) % V;
    for (int i = head[H]; i; i = nex[i])
        if (fir[i] == x && sec[i] == y) return val[i];
    return 0;
}
void modify (int x, int y, int z) {
    int H = hash (x, y) % V;
    nex[++tmp] = head[H], head[H] = tmp;
    fir[tmp] = x, sec[tmp] = y, val[tmp] = z;
}
int head_e[N], head_ch[N], nex_e[N], nex_ch[N], tot_e, tot_ch, e[N], ch[N];
void push_e (int x, int y) {
    nex_e[++tot_e] = head_e[x];
    head_e[x] = tot_e, e[tot_e] = y;
}
void push_ch (int x, int y) {
    nex_ch[++tot_ch] = head_ch[x];
    head_ch[x] = tot_ch, ch[tot_ch] = y;
}
int dep[N], fail[N], fa[N], fa_w[N], tot, cnt[N];
char s[N], t[N];
bool ok1[N], ok2[N];
int n, q;
void dfs (int u) {
    for (int i = head_e[u]; i; i = nex_e[i]) {
        int v = e[i];
        cnt[v] += cnt[u];
        dfs (v);        
    }
}
int Q[N], tl, tr;
void build () {
    tl = 1;
    for (int i = head_ch[0]; i; i = nex_ch[i]) Q[++tr] = ch[i];
    while (tr >= tl) {
        int u = Q[tl++], w = fa_w[u];
        int x = fail[fa[u]], y = find (x, w);
        while (!y && x) {
            x = fail[x];
            y = find (x, w);
        }
        if (y) fail[u] = y;
        if (!fa[u]) fail[u] = 0;
        for (int i = head_ch[u]; i; i = nex_ch[i]) Q[++tr] = ch[i];
    }
}
int main () {
    freopen ("replace.in", "r", stdin);
    freopen ("replace.out", "w", stdout);
    scanf ("%d%d", &n, &q);
    for (int x = 1; x <= n; x++) {
        char c = getchar ();
        while (c < 'a' || c > 'z') c = getchar ();
        int len = 0;
        while ('a' <= c && c <= 'z') {
            s[++len] = c;
            c = getchar ();
        }
        while (c < 'a' || c > 'z') c = getchar ();
        len = 0;
        while ('a' <= c && c <= 'z') {
            t[++len] = c;
            c = getchar ();
        }
        int u = 0;
        for (int i = 1; i <= len; i++) {
            int w = id (s[i], t[i]);
            if (!find (u, w)) {
                push_ch (u, ++tot);
                modify (u, w, tot);
                fa[tot] = u, fa_w[tot] = w, dep[tot] = dep[u] + 1;
            }
            u = find (u, w);
        }
        cnt[u]++;
    }
    build ();
    for (int i = 1; i <= tot; i++) push_e (fail[i], i);
    dfs (0);
    for (int i = 1; i <= q; i++) {
        char c = getchar ();
        while (c < 'a' || c > 'z') c = getchar ();
        int len1 = 0, len2 = 0;
        while ('a' <= c && c <= 'z') {
            s[++len1] = c;
            c = getchar ();
        }
        while (c < 'a' || c > 'z') c = getchar ();
        while ('a' <= c && c <= 'z') {
            t[++len2] = c;
            c = getchar ();
        }
        if (len1 != len2) {
            printf ("0\n");
            continue;
        }
        int len = len1;
        ok1[0] = ok2[len + 1] = 1;
        for (int i = 1; i <= len; i++) ok1[i] = (s[i] == t[i]) && ok1[i - 1];
        for (int i = len; i >= 1; i--) ok2[i] = (s[i] == t[i]) && ok2[i + 1];
        ll ans = 0;
        for (int i = 1, u = 0, v = 0; i <= len; i++) {
            int w = id (s[i], t[i]);
            while (u && !find (u, w)) u = fail[u];
            if (find (u, w)) u = find (u, w);
            while (v && !find (v, w)) v = fail[v];
            if (find (v, w)) v = find (v, w);
            while (ok1[i - dep[v]] && v) v = fail[v];
            if (ok2[i + 1]) ans += (cnt[u] - cnt[v]);
        }
        printf ("%lld\n", ans);
    }
    fclose (stdin);
    fclose (stdout);
    return 0;
}
// BU YAO BEI KA CHANG
// BU YAO BEI KA KONG JIAN
// pls give me MAN FEN!!!
// QAQ
#include <bits/stdc++.h>
using namespace std;
#define getchar getchar_unlocked
const int maxn = 2e5 + 5, maxm = 5e6 + 5;
int n, Q, ncnt = 2;
int get(char c) { return c == '$' ? 26 : c - 'a'; }
// rp++
struct Node {
    int son[27], cnt, siz; vector<int> rec;
    Node() { cnt = siz = 0; for (int i = 0; i < 27; i ++) son[i] = 0; }
} T[(maxm << 1) + (maxn << 1)]; int bin[(maxm << 1) + (maxn << 1)], top;
int create_node() {
    if (!top) bin[++ top] = ++ ncnt;
    int res = bin[top --]; T[res].cnt = T[res].siz = 0, T[res].rec.clear();
    for (int i = 0; i < 27; i ++) T[res].son[i] = 0;
    return res;
} inline int read() {
    char c = getchar(); int f = 1;
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-') f = -f;
    int res = 0;
    for (; c >= '0' && c <= '9'; c = getchar())
        res = (res << 1) + (res << 3) + (c ^ 48);
    return res;
} 
int mid_root = 0, pre_root = 1, suf_root = 2;
void insert(int cur, char *s, int len, int idx = 0) {
    for (int i = 0; i < len; i ++) {
        int c = get(s[i]);
        if (T[cur].son[c] == 0) T[cur].son[c] = create_node();
        T[cur].siz ++, cur = T[cur].son[c];
    } T[cur].cnt ++, T[cur].siz ++;
    if (idx) T[cur].rec.push_back(idx);
} void remove(int cur, char *s, int len, int i = 0) {
    // cerr << "remove: " << i << '\n';
    T[cur].siz --;
    if (i >= len) return T[cur].cnt --, void(0);
    int c = get(s[i]), nxt = T[cur].son[c];
    remove(nxt, s, len, i + 1);
    if (T[nxt].siz == 0) T[cur].son[c] = 0, bin[++ top] = nxt;
} char str[(maxm << 1) + (maxn << 1)], tmp[(maxm << 1) + (maxn << 1)]; int tot_len = 0, ans[maxn]; 
struct my_string { 
    char *st; int len; 
    my_string(char *a = nullptr, int b = 0) { st = a, len = b; }
    char &operator[](const int &pos) const { return *(st + pos); }
} a[maxn][2], que[maxn][2]; pair<int, int> mid[maxn], que_mid[maxn];
my_string input() {
    char c; for (c = getchar(); c < 'a' || c > 'z'; c = getchar());
    my_string res; res.st = str + tot_len;
    for (; c >= 'a' && c <= 'z'; c = getchar()) res.len ++, str[tot_len ++] = c;
    return res;
} int idx[maxn << 1], k = 0;
void find_node(int cur) {
    if (T[cur].cnt) idx[++ k] = cur;
    for (int i = 0; i < 27; i ++)
        if (T[cur].son[i]) find_node(T[cur].son[i]);
} int ask(int cur, char *s, int len) {
    int res = T[cur].cnt;
    for (int i = 0; i < len; i ++) {
        int c = get(s[i]);
        if (!T[cur].son[c]) return res;
        cur = T[cur].son[c], res += T[cur].cnt;
    } return res;
} void clear(int cur) {
    for (int i = 0; i < 27; i ++)
        if (T[cur].son[i]) clear(T[cur].son[i]), bin[++ top] = T[cur].son[i], T[cur].son[i] = 0;
    T[cur].rec.clear(), T[cur].cnt = T[cur].siz = 0;
} void solve(int cur) {
    if (T[cur].cnt) {
        for (int len = T[cur].rec.size(), t = 0; t < len; t ++) {
            int i = T[cur].rec[t];
            if (i <= n) {
                int cnt = 0;
                for (int j = mid[i].second + 1; j < a[i][0].len; j ++)
                    tmp[cnt ++] = a[i][0][j];
                insert(suf_root, tmp, cnt);
            }
        } for (int len = T[cur].rec.size(), t = 0; t < len; t ++) {
            int i = T[cur].rec[t];
            if (i > n) {
                int cnt = 0;
                for (int j = que_mid[i - n].second + 1; j < que[i - n][0].len; j ++)
                    tmp[cnt ++] = que[i - n][0][j];
                ans[i - n] += ask(suf_root, tmp, cnt);
            }
        }
    } for (int i = 0; i < 27; i ++) if (T[cur].son[i]) solve(T[cur].son[i]);
    if (T[cur].cnt) {
        for (int len = T[cur].rec.size(), t = 0; t < len; t ++) {
            int i = T[cur].rec[t];
            if (i <= n) {
                int cnt = 0;
                for (int j = mid[i].second + 1; j < a[i][0].len; j ++)
                    tmp[cnt ++] = a[i][0][j];
                remove(suf_root, tmp, cnt);
            }
        }
    }
}
#define open(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)
int main() { open(replace);
    n = read(), Q = read();
    for (int i = 1; i <= n; i ++) {
        a[i][0] = input(), a[i][1] = input(); int len = a[i][0].len; bool ok = 0;
        for (int j = 0; j < len; j ++) if (a[i][0][j] != a[i][1][j]) { ok = 1; break; }
        if (!ok) continue;
        for (mid[i].first = 0; mid[i].first < len && a[i][0][mid[i].first] == a[i][1][mid[i].first]; mid[i].first ++);
        for (mid[i].second = len - 1; (~mid[i].second) && a[i][0][mid[i].second] == a[i][1][mid[i].second]; mid[i].second --);
        int cnt = 0; for (int j = mid[i].first; j <= mid[i].second; j ++) tmp[cnt ++] = a[i][0][j];
        tmp[cnt ++] = '$'; for (int j = mid[i].first; j <= mid[i].second; j ++) tmp[cnt ++] = a[i][1][j];
        insert(mid_root, tmp, cnt, i);
    } for (int i = 1; i <= Q; i ++) {
        que[i][0] = input(), que[i][1] = input(); 
        if (que[i][0].len != que[i][1].len) continue; 
        int len = que[i][0].len;
        for (que_mid[i].first = 0; que_mid[i].first < len && que[i][0][que_mid[i].first] == que[i][1][que_mid[i].first]; que_mid[i].first ++);
        for (que_mid[i].second = len - 1; (~que_mid[i].second) && que[i][0][que_mid[i].second] == que[i][1][que_mid[i].second]; que_mid[i].second --);
        int cnt = 0; for (int j = que_mid[i].first; j <= que_mid[i].second; j ++) tmp[cnt ++] = que[i][0][j];
        tmp[cnt ++] = '$'; for (int j = que_mid[i].first; j <= que_mid[i].second; j ++) tmp[cnt ++] = que[i][1][j];
        insert(mid_root, tmp, cnt, i + n);
    } // cerr << "over\n";
    find_node(mid_root);
    for (int o = 1; o <= k; o ++) {
        int p = idx[o];
        // cerr << "====================\n";
        for (int len = T[p].rec.size(), t = 0; t < len; t ++) {
            int i = T[p].rec[t], cnt = 0;
            // cerr << "get: " << i << '\n';
            if (i > n) {
                for (int j = que_mid[i - n].second - 1; ~j; j --)
                    tmp[cnt ++] = que[i - n][0][j];
            } else {
                for (int j = mid[i].second - 1; ~j; j --)
                    tmp[cnt ++] = a[i][0][j];
            } insert(pre_root, tmp, cnt, i);
        } solve(pre_root), clear(pre_root);
    } 
    // cerr << "over\n";
    for (int i = 1; i <= Q; i ++) printf("%d\n", ans[i]);
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
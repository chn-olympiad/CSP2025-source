// mind! the test means only replace once!
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+6,C=22;
#define pb push_back
#define For(i, s, e) for(int i = (s); i <= (e); ++i)
#define ifor(i, s, e) for(int i = (s); i >= (e); --i)
inline ll read() {
    ll x(0); bool f(0); char ch = getchar();
    while(!isdigit(ch)) f = ch == '-', ch = getchar();
    while(isdigit(ch)) x = x * 10 + (ch^48), ch = getchar();
    return f ? -x : x;
}
inline void wt(ll x, bool md=1) {
    if(x < 0) putchar('-'), x = -x;
    short stack[64], top(0);
    do stack[++ top] = x % 10, x /= 10; while(x);
    while(top) putchar(stack[top --] | 48);
    md ? putchar('\n') : putchar(' ');
}
struct SAM{
    int lnk[N], len[N], cnt[N], ch[N][C + 1], tot, lst;
    void init() {
        For(i, 0, tot) {
            lnk[i] = len[i] = cnt[i] = 0;
            For(j, 0, C) ch[i][j] = 0;
        }
        lnk[0] = -1;
    } // 
    void ins(int c) {
        int p = lst;
        len[++ tot] = len[p] + 1; lst = tot;
        while(~p && !ch[p][c]) p = lnk[p];
        if(p == -1) lnk[lst] = 0;
        else {
            int q = ch[p][c];
            if(len[q] == len[p] + 1) lnk[lst] = q;
            else {
                int cpy = ++ tot;
                lnk[cpy] = lnk[q]; lnk[q] = lnk[lst] = cpy; len[cpy] = len[p] + 1;
                For(i, 0, C) ch[cpy][i] = ch[q][i];
                while(~p && ch[p][c] == q) ch[p][c] = cpy;
            }
        }
        cnt[lst] = 1;
    }
}a[2];
void dp(int u, int v) {
    For(i, 0, C) if(a[0].ch[u][i] && a[1].ch[v][i]) {
        dp(a[0].ch[u][i], a[1].ch[v][i]);
        a[0].cnt[u] += a[0].cnt[a[0].ch[u][i]];
    }
}
int n, q;
string s[2], t[N][2];
int main() {
    n = read(), q = read();
    For(i, 1, n) {
        cin >> t[i][0] >> t[i][1];
    }
    For(_, 1, q) {
        cin >> s[0] >> s[1];
        For(b, 0, 1) {
            a[b].init();
            for(char ch : s[b]) a[b].ins(ch - 'a');
        }
        ll cnt = 0;
        For(i, 1, n) {
            int len = t[i][0].size();
            int cur[2]; cur[0] = cur[1] = 0;
            For(j, 0, len - 1) {
                if(a[0].ch[cur[0]][t[i][0][j] - 'a'] && a[1].ch[cur[1]][t[i][1][j] - 'a']) {
                    cur[0] = a[0].ch[cur[0]][t[i][0][j] - 'a'];
                    cur[1] = a[1].ch[cur[1]][t[i][1][j] - 'a'];
                } else goto fail;
            }
            cnt += a[0].cnt[cur[0]];
            fail:;
        }
        wt(cnt);
    }
    return 0;
}
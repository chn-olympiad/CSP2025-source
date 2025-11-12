#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10, M = 5e6 + 10, base1 = 131, base2 = 137, mod1 = 998244353, mod2 = 1e9 + 7;
int n, q, len[N], pw1[M] = {1}, pw2[M] = {1}, ql[N], qr[N];
int ax[N], bx[N], le[N], ri[N], p, ans[N], tr[M], maxn;
int lowbit(int x) {
    return x & -x;
}
void add(int x, int y) {
	printf("%lld %lld\n", x, y);
    for(int i = x; i <= 5e6; i += lowbit(i)) {
    	printf("%lld\n", i);
    	tr[i] += y;
	}
}
int query(int x) {
    int sum = 0;
    for(int i = x; i; i -= lowbit(i)) sum += tr[i];
    return sum;
}
vector <int> s1[N], s2[N], t1[N], t2[N], sx, sy, tx, ty, aa[M], bb[M];
char a[N], b[N];
struct node {
    int x, l, r, id;
}que[N];
bool cmp(node p, node q) {
    if(p.x == q.x && p.l == q.l) return p.r < q.r;
    if(p.x == q.x) return p.l < q.l;
    return p.x < q.x;
}
bool cmp2(int p, int q) {
    if(le[p] == le[q]) return ri[p] < ri[q];
    return le[p] < le[q];
}
int sol1(int id, int l, int r, int op) {
    if(op == 1) return (s1[id][r] - s1[id][l - 1] * pw1[r - l + 1] % mod1 + mod1) % mod1;
    return (t1[id][r] - t1[id][l - 1] * pw1[r - l + 1] % mod1 + mod1) % mod1;
}
int sol2(int id, int l, int r, int op) {
    if(op == 1) return (s2[id][r] - s2[id][l - 1] * pw2[r - l + 1] % mod2 + mod2) % mod2;
    return (t2[id][r] - t2[id][l - 1] * pw2[r - l + 1] % mod2 + mod2) % mod2;
}
int solx(int l, int r, int op) {
    if(op == 1) return (sx[r] - sx[l - 1] * pw1[r - l + 1] % mod1 + mod1) % mod1;
    return (tx[r] - tx[l - 1] * pw1[r - l + 1] % mod1 + mod1) % mod1;
}
int soly(int l, int r, int op) {
    if(op == 1) return (sy[r] - sy[l - 1] * pw2[r - l + 1] % mod2 + mod2) % mod2;
    return (ty[r] - ty[l - 1] * pw2[r - l + 1] % mod2 + mod2) % mod2;
}
bool check(int l, int r) {
    if(solx(l, r, 1) == solx(l, r, 2) && soly(l, r, 1) == soly(l, r, 2)) return true;
    return false;
}
void solve(int l, int r) {
    int x = abs(que[l].x);
    if(que[l].x > 0) {
        sort(aa[x].begin(), aa[x].end(), cmp2);
        int nw = 0;
        for(int i = l; i <= r; i++) {
            while(nw < aa[x].size()) {
            	add(ri[aa[x][nw]] + 1, 1), nw++;
			}
            ans[que[i].id] = query(que[i].r + 1);
        }
        for(int i = 0; i < nw; i++) add(ri[aa[x][nw]] + 1, -1);
    }
    else {
        sort(bb[x].begin(), bb[x].end(), cmp2);
        int nw = 0;
        for(int i = l; i <= r; i++) {
            while(nw < bb[x].size()) add(ri[bb[x][nw]], 1), nw++;
            ans[que[i].id] = query(que[i].r);
        }
        for(int i = 0; i < nw; i++) add(ri[bb[x][nw]], -1);
    }
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
    scanf("%lld%lld", &n, &q);
    // if(n * q <= 0) {
        for(int i = 1; i <= 5e6; i++) pw1[i] = pw1[i - 1] * base1 % mod1, pw2[i] = pw2[i - 1] * base2 % mod2;
        for(int i = 1; i <= n; i++) {
            scanf("%s%s", a + 1, b + 1);
            len[i] = strlen(a + 1);
            s1[i].push_back(0);
            s2[i].push_back(0);
            t1[i].push_back(0);
            t2[i].push_back(0);
            for(int j = 1; j <= len[i]; j++) {
                s1[i].push_back((s1[i][j - 1] * base1 + a[j]) % mod1);
                s2[i].push_back((s2[i][j - 1] * base2 + a[j]) % mod2);
                t1[i].push_back((t1[i][j - 1] * base1 + b[j]) % mod1);
                t2[i].push_back((t2[i][j - 1] * base2 + b[j]) % mod2);
            }
            int l = 1, r = len[i];
            ql[i] = 1, qr[i] = len[i];
            while(l <= r) {
                int mid = (l + r) / 2;
                if(sol1(i, 1, mid, 1) == sol1(i, 1, mid, 2) && sol2(i, 1, mid, 1) == sol2(i, 1, mid, 2)) ql[i] = mid + 1, l = mid + 1;
                else r = mid - 1;
            }
            if(ql[i] == len[i] + 1) continue;
            l = 1, r = len[i];
            while(l <= r) {
                int mid = (l + r) / 2;
                if(sol1(i, mid, len[i], 1) == sol1(i, mid, len[i], 2) && sol2(i, mid, len[i], 1) == sol2(i, mid, len[i], 2)) qr[i] = mid - 1, r = mid - 1;
                else l = mid + 1;
            }
        }
        while(q--) {
            scanf("%s%s", a + 1, b + 1);
            int lenx = strlen(a + 1);
            if(lenx != strlen(b + 1)) {
                printf("0\n");
                continue;
            }
            sx.clear(), sy.clear(), tx.clear(), ty.clear();
            sx.push_back(0), sy.push_back(0), tx.push_back(0), ty.push_back(0);
            for(int i = 1; i <= lenx; i++) {
                sx.push_back((sx[i - 1] * base1 + a[i]) % mod1);
                sy.push_back((sy[i - 1] * base2 + a[i]) % mod2);
                tx.push_back((tx[i - 1] * base1 + b[i]) % mod1);
                ty.push_back((ty[i - 1] * base2 + b[i]) % mod2);
            }
            int ll = 1, rr = lenx, l = 1, r = lenx;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(check(1, mid)) ll = mid + 1, l = mid + 1;
                else r = mid - 1;
            }
            l = 1, r = lenx;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(check(mid, lenx)) rr = mid - 1, r = mid - 1;
                else l = mid + 1;
            }
            int cnt = 0;
            for(int i = 1; i <= n; i++) if(ql[i] != len[i] + 1 && qr[i] - ql[i] == rr - ll) {
                if(sol1(i, ql[i], qr[i], 1) == solx(ll, rr, 1) && sol2(i, ql[i], qr[i], 1) == soly(ll, rr, 1) && sol1(i, ql[i], qr[i], 2) == solx(ll, rr, 2) && sol2(i, ql[i], qr[i], 2) == soly(ll, rr, 2)) {
                    int sl = ll - ql[i] + 1, sr = sl + len[i] - 1;
                    if(sl <= 0 || sr > lenx) continue;
                    if(sol1(i, 1, len[i], 1) == solx(sl, sr, 1) && sol2(i, 1, len[i], 1) == soly(sl, sr, 1) && sol1(i, 1, len[i], 2) == solx(sl, sr, 2) && sol2(i, 1, len[i], 2) == soly(sl, sr, 2)) {
                        cnt++;
                    }
                }
            }
            printf("%lld\n", cnt);
        }
        return 0;
    // }
    // for(int i = 1; i <= n; i++) {
    //     scanf("%s%s", a + 1, b + 1);
    //     len[i] = strlen(a + 1);
    //     for(int j = 1; j <= len[i]; j++) if(a[j] == 'b') {
    //         ax[i] = j;
    //         break;
    //     }
    //     for(int j = 1; j <= len[i]; j++) if(b[j] == 'b') {
    //         bx[i] = j;
    //         break;
    //     }
    //     le[i] = ax[i] - 1, ri[i] = len[i] - ax[i], maxn = max(maxn, ri[i]);
    //     if(ax[i] > bx[i]) {
    //         aa[ax[i] - bx[i]].push_back(i);
    //     }
    //     else {
    //         bb[bx[i] - ax[i]].push_back(i);
    //     }
    // }
    // for(int i = 1; i <= q; i++) {
    //     scanf("%s%s", a + 1, b + 1);
    //     int lenx = strlen(a + 1), xx, yy;
    //     if(strlen(b + 1) != lenx) {
    //         ans[i] = 0;
    //         continue;
    //     }
    //     for(int j = 1; j <= lenx; j++) if(a[j] == 'b') {
    //         xx = j;
    //         break;
    //     }
    //     for(int j = 1; j <= lenx; j++) if(b[j] == 'b') {
    //         yy = j;
    //         break;
    //     }
    //     que[++p] = {xx - yy, xx - 1, lenx - xx, i};
    // }
    // sort(que + 1, que + q + 1, cmp);
    // int nw = 1;
    // while(true) {
    //     int l = nw, r = nw;
    //     while(r <= p && que[r + 1].x == que[r].x) r++;
    //     solve(l, r);
    //     nw = r + 1;
    //     if(nw > p) break;
    // }
    // for(int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
}
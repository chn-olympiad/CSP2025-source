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
    const int N = 1e5 + 10;
    int n;
    struct node{
        int s[3];
        int mx, d;
    }a[N];
    int b[N];
    int len;
    int c[3];
    int check() {
        if (c[0] > n / 2)       return 0;
        else if (c[1] > n / 2)  return 1;
        return 2;
    }
    int q(int x, int y) {
        int mx = -1, d = 0;
        REP(i, 0, 2) {
            if (i == y) continue;
            if (a[x].s[i] >= mx) {
                mx = a[x].s[i];
                d = i;
            }
        }
        // cout << x << " " << mx << "\n";
        return mx;
    }
    void main() {
        read(n);
        c[0] = c[1] = c[2] = 0;
        REP(i, 1, n)    read(a[i].s[0], a[i].s[1], a[i].s[2]);
        int ans = 0;
        REP(i, 1, n) {
            int mx = a[i].s[0], d = 0;
            REP(j, 1, 2) {
                if (a[i].s[j] > mx) {
                    mx = a[i].s[j];
                    d = j;
                }
            }
            a[i].mx = mx, a[i].d = d;
            c[d]++;
            ans += mx;
        }
        if (c[0] <= n / 2 and c[1] <= n / 2 and c[2] <= n / 2)  return cout << ans << "\n", void();
        int d = check();
        len = 0;
        // cout << d << "\n";
        REP(i, 1, n) {
            if (a[i].d == d) 
                b[++len] = q(i, d) - a[i].s[d];
        }
        // REP(i, 1, len)  cout << b[i] << " ";
        // cout << "\n";
        // cout << len << "\n";
        sort(b + 1, b + len + 1, [](int a, int b){
            return a > b;
        });
        // cout << ans << "\n";
        int cnt = c[d] - n / 2;
        REP(i, 1, cnt)  ans += b[i];
        cout << ans << "\n";
        return;
    }
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T = 1;
    read(T);
    while(T--) {
        YZLK::main();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
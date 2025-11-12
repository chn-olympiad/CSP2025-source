#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define bug(x) cerr << __LINE__ << ":" << (#x) << "=" << (x) << endl
#define del cerr << endl;
#define int ll
using namespace std;
int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){if (ch == '-') w = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
const int N = 1e5 + 10;
int n;
struct Value {
    int a, b, c;
    Value(int x) {
        c = x % n, x /= n;
        b = x % n, x /= n;
        a = x % n;
    }
    int to() {
        return c + b * n + a * n * n;
    }
};
int get_v(const int& a, const int& b, const int& c) {
    return c + b * n + a * n * n;
}
bool cmp(const Value& x, const Value& y) {
    return x.a > y.a;
}
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = read();
    while (T--) {
        n = read();
        vector<Value> a(n + 10, 0);
        unordered_map<int, int> f;
        int suma = 0, sumb = 0, sumc = 0;
        for (int i = 1; i <= n; i++) {
            a[i].a = read(), a[i].b = read(), a[i].c = read();
            suma += a[i].a;
            sumb += a[i].b;
            sumc += a[i].c;
        }
        if (sumb == 0 && sumc == 0) {
            sort(a.begin() + 1, a.begin() + n + 1, cmp);
            int ans = 0;
            for (int i = 1; i <= n / 2; i++) {
                ans += a[i].a;
            }
            cout << ans << endl;
            continue;
        }
        if (sumc == 0) {
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int xa = 0; xa <= min(i, n / 2); xa++) {
                    int nw = get_v(xa, i - xa, 0), xb = i - xa;
                    if (xb > n / 2 || xb < 0) continue;
                    if (xa != 0) f[nw] = max(f[nw], f[get_v(xa - 1, xb, 0)] + a[i].a);
                    if (xb != 0) f[nw] = max(f[nw], f[get_v(xa, xb - 1, 0)] + a[i].b);
                    if (i == n) ans = max(ans, f[nw]);
                }
            }
            cout << ans << endl;
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int xa = 0; xa <= min(i, n / 2); xa++) {
                for (int xb = 0; xb <= min(i, n / 2); xb++) {
                    int nw = get_v(xa, xb, i - xa - xb), xc = i - xa - xb;
                    if (xc > n / 2 || xc < 0) continue;
                    if (xa != 0) f[nw] = max(f[nw], f[get_v(xa - 1, xb, xc)] + a[i].a);
                    if (xb != 0) f[nw] = max(f[nw], f[get_v(xa, xb - 1, xc)] + a[i].b);
                    if (xc != 0) f[nw] = max(f[nw], f[get_v(xa, xb, xc - 1)] + a[i].c);
                    if (i == n) ans = max(ans, f[nw]);
//                    if (i == n) cerr << xa << " " << xb << " " << xc << " " << f[nw] << endl;
                }
            }
        }
//        cerr << endl;
        cout << ans << '\n';
    }
    return 0;
}

// maybe greedy is right? choose the largest col for all, change the illegal
// wrong?

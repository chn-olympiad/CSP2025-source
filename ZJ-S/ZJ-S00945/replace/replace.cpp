#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define REP(i, l, r)    for(int (i) = (l);(i) <= (r);(i)++)
#define DEP(i, r, l)    for(int (i) = (r);(i) >= (l);(i)--)
#define pb push_back
#define ull unsigned long long

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
    const int N = 2e5 + 10;
    const int M = 5e6 + 10;
    const ull P = 131;
    int n, q;
    int h[M];
    struct node{
        int len;
        string s1, s2;
        int l = -1, r = -1;
        ull c1, c2;
        ull h1, h2;
    }a[N], b[N];
    map<pii, vector<int> > mp;
    int he1[M], he2[M];
    void main() {
        read(n, q);
        h[0] = 1;
        REP(i, 1, M - 10)   h[i] = h[i - 1] * P;
        REP(i, 1, n) {
            cin >> a[i].s1 >> a[i].s2;
            // cout << 111 << "\n";
            a[i].len = a[i].s1.size();
            // cout << 222 << "\n";
            ull c1 = 0, c2 = 0;
            REP(j, 0, a[i].len - 1) {
                c1 = c1 * P + a[i].s1[j];
                c2 = c2 * P + a[i].s2[j];
                if (a[i].s1[j] != a[i].s2[j]) {
                    if (a[i].l == -1) a[i].l = j;
                    a[i].r = j;
                }
            }
            // cout << a[i].l << " " << a[i].r << '\n';
            if (a[i].l >= 0) {
                ull s1 = 0, s2 = 0;
                REP(j, a[i].l, a[i].r) {
                    s1 = s1 * P + a[i].s1[j];
                    s2 = s2 * P + a[i].s2[j];
                }
                a[i].c1 = s1;
                a[i].c2 = s2;
                mp[(pii){s1, s2}].pb(i);
                s1 = s2 = 0;
                REP(j, 0, a[i].len - 1) {
                    s1 = s1 * P + a[i].s1[j];
                    s2 = s2 * P + a[i].s2[j];
                }
                a[i].h1 = s1;
                a[i].h2 = s2;
                // cout << a[i].c1 << " " << a[i].c2 << "\n";
            }
        }


        REP(i, 1, q) {
            cin >> b[i].s1 >> b[i].s2;
            if (b[i].s1.size() != b[i].s2.size())   {puts("0");continue;}
            b[i].len = b[i].s1.size();
            ull h1 = 0, h2 = 0;
            REP(j, 0, b[i].len - 1) {
                h1 = h1 * P + b[i].s1[j];
                h2 = h2 * P + b[i].s2[j];
                he1[j] = h1;
                he2[j] = h2;
                if (b[i].s1[j] != b[i].s2[j]) {
                    if (b[i].l == -1) b[i].l = j;
                    b[i].r = j;
                }
            }
            // cout << he1[b[i].len - 1] << " "<< he2[b[i].len - 1] << "\n";
            if (b[i].l >= 0) {
                ull s1 = 0, s2 = 0;
                REP(j, b[i].l, b[i].r) {
                    s1 = s1 * P + b[i].s1[j];
                    s2 = s2 * P + b[i].s2[j];
                }
                b[i].c1 = s1;
                b[i].c2 = s2;
                vector<int> ve;
                ve = mp[(pii){s1, s2}];
                // cout << s1 << " " << s2 << "\n";
                if (ve.empty()) {
                    puts("0");
                    continue;
                }
                int cnt = 0;
                for(auto it:ve) {
                    if (a[it].l <= b[i].l and (a[it].len - a[it].r - 1) <= (b[i].len - b[i].r - 1)) {
                        int l = (b[i].l - a[it].l), r = (b[i].r + (a[it].len - a[it].r - 1));
                        // cout << l << " " << r << "\n";
                        ull sum1 = he1[r], sum2 = he2[r];
                        if (l > 0) {
                            sum1 = sum1 - (he1[l - 1] * h[r - l + 1]);
                            sum2 = sum2 - (he2[l - 1] * h[r - l + 1]);
                        }
                        if (sum1 == a[it].h1 and sum2 == a[it].h2)  cnt++;
                    }
                }
                cout << cnt << "\n";
            }

        }
        return;
    }
}

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int T = 1;
    // read(T);
    while(T--) {
        YZLK::main();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
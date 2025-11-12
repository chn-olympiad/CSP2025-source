#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define bug(x) cerr << __LINE__ << ":" << (#x) << "=" << (x) << endl;
#define del cerr << endl;
#define int ll
#define mod 998244353
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
const int N = 510;
int n, m;
string s;
int c[N];
int perm[N];
bool check() {
    int ans = 0;
    int tot = 0;
//    for (int i = 1; i <= n; i++) {
//        cerr << perm[i] << " ";
//    }
//    del;
    for (int i = 1; i <= n; i++) {
        if (tot < c[ perm[i] ] && s[ i - 1 ] == '1') {
//            bug(i);
            ans++;
        } else {
            tot++;
        }
    }
//    del;
    return ans >= m;
}
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    n = read(), m = read();
    cin >> s;
    for (int i = 1; i <= n; i++) {
        c[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        perm[i] = i;
    }
    int ans = 0;
    do {
        if (check()) {
            ans = (ans + 1) % mod;
        }
    } while (next_permutation(perm + 1, perm + n + 1));
    cout << ans << '\n';
    return 0;
}


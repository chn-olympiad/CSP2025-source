#include<bits/stdc++.h>
#define fup(i, bg, ed) for(int i = (bg); i <= (ed); i++)
#define fdn(i, bg, ed) for(int i = (bg); i >= (ed); i--)
typedef long long lld;
using namespace std;
#define mms(f, x) memset(f, x, sizeof f)

struct AutoIO {
    AutoIO() {
        freopen("employ.in", "r", stdin);
        freopen("employ.out", "w", stdout);
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    ~AutoIO() {
        cout.flush();
        #ifdef Local
        cerr << 1000. * clock() / CLOCKS_PER_SEC << "ms" << "\n";
        #endif
    }
}__cdl_auto_io;

const int N = 505;
const int P = 998244353;
int n, m;
string s;
int c[N], cnt[N], precnt[N], sufcnt[N];
int f[N][N][N];
int g[N][N];
int C[N][N];
int fac[N];

main() {
    fac[0] = 1; for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i-1] * i % P;
    fup(i, 0, N-1) {
        C[i][0] = 1;
        fup(j, 1, i) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % P;
    }

    cin >> n >> m;
    cin >> s;
    s = " " + s;
    fup(i, 1, n) cin >> c[i];
    // fup(i, 1, n) cerr << c[i] << " \n"[i==n];

        // cerr << 1000. * clock() / CLOCKS_PER_SEC << "ms" << "\n";
    fup(i, 1, n) cnt[c[i]]++;
    // fup(i, 0, n) cerr << cnt[i] << " \n"[i==n];
    fup(i, 0, n) precnt[i] = (i ? precnt[i-1] : 0) + cnt[i];
    fdn(i, n, 0) sufcnt[i] = sufcnt[i+1] + cnt[i];

    // fup(i, 1, n) {
    //     pre[i] = pre[i-1] + (s[i] == '0');
    // }

    // fup(k, 0, n) f[0][0][k][0] = 1;
    f[0][0][0] = 1;
    fup(j, 0, n) {
        // cerr << "cur: " << j << endl;
        mms(g, 0);
        fup(i, 0, n) fup(k, 0, n) if(f[i][j][k]) fup(kk, 0, cnt[j]) if(k >= kk) {
            // fprintf(stderr, "[%d][%d][%d](%d) * %d -> [%d][%d][%d]\n", i,k,p,f[i][j][k],1ll * C[k][kk] * fac[kk] % P,i,k-kk,p+cnt[j]-kk);
            (g[i][k-kk] += 1ll * C[k][kk] * C[cnt[j]][kk] % P * fac[kk] % P * f[i][j][k] % P) %= P;
        }
        fup(i, 0, n) fup(k, 0, n)  f[i][j][k] = g[i][k];
        // fup(i, 0, n) fup(k, 0, n) fup(p, 0, n) if(f[i][j][k][p]) {
        //     fprintf(stderr, "f[%d][%d][%d][%d] = %d\n", i, j, k, p, f[i][j][k][p]);
        // }
        // cerr << "trans: " << endl;
        fup(i, 0, n-1) fup(k, 0, n) {
            int p = precnt[j] - i + k;
            if(p > n || p < 0) continue;
            if(s[i+1] == '0') {
                (f[i+1][j+1][k+1] += f[i][j][k]) %= P;
                if(p) (f[i+1][j+1][k] += 1ll * p * f[i][j][k] % P) %= P;
            } else {
                (f[i+1][j][k+1] += f[i][j][k]) %= P;
                if(p) (f[i+1][j+1][k] += 1ll * p * f[i][j][k] % P) %= P;
            }
        }
        // fup(i, 0, n) fup(k, 0, n) fup(p, 0, n) if(f[i][j][k][p]) {
        //     fprintf(stderr, "f[%d][%d][%d][%d] = %d\n", i, j, k, p, f[i][j][k][p]);
        // }
        // fup(i, 0, n) fup(k, 0, n) fup(p, 0, n) if(f[i][j+1][k][p]) {
        //     fprintf(stderr, "f[%d][%d][%d][%d] = %d | %d\n", i, j+1, k, p, f[i][j+1][k][p], i - k + p);
        // }
    }

    // fup(i, 0, n) fup(j, 0, n) fup(k, 0, n) fup(p, 0, n) if(f[i][j][k][p]) {
    //     fprintf(stderr, "f[%d][%d][%d][%d] = %d\n", i, j, k, p, f[i][j][k][p]);
    // }

    int ans = 0;
    fup(j, m, n) {
        // cerr << "+= " << n << " " << n-j << " " << sufcnt[n-j+1] << " " << 0 << endl;
        // cerr << f[n][n-j][sufcnt[n-j+1]][0] << " * " << fac[sufcnt[n-j+1]] << "\n";
        // cerr << 1ll * f[n][n-j][sufcnt[n-j+1]][0] * fac[sufcnt[n-j+1]] % P << "\n";
        (ans += 1ll * fac[sufcnt[n-j+1]] * f[n][n-j][sufcnt[n-j+1]] % P) %= P;
    }

    cout << ans << "\n";


}
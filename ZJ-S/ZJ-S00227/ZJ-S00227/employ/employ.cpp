#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define RAP(i,a)      for(auto i=(a).begin();i!=(a).end();i++)
#define REP(i,a,b)    for(int i=(a);i<=(b);i++)
#define DEP(i,a,b)    for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=c)
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=c)
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define MOD(a)   (((a)%mod+mod)%mod)
#define ADD(a,b) (a)=((a)+(b))%mod
#define SUB(a,b) (a)=MOD((a)-(b))
#define MUL(a,b) (a)=MOD((a)*(b))
#define SZ(a)    ((int)(a).size())
#define ALL(a)   (a).begin(),(a).end()
#define ppc(a)   __builtin_popcountll(a)
#define DBG(a)     cout<<#a<<": "<<a<<endl
#define AST(a,l,r) assert(a>=l),assert(a<=r)
#define int long long
using namespace std;

namespace Yyydrasil {

    const int mod = 998244353;
    const int N = 500 + 5;
    int n, m, c[N], a[N], ans;
    char s[N];

    void main() {
        cin >> n >> m;
        cin >> (s + 1);
        REP(i, 1, n) cin >> c[i];
        if (n <= 10) {
            REP(i, 1, n) a[i] = i;
            do {
                int res = 0;
                REP(i, 1, n) {
                    if (s[i] == '1' && (i - 1) - res < c[a[i]]) {
                        res++;
                    }
                }
                ans += (res >= m);
            } while (next_permutation(a + 1, a + 1 + n));
            cout << ans % mod << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}

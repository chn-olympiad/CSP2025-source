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
#define int unsigned long long
using namespace std;
typedef pair<int,int> pii;

namespace Yyydrasil {

    const int N = 2e5 + 5;
    const int base = 20011;
    int n, q, m, tot;
    string s1, s2;
    pii s[N];
    unordered_set<int> hl, hr;

    void main() {
        cin >> n >> q;
        if ((n <= 10000 && q <= 10000) || q == 1) {
            REP(i, 1, n) {
                cin >> s1 >> s2; m = s1.size();
                s1 = " " + s1;
                s2 = " " + s2;
                int sl = 0, sr = m + 1;
                while (sl < m && s1[sl + 1] == s2[sl + 1]) sl++;
                while (sr > 1 && s1[sr - 1] == s2[sr - 1]) sr--;
                if (sl != m) {
                    int res1 = 0, res2 = 0;
                    DEP(j, sr - 1, 1) res1 = res1 * base + (j >= sl ? s1[j] * 128 + s2[j] : s1[j]);
                    REP(j, sl + 1, m) res2 = res2 * base + (j <= sr ? s1[j] * 128 + s2[j] : s1[j]);
                    s[++tot] = {res1, res2};
                }
            }
            REP(i, 1, q) {
                int ans = 0;
                cin >> s1 >> s2;
                if (s1.size() != s2.size()) {
                    cout << 0 << '\n';
                } else {
                    hl.clear(), hr.clear();
                    m = s1.size();
                    s1 = " " + s1;
                    s2 = " " + s2;
                    int sl = 0, sr = m + 1;
                    while (sl < m && s1[sl + 1] == s2[sl + 1]) sl++;
                    while (sr > 1 && s1[sr - 1] == s2[sr - 1]) sr--;
                    int res1 = 0, res2 = 0;
                    DEP(j, sr - 1, 1) { res1 = res1 * base + (j >= sl ? s1[j] * 128 + s2[j] : s1[j]); if (j <= sl + 1) hl.insert(res1); }
                    REP(j, sl + 1, m) { res2 = res2 * base + (j <= sr ? s1[j] * 128 + s2[j] : s1[j]); if (j >= sr - 1) hr.insert(res2); }
                    REP(j, 1, tot) {
                        if (hl.find(s[j].fi) != hl.end() && hr.find(s[j].se) != hr.end()) {
                            ans++;
                        }
                    }
                    cout << ans << '\n';
                }
            }
        } else {
            REP(i, 1, q) {
                cout << 0 << '\n';
            }
        }
    }
}

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}

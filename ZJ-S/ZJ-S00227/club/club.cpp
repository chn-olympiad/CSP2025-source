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
using namespace std;

namespace Yyydrasil {

    priority_queue<int, vector<int>, greater<int>> q[4];
    int n, a1, a2, a3, s1, s2, s3, ans;

    void main() {
        s1 = s2 = s3 = ans = 0;
        while (!q[1].empty()) q[1].pop();
        while (!q[2].empty()) q[2].pop();
        while (!q[3].empty()) q[3].pop();
        cin >> n;
        REP(i, 1, n) {
            cin >> a1 >> a2 >> a3;
            ans += max({a1, a2, a3});
                 if (a1 == max({a1, a2, a3})) s1++, q[1].push(a1 - max(a2, a3));
            else if (a2 == max({a1, a2, a3})) s2++, q[2].push(a2 - max(a1, a3));
            else                              s3++, q[3].push(a3 - max(a1, a2));
        }
        while (s1 > (n / 2)) ans -= q[1].top(), q[1].pop(), s1--;
        while (s2 > (n / 2)) ans -= q[2].top(), q[2].pop(), s2--;
        while (s3 > (n / 2)) ans -= q[3].top(), q[3].pop(), s3--;
        cout << ans << '\n';
    }
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}
//main
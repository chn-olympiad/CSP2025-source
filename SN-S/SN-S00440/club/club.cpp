#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second
#define pb push_back
#define bs basic_string
#define sz(v) (LL)(v).size()
#define cir(x) rep(__tmp, 1, x)
#define rd(x) scanf("%lld", &(x))
#define all(v) (v).begin(), (v).end()
#define erg(i, pre, x) for(LL i = (pre)[x];i;i = a[i].next)
#define rep(i, l, r) for(LL i = (l), _tmp = (r);i <= _tmp;i++)
#define per(i, l, r) for(LL i = (l), _tmp = (r);i >= _tmp;i--)
typedef long long LL;
typedef pair<LL, LL> PII;
const LL INF = 0x3f3f3f3f3f3f3f3f, INF_BIT = 0x3f;

const LL N = 1e5 + 10;

LL t;
LL n;
LL a[N][4];

bs<LL> b[4];

LL ans;

void solve(){
    rd(t);
    cir(t){
        rep(i, 1, 3) b[i].clear();
        ans = 0;
        
        rd(n);
        rep(i, 1, n) rep(j, 1, 3) rd(a[i][j]);
        
        rep(i, 1, n){
            LL ma = 0, mai = 0;
            rep(j, 1, 3) if(ma < a[i][j]) ma = a[i][j], mai = j;
            ans += ma;
            b[mai] += i;
        }
        LL lim = n / 2;
        rep(i, 1, 3) if(sz(b[i]) > lim){
            bs<LL> v;
            for(auto x : b[i]){
                LL ma = -INF;
                rep(j, 1, 3) if(j != i) ma = max(ma, a[x][j] - a[x][i]);
                v += ma;
            }
            sort(all(v), greater<LL>());
            rep(j, 0, sz(b[i]) - lim - 1) ans += v[j];
            break;
        }
        
        printf("%lld\n", ans);
    }
}

int main(){
    // freopen("club5.in", "r", stdin);  //std=
    // freopen("club5.out", "w", stdout);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    
    solve();
    return 0;
}

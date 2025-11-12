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

const LL N = 510, M = 510, MOD = 998244353;

LL n, m;
char s[N];
LL a[N];

#define gm(x) (((x) % MOD + MOD) % MOD)

namespace Sub1to5{
    bool check(){ return n <= 18; }
    
    LL d[1 << 18][20];
    
    LL ans;
    
    void solve(){
        d[0][0] = 1;
        rep(st, 0, (1 << n) - 2) rep(i, 0, n){
            if(d[st][i] == 0) continue;
            LL cur = 0;
            rep(j, 0, n - 1) cur += ((st >> j) & 1);
            rep(j, 0, n - 1) if(((st >> j) & 1) == 0){
                bool in = true;
                if(i >= a[j + 1] || s[cur + 1] == '0') in = false;
                d[st | (1 << j)][i + !in] = (d[st | (1 << j)][i + !in] + d[st][i]) % MOD;
            }
        }
        
        rep(i, 0, n - m) /* printf("%lld-%lld\n", i, d[(1 << n) - 1][i]), */ ans = (ans + d[(1 << n) - 1][i]) % MOD;
        printf("%lld\n", ans);
    }
}

namespace SubB{
    bool check(){
        return count(s + 1, s + n + 1, '1') <= 18;
    }
    
    LL ans;
    
    void solve(){
        
    }
}

namespace Sub12to14{
    bool check(){
        return m == 1;
    }
    
    LL ans;
    
    void solve(){
        //n!-(c[i]<i)
        bs<LL> v;
        rep(i, 1, n) v += n - a[i];
        sort(all(v));
        LL tot = 1;
        cir(n) tot = tot * __tmp % MOD;
        ans = 1;
        LL cnt = 0;
        for(auto x : v){
            LL cur = x - cnt;
            rep(i, 1, n - x) cur += s[i] == '0';
            if(cur <= 0){ ans = 0; break; }
            ans = ans * cur % MOD, cnt++;
        }
        printf("%lld\n", gm(tot - ans));
    }
}

namespace Sub15{
    bool check(){
        return m == n;
    }
    
    LL ans;
    
    void solve(){
        if(count(s + 1, s + n + 1, '0')){
            puts("0");
            return;
        }
        if(count(a + 1, a + n + 1, 0)){
            puts("0");
            return;
        }
        ans = 1;
        cir(n) ans = ans * __tmp % MOD;
        printf("%lld\n", ans);
    }
}

void solve(){
    rd(n), rd(m);
    scanf("%s", s + 1);
    rep(i, 1, n) rd(a[i]);
    
    if(Sub1to5::check()){ Sub1to5::solve(); return; }
    if(Sub12to14::check()){ Sub12to14::solve(); return; }
    if(Sub15::check()){ Sub15::solve(); return; }
    
    puts("0");
}

int main(){
    // freopen("employ4.in", "r", stdin);  //std=
    // freopen("1.out", "w", stdout);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    
    solve();
    return 0;
}

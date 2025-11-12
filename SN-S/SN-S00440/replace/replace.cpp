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

const LL N = 2e5 + 10, Q = 2e5 + 10, S = 2.5e6 + 10;

LL n, q;
string a, b;

struct OptQuery{
    string a, b;
};
OptQuery opt[N], qq[Q];

namespace Sub1to5{
    bool check(){
        LL l2 = 0;
        rep(i, 1, q) l2 += sz(qq[i].a) + sz(qq[i].b);
        return n <= 1e3 && l2 <= 2e3;
    }
    
    map<PII, map<PII, LL>> ma;
    
    const LL b1 = 128, p1 = 998244353;
    const LL b2 = 131, p2 = 1e9 + 7;
    
    PII gethash(string s){
        PII ret;
        for(auto ch : s){
            ret.fir = (ret.fir * b1 + ch) % p1;
            ret.sec = (ret.sec * b2 + ch) % p2;
        }
        return ret;
    }
    
    struct HashAll{
        struct Hash{
            LL oo;
            LL h[S];
            LL baseb[S];
            void init(LL o, string &s){
                oo = o;
                if(o == 1){
                    rep(i, 1, sz(s)) h[i] = (h[i - 1] * b1 + s[i - 1]) % p1;
                    baseb[0] = 1;
                    rep(i, 1, sz(s)) baseb[i] = baseb[i - 1] * b1 % p1;
                }else{
                    rep(i, 1, sz(s)) h[i] = (h[i - 1] * b2 + s[i - 1]) % p2;
                    baseb[0] = 1;
                    rep(i, 1, sz(s)) baseb[i] = baseb[i - 1] * b2 % p2;
                }
            }
            LL gethash(LL l, LL r){
                LL ret = h[r] - h[l - 1] * baseb[r - l + 1];
                if(oo == 1) return (ret % p1 + p1) % p1;
                else        return (ret % p2 + p2) % p2;
            }
        };
        Hash h1, h2;
        void init(string &s){
            h1.init(1, s);
            h2.init(2, s);
        }
        PII gethash(LL l, LL r){
            return make_pair(h1.gethash(l, r), h2.gethash(l, r));
        }
    };
    HashAll ha, hb;
    
    LL ans;
    
    void solve(){
        cir(n){
            auto &a = opt[__tmp].a, &b = opt[__tmp].b;
            ma[gethash(a)][gethash(b)]++;
        }
        cir(q){
            ans = 0;
            auto &a = qq[__tmp].a, &b = qq[__tmp].b;
            if(sz(a) != sz(b)){
                puts("0");
                continue;
            }
            ha.init(a);
            hb.init(b);
            LL m = sz(a);
            rep(i, 1, sz(a)){
                per(j, m, i){
                    auto from = ha.gethash(i, j), to = hb.gethash(i, j);
                    ans += ma[from][to];
                    // printf("%lld~%lld : %lld\n", i, j, ma[from][to]);
                    if(ha.gethash(j, m) != hb.gethash(j, m)) break;
                }
                if(ha.gethash(1, i) != hb.gethash(1, i)) break;
            }
            printf("%lld\n", ans);
        }
    }
}

namespace SubB{
    bool check(){
        auto subcheck = [&](string &s) -> bool {
            LL cnt = 0;
            for(auto ch : s){
                if(ch > 'b') return false;
                cnt += (ch == 'b');
                if(cnt > 1) return false;
            }
            return cnt == 1;
        };
        rep(i, 1, n){
            auto &a = opt[i].a, &b = opt[i].b;
            if(!subcheck(a) || !subcheck(b)) return false;
        }
        rep(i, 1, q){
            auto &a = qq[i].a, &b = qq[i].b;
            if(!subcheck(a) || !subcheck(b)) return false;
        }
        return true;
    }
    
    struct SOQ{
        LL opt;
        LL x, y;
        LL qid;
    };
    unordered_map<LL, vector<SOQ>> ma;
    
    LL lim;
    
    #define lowbit(x) ((x) & (-(x)))
    LL c[S];
    void add(LL x, LL v){ for(LL i = x;i <= lim;i += lowbit(i)) c[i] += v; }
    LL query(LL x){ LL ret = 0; for(LL i = x;i;i -= lowbit(i)) ret += c[i]; return ret; }
    
    LL ans[Q];
    
    void solve(){
        // puts("---");
        auto getp = [&](string &s) -> LL {
            rep(i, 1, sz(s)) if(s[i - 1] == 'b') return i;
            return -1;
        };
        cir(n){
            auto &a = opt[__tmp].a, &b = opt[__tmp].b;
            LL pa = getp(a), pb = getp(b), pos = pb - pa;
            SOQ add;
            add.opt = 1;
            add.x = pa - 1, add.y = sz(a) - pa;
            add.qid = 0;
            ma[pos].pb(add);
            // printf("%lld - %lld,%lld\n", pos, add.x, add.y);
        }
        // puts("---");
        cir(q){
            auto &a = qq[__tmp].a, &b = qq[__tmp].b;
            if(sz(a) != sz(b)){
                ans[__tmp] = 0;
                continue;
            }
            LL pa = getp(a), pb = getp(b), pos = pb - pa;
            SOQ add;
            add.opt = 2;
            add.x = pa - 1, add.y = sz(a) - pa;
            add.qid = __tmp;
            ma[pos].pb(add);
            /*
            LL x = pa - 1, y = sz(a) - pa;
            // printf("? %lld - %lld,%lld\n", pos, x, y);
            LL ret = 0;
            for(auto it : ma[pos]) if(it.x >= x && it.y >= y) ret++;
            ans[__tmp] = ret;
            */
        }
        // puts("---");
        
        for(auto &it : ma){
            auto &cv = it.sec;
            sort(all(cv), [](SOQ a, SOQ b){
                if(a.x != b.x) return a.x < b.x;
                else if(a.y != b.y) return a.y < b.y;
                else return a.opt < b.opt;
            });
            lim = 0;
            for(auto &it : cv) it.y++, lim = max(lim, it.y);
            for(auto it : cv){
                LL opt = it.opt;
                LL x = it.x, y = it.y;
                LL qid = it.qid;
                if(opt == 1) add(y, 1) /* , printf("add %lld %lld\n", x, y) */;
                else ans[qid] += query(y) /* , printf("query %lld %lld -> %lld\n", x, y, qid) */;
            }
            for(auto it : cv) if(it.opt == 1) add(it.y, -1);
            /*
            auto &cv = it.sec;
            vector<PII> v;
            for(auto it : cv){
                LL opt = it.opt;
                LL x = it.x, y = it.y;
                LL qid = it.qid;
                if(opt == 1) v.pb({x, y});
                else{
                    for(auto it : v) if(it.fir >= x && it.fir >= y) ans[qid]++;
                }
            }
            */
        }
        // puts("---");
        
        rep(i, 1, q) printf("%lld\n", ans[i]);
    }
}

void solve(){
    // printf("Memory : %.2lf MB\n", 1.0 * (2 * sizeof(Sub1to5::ha)) / 1024 / 1024);
    
    rd(n), rd(q);
    rep(i, 1, n){
        cin >> a >> b;
        opt[i] = {a, b};
    }
    rep(i, 1, q){
        cin >> a >> b;
        qq[i] = {a, b};
    }
    
    if(Sub1to5::check()){ Sub1to5::solve(); return; }
    if(SubB::check()){ SubB::solve(); return; }
    
    cir(q) puts("0");
}

int main(){
    // freopen("replace4.in", "r", stdin);  //std=
    // freopen("replace4.out", "w", stdout);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    
    solve();
    return 0;
}

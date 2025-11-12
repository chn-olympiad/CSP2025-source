#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e18;
#define Max(x,y) x = max(x,y)
#define Min(x,y) x = min(x,y)
#define fr(i,l,r) for (i=(l); i<=(r); i++)
#define rfr(i,l,r) for (i=(l); i>=(r); i--)
template<typename T>inline void read(T &n){
    T w = 1; n = 0; char ch = getchar();
    while (!isdigit(ch) && ch!=EOF){
        if (ch=='-') w = -1;
        ch = getchar();
    }
    while (isdigit(ch) && ch!=EOF){
        n = n*10 + ch-'0';
        ch = getchar();
    }
    n *= w;
}
const ll N = 200005, S = 5000005, B = 233, p1 = 721587059, p2 = 761926883;
ll n,qs;
string s,t,L,R;
ll af[N];
struct Hash{
    ll x,y;
    bool operator == (const Hash o)const{
        return x==o.x && y==o.y;
    }
    bool operator < (const Hash o)const{
        if (x!=o.x) return x<o.x;
        return y<o.y;
    }
    bool operator > (const Hash o)const{
        if (x!=o.x) return x>o.x;
        return y>o.y;
    }
    void ins(ll p){
        x = (x*B+p)%p1;
        y = (y*B+p)%p2;
    }
};
ll cnt; map<pair<Hash,Hash>,ll> mp;
struct infor{
    ll op,id;
    string L,R;
};
vector<infor> c[N];
struct Trie{
    ll cnt,rt,tms;
    struct node{
        ll dfn,rh;
        map<ll,ll> mp;
        void init(){ mp.clear(), dfn = 0; }
    }t[S];
    void init(){
        ll i;
        fr(i,0,cnt+1) t[i].init();
        cnt = rt = 1;
    }
    ll nww(){
        t[++cnt].init();
        return cnt;
    }
    ll ins(string &s){
        ll i, len = s.size()-1, x = rt;
        fr(i,0,len){
            ll nw = s[i]-'a';
            if (!t[x].mp.count(nw)) t[x].mp[nw] = nww();
            x = t[x].mp[nw];
        }
        return x;
    }
    void dfs(ll x){
        t[x].dfn = ++tms;
        for (auto go:t[x].mp) dfs(go.second);
        t[x].rh = tms;
    }
    void build(){ tms = 0, dfs(rt); }
    ll getp(string &s){
        ll i, len = s.size()-1, x = rt;
        fr(i,0,len){
            ll nw = s[i]-'a';
            if (!t[x].mp.count(nw)) return t[x].dfn;
            x = t[x].mp[nw];
        }
        return t[x].dfn;
    }
}tl,tr;
ll pl[N], pr[N];
struct opt{ ll x,y,v; };
struct qus{ ll x,id; };
vector<opt> g[S];
vector<qus> q[S];
void ins(ll l1,ll r1,ll l2,ll r2){
    g[l1].push_back(opt{l2,r2,1});
    g[r1+1].push_back(opt{l2,r2,-1});
}
struct BIT{
    ll n, t[S];
    void init(ll _n){
        ll i;
        n = _n;
        fr(i,0,n+1) t[i] = 0;
    }
    void pls(ll x,ll v){
        for (;x<=n; x+=x&-x) t[x] += v;
    }
    void add(ll l,ll r,ll v){
        pls(l,v), pls(r+1,-v);
    }
    ll qry(ll x){
        ll ans = 0;
        for (;x; x-=x&-x) ans += t[x];
        return ans;
    }
}bit;
void solve(vector<infor> &c){
    // printf("\n\nsolve\n");
    // for (auto p:c){
    //     printf("op = %lld , ",p.op);
    //     cout<<p.L<<" "<<p.R<<endl;
    // }
    ll i,j;
    tl.init(), tr.init();
    for (i=0; i<c.size(); i++){
        if (c[i].op==2) break;
        pl[i] = tl.ins(c[i].L);
        pr[i] = tr.ins(c[i].R);
    }
    tl.build(), tr.build();
    ll sl = tl.cnt, sr = tr.cnt;
    fr(i,0,sl+1) g[i].clear(), q[i].clear();
    for (i=0; i<c.size(); i++){
        if (c[i].op==2) break;
        ins(tl.t[pl[i]].dfn,tl.t[pl[i]].rh,tr.t[pr[i]].dfn,tr.t[pr[i]].rh);
    }
    for (i=0; i<c.size(); i++){
        if (c[i].op==1) continue;
        ll x = tl.getp(c[i].L), y = tr.getp(c[i].R);
        q[x].push_back(qus{y,c[i].id});
    }
    bit.init(sr);
    fr(i,1,sl){
        for (auto p:g[i]) bit.add(p.x,p.y,p.v);
        for (auto p:q[i]) af[p.id] = bit.qry(p.x);
    }
}
void get_in(string &s){
    char ch = getchar();
    while (ch<'a' || ch>'z') ch = getchar();
    s = "";
    while (ch>='a' && ch<='z') s += ch, ch = getchar();
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ll i,j;
    read(n), read(qs);
    fr(i,1,n){
        // printf("\n");
        get_in(s), get_in(t);
        // cin>>s>>t;
        ll len = s.size()-1, l = inf, r = -inf;
        fr(j,0,len)
            if (s[j]!=t[j]) Min(l,j), Max(r,j);
        pair<Hash,Hash> p = make_pair(Hash{0,0},Hash{0,0});
        // printf("l = %lld , r = %lld\n",l,r);
        if (l<=r)
            fr(j,l,r) p.first.ins(s[j]), p.second.ins(t[j]);
        // printf("(%lld,%lld) , (%lld,%lld) \n",p.first.x,p.first.y,p.second.x,p.second.y);
        if (!mp.count(p)) mp[p] = ++cnt;
        L = R = "";
        if (l>r) R = s;
        else {
            rfr(j,l-1,0) L += s[j];
            fr(j,r+1,len) R += s[j];
        }
        infor v;
        v.op = 1, v.id = 0;
        v.L = L, v.R = R;
        // printf("i = %lld : id = %lld\n",i,mp[p]);
        c[mp[p]].push_back(v);
    }
    fr(i,1,qs){
        get_in(s), get_in(t);
        // cin>>s>>t;
        ll len = s.size()-1, l = inf, r = -inf;
        fr(j,0,len)
            if (s[j]!=t[j]) Min(l,j), Max(r,j);
        pair<Hash,Hash> p = make_pair(Hash{0,0},Hash{0,0});
        if (l<=r)
            fr(j,l,r) p.first.ins(s[j]), p.second.ins(t[j]);
        if (!mp.count(p)) continue;
        L = R = "";
        if (l>r) R = s;
        else {
            rfr(j,l-1,0) L += s[j];
            fr(j,r+1,len) R += s[j];
        }
        infor v;
        v.op = 2, v.id = i;
        v.L = L, v.R = R;
        c[mp[p]].push_back(v);
    }
    fr(i,1,cnt){
        if (c[i].empty() || c[i].back().op==1) continue;
        solve(c[i]);
    }
    fr(i,1,qs) printf("%lld\n",af[i]);
    return 0;
}
//g++ replace.cpp -o a -Wall -O2 -std=c++11
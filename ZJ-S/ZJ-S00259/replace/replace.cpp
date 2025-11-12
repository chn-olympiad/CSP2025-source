#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(k,l,r) for(int k=l;k<=r;++k)
#define per(k,r,l) for(int k=r;k>=l;--k)
#define ll long long 
#define ull unsigned long long
#define PII pair<int,int>
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define ld double
#define cl(f,x) memset(f,x,sizeof(f))
using namespace std;
void file_IO() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
}
bool M1;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const ld eps=1e-9;
const int N=5e6+5,M=26;
int trie[N][M],ans[N],l[N],r[N],pp,p;
bool ed[N];
void dfs(int u) {
    if(ed[u])
        ++pp;
    l[u]=pp;
    rep(i,0,25) {
        if(trie[u][i])
            dfs(trie[u][i]);
    }
    r[u]=pp;
}
struct BIT {
    int tree[N];
    void update(int x,int k) {
        while(x<=pp)
            tree[x]+=k,x+=x&-x;
    }
    void update(int l,int r,int k) {
        update(l,k);
        update(r+1,-k);
    }
    int query(int x) {
        int res=0;
        while(x)
            res+=tree[x],x-=x&-x;
        return res;
    }
}; BIT T;
unordered_map<ull,vector<PII>> vec;
const ull base=1145141,baset=233;
char s[N],t[N];
ull pw[N];
void init(int n=5e6) {
    pw[0]=1;
    rep(i,1,n)
        pw[i]=pw[i-1]*base;
}
ull hs[N],ht[N];
ull calcs(int l,int r) {
    return hs[r]-hs[l-1]*pw[r-l+1];
}
ull calct(int l,int r) {
    return ht[r]-ht[l-1]*pw[r-l+1];
}
void solve() {
    int n,q;
    scanf("%d%d",&n,&q);
    while(n--) {
        scanf("%s",s+1);
        scanf("%s",t+1);
        int n=strlen(s+1);
        int l=1,r=n;
        while(l<=n&&s[l]==t[l])
            ++l;
        while(r>=1&&s[r]==t[r])
            --r;
        if(l==n+1)
            continue;
        rep(i,1,n) {
            hs[i]=hs[i-1]*base+s[i];
            ht[i]=ht[i-1]*base+t[i];
        }
        ull val=calcs(1,l-1)*baset*baset+calcs(l,r)*baset+calct(l,r);
        int q=0;
        rep(i,r+1,n) {
            int ch=s[i]-'a';
            if(!trie[q][ch])
                trie[q][ch]=++p;
            q=trie[q][ch];
        }
        ed[q]=true;
        vec[val].push_back(make_pair(q,0));
    }
    rep(k,1,q) {
        scanf("%s",s+1);
        scanf("%s",t+1);
        int n=strlen(s+1);
        if(n!=(int)strlen(t+1)) {
            puts("0");
            continue;
        }
        int l=1,r=n;
        while(l<=n&&s[l]==t[l])
            ++l;
        while(r>=1&&s[r]==t[r])
            --r;
        rep(i,1,n) {
            hs[i]=hs[i-1]*base+s[i];
            ht[i]=ht[i-1]*base+t[i];
        }
        int q=0;
        rep(i,r+1,n) {
            int ch=s[i]-'a';
            if(!trie[q][ch])
                trie[q][ch]=++p;
            q=trie[q][ch];
        }
        ed[q]=true;
        rep(i,1,l) {
            ull val=calcs(i,l-1)*baset*baset+calcs(l,r)*baset+calct(l,r);
            if(vec.count(val))
                vec[val].push_back(make_pair(q,k));
        }
    }
    dfs(0);
    for(auto x:vec) {
        for(auto y:x.second) {
            if(!y.second)
                T.update(l[y.first],r[y.first],1);
        }
        for(auto y:x.second) {
            if(y.second)
                ans[y.second]+=T.query(l[y.first]);
        }
        for(auto y:x.second) {
            if(!y.second)
                T.update(l[y.first],r[y.first],-1);
        }
    }
    rep(i,1,q)
        printf("%d\n",ans[i]);
}
bool M2;
// g++ replace.cpp -std=c++14 -Wall -O2 -o replace
signed main() {
    file_IO();
    int testcase=1;
    init();
    // scanf("%d",&testcase);
    while(testcase--)
        solve();
    // debug("used time = %dms\n",(signed)(1000*clock()/CLOCKS_PER_SEC));
    // debug("used memory = %dMB\n",(signed)((&M2-&M1)/1024/1024));
    return 0;
}
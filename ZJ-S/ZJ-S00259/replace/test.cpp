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
const int M=5e6+5;
const ull base=1145141;
ull p[M];
void init(int n=5e6) {
    p[0]=1;
    rep(i,1,n)
        p[i]=p[i-1]*base;
}
struct node {
    int len1,len2;
    ull h1,h2;
    node() {
        len1=len2=0;
        h1=h2=0;
    }
    node(int a,ull b,int c,ull d) {
        len1=a; h1=b; len2=c; h2=d;
    }
    bool operator < (const node &tmp) const {
        return len1<tmp.len1;
    }
}; map<pair<ull,ull>,vector<node>> vec;
char s[M],t[M];
ull hs[M],ht[M];
ull calcs(int l,int r) {
    return hs[r]-hs[l-1]*p[r-l+1];
}
ull calct(int l,int r) {
    return ht[r]-ht[l-1]*p[r-l+1];
}
void solve() {
    int n,q;
    scanf("%d%d",&n,&q);
    while(n--) {
        scanf("%s",s+1);
        scanf("%s",t+1);
        int n=strlen(s+1);
        rep(i,1,n) {
            hs[i]=hs[i-1]*base+s[i];
            ht[i]=ht[i-1]*base+t[i];
        }
        int l=1,r=n;
        while(l<=n&&s[l]==t[l])
            ++l;
        while(r>=1&&s[r]==t[r])
            --r;
        if(l==n+1)
            continue;
        vec[make_pair(calcs(l,r),calct(l,r))].push_back(node(l-1,calcs(1,l-1),n-r,calct(r+1,n)));
    }
    for(auto &x:vec)
        sort(x.second.begin(),x.second.end());
    while(q--) {
        scanf("%s",s+1);
        scanf("%s",t+1);
        int n=strlen(s+1);
        if(n!=(int)strlen(t+1)) {
            puts("0");
            continue;
        }
        rep(i,1,n) {
            hs[i]=hs[i-1]*base+s[i];
            ht[i]=ht[i-1]*base+t[i];
        }
        int l=1,r=n;
        while(l<=n&&s[l]==t[l])
            ++l;
        while(r>=1&&s[r]==t[r])
            --r;
        vector<node> &tvec=vec[make_pair(calcs(l,r),calct(l,r))];
        int res=0,k=0;
        rep(i,0,l-1) {
            while(k<(int)tvec.size()&&tvec[k].len1==i) {
                if(calcs(l-tvec[k].len1,l-1)==tvec[k].h1)
                    res+=(int)tvec[k].len2<=n-r&&calcs(r+1,r+tvec[k].len2)==tvec[k].h2;
                ++k;
            }
        }
        printf("%d\n",res);
    }
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
    debug("used time = %dms\n",(signed)(1000*clock()/CLOCKS_PER_SEC));
    debug("used memory = %dMB\n",(signed)((&M2-&M1)/1024/1024));
    return 0;
}
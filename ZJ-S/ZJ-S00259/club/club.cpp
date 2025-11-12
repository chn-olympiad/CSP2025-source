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
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
}
bool M1;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const ld eps=1e-9;
const int N=1e5+5;
int bl[N],d[N],a[3],p[3],cnt[3],t[N];
void solve() {
    int n;
    scanf("%d",&n);
    cnt[0]=cnt[1]=cnt[2]=0;
    int res=0;
    rep(i,1,n) {
        rep(i,0,2)
            scanf("%d",&a[i]),p[i]=i;
        sort(p,p+3,[](const int &x,const int &y) {
            return a[x]>a[y];
        });
        bl[i]=p[0];
        ++cnt[bl[i]];
        res+=a[p[0]];
        d[i]=a[p[0]]-a[p[1]];
    }
    int k=-1;
    rep(i,0,2) {
        if(cnt[i]>n/2)
            k=i;
    }
    if(k==-1) {
        printf("%d\n",res);
        return;
    }
    int m=cnt[k]-n/2,len=0;
    rep(i,1,n) {
        if(bl[i]==k)
            t[++len]=d[i];
    }
    sort(t+1,t+len+1);
    rep(i,1,m)
        res-=t[i];
    printf("%d\n",res);
}
bool M2;
// g++ club.cpp -std=c++14 -Wall -O2 -o club
signed main() {
    file_IO();
    int testcase=1;
    scanf("%d",&testcase);
    while(testcase--)
        solve();
    // debug("used time = %dms\n",(signed)(1000*clock()/CLOCKS_PER_SEC));
    // debug("used memory = %dMB\n",(signed)((&M2-&M1)/1024/1024));
    return 0;
}
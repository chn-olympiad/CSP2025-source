#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
const int K=20;
typedef long long ll;

int read() {
    int s=0;
    char c=getchar();
    while(c<'0' || c>'9') c=getchar();
    while(c>='0' && c<='9') s=s*10+c-'0',c=getchar();
    return s;
}

int n,m,k;
pair<int,pair<int,int> > e[M];
int c[K];
int a[K][N];
int fa[N+K];

int get(int x) {
    if(fa[x]==x) return x;
    return fa[x]=get(fa[x]);
}

void mg(int u,int v) {
    u=get(u),v=get(v);
    if(u==v) return ;
    fa[u]=v;
}

void init(int n) {
    for(int i=1;i<=n;i++) fa[i]=i;
}

int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++) {
        int u=read(),v=read(),w=read();
        e[i]={w,{u,v}};
    }
    sort(e+1,e+1+m);
    vector<pair<int,pair<int,int> > > arr;
    for(int i=1;i<=k;i++) {
        c[i]=read();
        for(int j=1;j<=n;j++) a[i][j]=read(),arr.push_back({a[i][j],{i,j}});
    }
    sort(arr.begin(),arr.end());
    vector<int> et;
    ll sum=0;
    init(n);
    for(int i=1;i<=m;i++) {
        int u=e[i].second.first,v=e[i].second.second,w=e[i].first;
        u=get(u),v=get(v);
        if(u==v) continue;
        et.push_back(i);
        sum+=w;
        mg(u,v);
    }
    ll ans=sum;
    for(int i=1;i<1<<k;i++) {
        sum=0;
        for(int j=1;j<=k;j++) if(i>>j-1&1) sum+=c[j];
        init(n+k);
        int p=0,q=0;
        int tot=n+__builtin_popcount(i)-1;
        while((p<et.size() || q<arr.size()) && tot>0) {
            if(p>=et.size() || (q<arr.size() && arr[q].first<e[et[p]].first)) {
                int u=n+arr[q].second.first,v=arr[q].second.second,w=arr[q].first;
                q++;
                if(!(i>>u-n-1&1)) continue;
                u=get(u),v=get(v);
                if(u==v) continue;
                tot--;
                sum+=w;
                mg(u,v);
            }
            else {
                int u=e[et[p]].second.first,v=e[et[p]].second.second,w=e[et[p]].first;
                p++;
                u=get(u),v=get(v);
                if(u==v) continue;
                tot--;
                sum+=w;
                mg(u,v);
            }
        }
        ans=min(ans,sum);
    }
    printf("%lld",ans);
    return 0;
}
//15:01
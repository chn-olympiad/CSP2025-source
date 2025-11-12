#include <bits/stdc++.h>
#define int long long 
#define pii pair<int,int>
#define fi first
#define se second
// !
using namespace std;
const int INFM=1e6+5;
const int INFN=2e4+5;
const int INF=3e5+5;
const int oo=1e18;
struct E{int x,y,z;}e[INFM],e2[INFM];
pii a[13][INFN];int cnt4[13],l[13];
int n,m,k,c[13],fa_set[INFN],id[13],tote2;
int find_set(int x) {return x==fa_set[x]?x:fa_set[x]=find_set(fa_set[x]);}
void mer(int x,int y) {x=find_set(x);y=find_set(y);fa_set[x]=y;}
int ck(E x,E y){return x.z<y.z;}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) 
        cin>>e[i].x>>e[i].y>>e[i].z;
    for (int i=1;i<=k;i++) {
        cin>>c[i];
        for (int j=1;j<=n;j++) 
            cin>>a[i][j].fi,a[i][j].se=j;
        sort(a[i]+1,a[i]+1+n,[](pii X,pii Y){return X<Y;});
    }
    for (int i=1;i<=n;i++) fa_set[i]=i;
    sort(e+1,e+1+m,[](E xx,E yy){return xx.z<yy.z;});
    for (int i=1;i<=m;i++) {
        int x=find_set(e[i].x),y=find_set(e[i].y);
        if (x==y) continue;
        mer(x,y);e2[++tote2]=e[i];
    }
    int res=1e18;
    for (int u=0;u<(1<<k);u++) {
        for (int w=1;w<=k;w++) id[w]=(u>>(w-1))&1;
        int sum4=0;
        for (int w=1;w<=k;w++)
            if (id[w]) sum4+=c[w];
        if (sum4>=res) continue;
        for (int x=1;x<=n+k;x++) fa_set[x]=x;
        cnt4[0]=0; l[0]=1;
        for (int w=1;w<=k;w++) l[w]=1;
        for (int w=1;w<=k;w++)
            if (id[w]) cnt4[++cnt4[0]]=w;
        int cnt=0;
        while (cnt<n+cnt4[0]-1) {
            if (sum4>=res) break;
            E Min={0,0,oo};int op=0;
            while (l[0]<=tote2 && find_set(e2[l[0]].x)==find_set(e2[l[0]].y)) l[0]++;
            if (l[0]<=tote2 && e2[l[0]].z<Min.z) Min=e2[l[0]],op=0;
            for (int x=1;x<=cnt4[0];x++) {
                while (l[x]<=n && find_set(cnt4[x]+n)==find_set(a[cnt4[x]][l[x]].se)) l[x]++;
                if (l[x]<=n && a[cnt4[x]][l[x]].fi<Min.z)
                    Min={cnt4[x]+n,a[cnt4[x]][l[x]].se,a[cnt4[x]][l[x]].fi},op=x;
            }
            if (Min.z==oo) break;
            l[op]++;
            mer(Min.x,Min.y);
            sum4+=Min.z;cnt++;
            // if (u==5) cout<<Min.x<<" "<<Min.y<<" "<<Min.z<<" "<<cnt4[1]<<" "<<cnt4[2]<<" "<<a[cnt4[2]][l[2]].fi<<" qwq?\n";
        }
        if (cnt==n+cnt4[0]-1) 
            res=min(res,sum4);
    }
    cout<<res<<"\n";
    return 0;
}
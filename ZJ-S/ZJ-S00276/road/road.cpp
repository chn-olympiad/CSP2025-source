#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,l,r) for(int i=l;i<=r;++i)
#define F_(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define SZ(a) ((int)(a).size())
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define gc getchar

const int N = 1e5 + 100;
const int mod = 0;
const int INF = 1e18;

int rd(){
    int x=0,y=1;
    char c=gc();
    for(;!isdigit(c);c=getchar()){
        if(c=='-')y=-1;
    }
    for(;isdigit(c);c=getchar()){
        x=(x<<3)+(x<<1)+(c^48);
    }
    return x*y;
}

void cmx(int &a,int b){
    a=max(a,b);
}

void cmn(int &a,int b){
    a=min(a,b);
}

void add(int &a,int b){
    a+=b;
    if(a>=mod){
        a-=mod;
    }
}

int n,k,m,fa[N],x,c[11];

struct road{
    int u,v,w;
    friend bool operator<(const road &a,const road &b){
        return a.w<b.w;
    }
}E[N*10],E1[11][N];

int find(int x){
    return fa[x]=x==fa[x]?fa[x]:find(fa[x]);
}

void SOLVE(){
    n=rd(),m=rd(),k=rd();
    x=0;
    F(i,1,m){
        E[i].u=rd(),E[i].v=rd(),E[i].w=rd();
    }
    F(i,1,n){
        fa[i]=i;
    }
    sort(E+1,E+m+1);
    int ans=0,cnt=0;
    F(i,1,m){
        int u=E[i].u,v=E[i].v,w=E[i].w;
        u=find(u),v=find(v);
        if(u==v){
            continue;
        }
        fa[u]=v;
        ans+=w;
        ++cnt;
        E1[0][++x]=E[i];
        if(cnt==n-1){
            break;
        }
    }
    // cerr<<ans<<'\n';
    m=n-1;
    F(i,1,k){
        c[i]=rd();
        F(j,1,n){
            int w=rd();
            E1[i][j]=(road){i+n,j,w};
        }
        sort(E1[i]+1,E1[i]+n+1);
    }
    vector<pii>p;
    F(S,0,(1<<k)-1){
        p.clear();
        p.pb(mp(0ll,0ll));
        int res=0,num=n;
        F(i,1,k){
            if((S>>(i-1))&1){
                p.pb({i,0ll});
                res+=c[i];
                ++num;
            }
        }
        // if(S<=10)
        // cerr<<num<<'\n';
        F(i,1,n+k){
            fa[i]=i;
        }
        cnt=0;
        while(true){
            int q=-1,mn=INF;
            int id=0,s=0;
            F(i,0,SZ(p)-1){
                id=p[i].fi,s=p[i].se;
                if(s+1<=n&&E1[id][s+1].w<mn){
                    mn=E1[id][s+1].w,q=i;
                }
            }
            ++p[q].se;
            id=p[q].fi,s=p[q].se;
            int u=E1[id][s].u,v=E1[id][s].v;
            u=find(u),v=find(v);
            if(u==v){
                continue;
            }
            ++cnt;
            res+=mn;
            fa[u]=v;
            if(cnt==num-1){
                break;
            }
        }
        cmn(ans,res);
    }
    printf("%lld\n",ans);
    return ;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int T=1;
    while(T--){
        SOLVE();
    }
    return 0;
}
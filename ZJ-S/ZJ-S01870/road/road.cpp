// #define NDEBUG
#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);i++)
#define ForD(i,j,k) for(int i=(j);i>=(k);i--)
#define int long long
#define endl '\n'
using namespace std;
bool Mbe;
const int N=1e4+5,M=1e6+5,K=12,inf=1e18;
int n,m,k;
int fa[N];
tuple<int,int> vl[K][N];
int ff(int x){return x==fa[x]?x:fa[x]=ff(fa[x]);}
tuple<int,int,int> edge[M];
int c[K];
int Ans=inf;
void dfs(int lim,int len,int W){
    tuple<int,int,int> his[N];
    int ans=W;
    For(i,1,len) his[i]=edge[i],ans+=get<0>(edge[i]);
    Ans=min(ans,Ans);
    For(i,1,n+k) fa[i]=i;
    For(i,lim+1,k){
        int tot=0;
        int pt1=1,pt2=1;
        while(pt1<=len&&pt2<=n){
            if(pt1>len||(pt2<=n&&get<0>(his[pt1])>=get<0>(vl[i][pt2]))){
                int w,v,u=i+n;
                tie(w,v)=vl[i][pt2];
                if(ff(u)!=ff(v)){
                    fa[ff(u)]=ff(v);
                    edge[++tot]={w,u,v};
                }
                pt2++;
            }else{
                int u,v,w;
                tie(w,u,v)=his[pt1];
                if(ff(u)!=ff(v)){
                    fa[ff(u)]=ff(v);
                    edge[++tot]={w,u,v};
                }
                pt1++;
            }
        }
        // assert(tot==len+1);
        dfs(i,tot,W+c[i]);
    }
}
void solve(){
    cin>>n>>m>>k;
    For(i,1,m){
        int u,v,w; cin>>u>>v>>w;
        edge[i]={w,u,v};
    }
    For(i,1,n+k) fa[i]=i;
    sort(edge+1,edge+m+1);
    int tot=0;
    For(i,1,m){
        int u,v,w;
        tie(w,u,v)=edge[i];
        if(ff(u)!=ff(v)){
            fa[ff(u)]=ff(v);
            edge[++tot]={w,u,v};
        }
    }
    For(i,1,k){
        cin>>c[i];
        For(j,1,n){
            int val; cin>>val;
            vl[i][j]={val,j};
        }
        sort(vl[i]+1,vl[i]+n+1);
    }
    dfs(0,n-1,0);
    cout<<Ans<<endl;
}
bool Med;
signed main(){
    fprintf(stderr,"%.3lf MB\n",(&Mbe-&Med)/1048576.0);
    freopen("road.in","r",stdin), freopen("road.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--) solve();
    cerr<<1e3*clock()/CLOCKS_PER_SEC<<" ms\n";
    return 0;
}
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define m(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e4+100,M=1e6+10;
int n,m,k,T,ans,fa[N],cnt;
struct node{
	int u,v,w;
}e[M],g[N],g1[N*11];
struct nd{
	int pos;
	int w[N];
}c[11];
bool cmp(node a,node b){
	return a.w<b.w;
}
inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int ksk(int tmp){
	rep(i,1,n+20) fa[i]=i;
	sort(g1+1,g1+tmp+1,cmp);
	int sum=0;
	rep(i,1,tmp){
		int u=g1[i].u,v=g1[i].v,w=g1[i].w;
		if(find(u)!=find(v)){
			sum+=w;
			fa[find(u)]=find(v);
		}	
	}return sum;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    rep(i,1,n) fa[i]=i;
    rep(i,1,m){
    	int u,v,w;cin>>u>>v>>w;
    	e[i]={u,v,w};
	}sort(e+1,e+m+1,cmp);
	rep(i,1,m){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)){
			g[++cnt]={u,v,w};ans+=w;
			fa[find(u)]=find(v);
		}
	}
	rep(i,0,k-1){
		int x;cin>>x;
		c[i].pos=x;
		rep(j,1,n){
			int y;cin>>y;
			c[i].w[j]=y;
		}
	}
	for(int i=1;i<(1<<k);i++){
		int tmp=cnt,sum=0;
		rep(j,1,cnt) g1[j]=g[j];
		rep(j,0,k-1){
			if((i&(1<<j))){sum+=c[j].pos;
				rep(x,1,n){
					g1[++tmp]={j+1+n,x,c[j].w[x]};
				}
			}
		}
		ans=min(ans,ksk(tmp)+sum);
		rep(j,1,tmp) g1[j]={0,0,0};
	}cout<<ans;
	return 0;
}

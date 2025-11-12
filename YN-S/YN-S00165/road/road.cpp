//I love Nagato Yuki forever!!!
//Begin at 2025/11/01 16:19:14 
//Finish at 2025/11/01 16:50:32
#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace Z3k7223{
	const int N=1e4+10,K=1050,M=1e6+10;
	struct node{
		int u,v,w;
		friend bool operator<(node x,node y){
			return x.w<y.w;
		}
	}g[M],rg[K][N];
	int tot;
	int fa[N];
	int n,m,k;
	int a[13][N],pos[13];
	ll val[13],sumv[K];
	ll f[K];
	int find(int x){
		if(fa[x]==x){
			return x;
		}else{
			return fa[x]=find(fa[x]);
		}
	}
	void merge(int x,int y){
		int fx=find(x),fy=find(y);
		if(fx==fy){
			return;
		}
		fa[fx]=fy;
	}
	ll MST(int s){
		sort(g+1,g+1+tot);
		for(int i=1;i<=n;i++)fa[i]=i;
		ll res=0,now=0;
		for(int i=1;i<=tot;i++){
			if(find(g[i].u)==find(g[i].v)){
				continue;
			}
			res+=g[i].w;
			rg[s][++now]=g[i];
			merge(g[i].u,g[i].v);
			if(now==n-1){
				break;
			}
		}
		return res;
	}
	void main(){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
		}
		tot=m;
		f[0]=MST(0);
		ll ans=f[0];
		for(int i=0;i<k;i++){
			scanf("%lld",&val[i]);
			pos[i]=1;
			for(int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
				if(a[i][pos[i]]>a[i][j]){
					pos[i]=j;
				}
			}
			val[i]+=a[i][pos[i]];
		}
		for(int i=1;i<(1<<k);i++){
			int prev=i,prej=0;
			for(int j=0;j<k;j++){
				if(i&(1<<j)){
					prej=j;
					prev^=(1<<j);
					break;
				}
			}
			sumv[i]=sumv[prev]+val[prej];
			tot=0;
			for(int j=1;j<n;j++){
				g[++tot]=rg[prev][j];
			}
			for(int j=1;j<=n;j++){
				if(j==pos[prej])continue;
				g[++tot]=(node){pos[prej],j,a[prej][j]};
			}
			f[i]=MST(i);
			ans=min(ans,f[i]+sumv[i]);
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Z3k7223::main();
	return 0;
}

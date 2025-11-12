#include<bits/stdc++.h>
using namespace std;
const int M=1e6+1e5+5;
const int N=1e4+5;
using ll=long long;
const ll INF=1e18;
ll ans[1<<10],c[N];
int l[1<<10],fa[N][1<<10];
struct edge{
	int u,v;
	ll w;
}e[M];
int query(int u,int x){
	return fa[u][x]==u?u:fa[u][x]=query(fa[u][x],x);
}
int tot;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&e[i].u,&e[i].v,&e[i].w);
	}
	tot=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			e[++tot].u=i+n;
			e[tot].v=j;
			cin>>e[tot].w;
		}
	}
	sort(e+1,e+tot+1,[](edge a,edge b){
		return a.w<b.w;
	});
	for(int i=0;i<1<<k;i++){
		l[i]=n;
		for(int j=0;j<=k-1;j++){
			if((i>>j)&1){
				ans[i]+=c[j+1];
				l[i]++;
			}
		}
	}
	for(int i=1;i<=n+k;i++){
		for(int j=0;j<1<<k;j++){
			fa[i][j]=i;
		}
	}
	for(int i=1;i<=tot;i++){
		if(e[i].u<=n){
			int qu=query(e[i].u,0),qv=query(e[i].v,0);
			if(qu!=qv){
				fa[qu][0]=qv;
				l[0]--;
				ans[0]+=e[i].w;
				for(int j=1;j<1<<k;j++){
					int qu2=query(e[i].u,j),qv2=query(e[i].v,j);
					if(qu2!=qv2){
						fa[qu2][j]=qv2;
						l[j]--;
						ans[j]+=e[i].w;
					}
				}
				if(!l[0])break;
			}
		}else{
			int a=e[i].u-n;
			int qu=query(e[i].u,0),qv=query(e[i].v,0);
			if(qu!=qv){
				qu=query(e[i].u,1<<(a-1)),qv=query(e[i].v,1<<(a-1));
				if(qu!=qv){
					for(int j=1;j<1<<k;j++){
						qu=query(e[i].u,j),qv=query(e[i].v,j);
						if(qu!=qv&&(j&(1<<(a-1)))){
							fa[qu][j]=qv;
							ans[j]+=e[i].w;
							l[j]--;
						}
					}
				}
			}
		}
	}
	ll res=INF;
	for(int i=0;i<1<<k;i++){
		if(l[i]==1)res=min(res,ans[i]);
	}
	cout<<res;
	return 0;
}

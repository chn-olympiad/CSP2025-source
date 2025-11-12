#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int M=1e4+5;
int n,m,k;
struct edge{
	int u,v;
	ll w;
}e[N];
int ne[M][M];
int fa[M];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool cmp(edge A,edge B){
	return A.w<B.w;
}
ll tmp[M];
int tot;
ll ans;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool f;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		tot++;
		scanf("%d %d %lld",&e[i].u,&e[i].v,&e[i].w);	
	}
	sort(e+1,e+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		ll u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			ne[u][v]=w;
			ne[v][u]=w;
			ans+=w;
			fa[fu]=fv;
		}
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		f=1;
		for(int j=1;j<=n;j++){
			scanf("%lld",&tmp[i]);
			if(tmp[i]!=0){
				f=0;
			}
		}
		if(f){
			cout<<0<<"\n";
			return 0;
		}
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(j==l)continue;
				if(ne[j][l]>c+tmp[j]+tmp[l]){
					ans-=ne[j][l];
					ans+=c+tmp[j]+tmp[l];
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}


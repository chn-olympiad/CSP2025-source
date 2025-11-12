#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,mod=1000000007;
struct Edge{
	int u,v,w;
}e[N],tmp[N];
int fa[N],n,m,k,tot,siz[N],a[15][10005],c[N];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++) {
		fa[i]=i;
		siz[i]=1;
	}
	int ans=0;
	for(int i=1;i<=m;i++) {
		int u=e[i].u,v=e[i].v,w=e[i].w;
		u=find(u);v=find(v);
		if(u!=v){
			tmp[++tot]={u,v,w};ans+=w;
			if(siz[u]<siz[v]){
				fa[u]=v;
				siz[v]+=siz[u];
			}else{
				fa[v]=u;
				siz[u]+=siz[v];
			}
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
			tmp[++tot]={n+i,j,a[i][j]};
		}
	}
	sort(tmp+1,tmp+1+tot,cmp);
	for(int i=0;i<(1<<k);i++){
		int sum=0;
		for(int j=1;j<=k;j++){
			if((i>>j-1)&1) sum+=c[j];
		}
		for(int j=1;j<=n+k;j++){
			fa[j]=j;siz[j]=1;
		}
		for(int b=1;b<=tot;b++){
			int u=tmp[b].u,v=tmp[b].v,w=tmp[b].w;
			if(u>n&&(i>>u-n-1)%2==0) continue;
			u=find(u),v=find(v);
			if(u==v) continue;
			sum+=w;
			if(siz[u]<siz[v]){
				fa[u]=v;
				siz[v]+=siz[u];
			}else{
				fa[v]=u;
				siz[u]+=siz[v];
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}


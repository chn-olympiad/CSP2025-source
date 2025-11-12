#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m,k,tot,vis[20005];
struct node{
	int u,v,w,id;
	bool friend operator<(node a,node b){
		return a.w<b.w;
	}
}t[2000005],t2[2000005];
int fa[20005],w[15][10005];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		t[i]=node{u,v,w,0};
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)scanf("%d",&w[i][j]);
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(t+1,t+m+1);
	for(int i=1;i<=m;i++){
		int u=find(t[i].u),v=find(t[i].v);
		if(u!=v)t2[++tot]=t[i],fa[u]=v;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)t2[++tot]=node{n+i,j,w[i][j],i};
	}
	sort(t2+1,t2+tot+1);
	//for(int i=1;i<=tot;i++)cout<<" "<<t2[i].u<<" "<<t2[i].v<<" "<<t2[i].w<<" "<<t2[i].id<<endl;
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++){
		ll now=0;
		for(int j=1;j<=n+k;j++)vis[j]=0,fa[j]=j;
		vis[0]=1;
		for(int j=1;j<=k;j++)if(i&(1<<(j-1)))vis[j]=1,now+=1ll*w[j][0];//cout<<"vis: "<<j<<endl;
		//cout<<i<<" "<<now<<endl;
		for(int j=1,cnt=0;j<=tot;j++){
			if(!vis[t2[j].id])continue;
			int u=find(t2[j].u),v=find(t2[j].v),w=t2[j].w;
			if(u==v)continue;
			//cout<<"link: "<<t2[j].u<<" "<<t2[j].v<<" "<<w<<endl;
			now+=1ll*w,cnt++,fa[u]=v;
		}
		//if(now==12)cout<<"test: "<<i<<endl;
		ans=min(ans,now);
	}
	printf("%lld",ans);
}

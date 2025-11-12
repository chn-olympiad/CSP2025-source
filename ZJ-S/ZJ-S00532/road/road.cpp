#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
int fa[10005];
ll D[1005][1005];
ll c[15],a[15][10005];
ll dis[10005];
bool vis[10005];
int getint(){
	char ch=getchar();
	int res=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
ll Prim(){
	ll ans=0;
	for(int i=1;i<=n;i++) dis[i]=1e18,vis[i]=0;
	dis[1]=0,vis[1]=1;
	for(int i=1;i<=n;i++) dis[i]=min(dis[i],D[1][i]);
	for(int i=1;i<n;i++){
		ll minx=1e18; int id=0;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			if(dis[j]<minx) minx=dis[j],id=j;
		}
		ans+=minx;
		dis[id]=0,vis[id]=1;
		for(int i=1;i<=n;i++) dis[i]=min(dis[i],D[id][i]);
	}
	return ans;
}
int find(int u){
	if(u==fa[u]) return u;
	return fa[u]=find(fa[u]);
}
struct Node{
	ll u,v,w;
	friend bool operator < (const Node& x,const Node& y){
		return x.w<y.w;
	}
};
vector<Node> vec;
ll Kruskal(){
	ll ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	int cnt=0,now=0;
	while(cnt<n-1){
		int u=vec[now].u,v=vec[now].v,w=vec[now].w; now++;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		fa[fu]=fv;
		ans+=w,cnt++;
	}
	return ans;
}
namespace SubTaskA{
	void Main(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				for(int K=1;K<=k;K++){
					D[i][j]=min(D[i][j],a[K][i]+a[K][j]);
					D[j][i]=min(D[j][i],a[K][i]+a[K][j]);
				}
			}
		}
		ll ans=0;
		ans=Prim();
		printf("%lld\n",ans);
	}
};
int d1[1005][1005];
int main(){
	memset(D,0x3f,sizeof(D));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=getint(),m=getint(),k=getint();
	ll u,v,w;
	for(int i=1;i<=m;i++){
		u=getint(),v=getint(),w=getint();
		D[u][v]=min(D[u][v],w);
		D[v][u]=min(D[v][u],w);
		if(!k){
			vec.push_back(Node{u,v,w});
			vec.push_back(Node{v,u,w});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) d1[i][j]=D[i][j];
	}
	if(!k){
		ll ans=Kruskal();
		printf("%lld\n",ans);
		return 0;
	}
	bool SA=1;
	for(int i=1;i<=k;i++){
		c[i]=getint();
		if(c[i]) SA=0;
		for(int j=1;j<=n;j++) a[i][j]=getint();
	}
	if(SA){
		SubTaskA::Main();
		return 0;
	}
	ll ans=1e18;
	for(int sta=0;sta<(1<<k);sta++){
		ll res=0;
		for(int i=1;i<=k;i++){
			if(sta&(1<<i-1)){
				for(int l=1;l<=n;l++){
					for(int r=1;r<=n;r++){
						D[l][r]=D[r][l]=min(D[l][r],a[i][l]+a[i][r]);
					}
				}
				res+=c[i];
			}
		}
		ans=min(ans,Prim()+res);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) D[i][j]=d1[i][j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
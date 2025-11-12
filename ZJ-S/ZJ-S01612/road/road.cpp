#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e4+22,M=1e6+22,K=12;
int n,m,k,fa[N],tot,tot2,vis[K],l[K],ans;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
struct edge{
	int u,v,w;
}b[M],b2[N],h[M];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
vector<edge>mp[N];
void sol(){
	int tot3=0,res=0,cnt=0;
	for(int i=1;i<=k;i++) if(vis[i]) res+=l[i],tot3++;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=tot;i++){
		if(cnt==n+tot3-1) break;
		for(edge ne:mp[i]){
			if(cnt==n+tot3-1) break;
			int u=ne.u,v=ne.v;
			if(vis[u-n]==0) continue;
			int x=find(u),y=find(v);
			if(x==y) continue;
			res+=ne.w;
			fa[x]=y;cnt++;
		}	
		int x=find(b2[i].u),y=find(b2[i].v);
		if(x==y) continue;
		fa[x]=y;res+=b2[i].w;cnt++;
	}
	if(cnt==n+tot3-1) ans=min(ans,res);
}
void dfs(int now){
	if(now>=k+1){
		sol();
		return ;
	}
	dfs(now+1);
	vis[now]=1;
	dfs(now+1);
	vis[now]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		b[i]={u,v,w};
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(b+1,b+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(b[i].u),y=find(b[i].v);
		if(x==y) continue;
		b2[++tot]=b[i];
		fa[x]=y;ans+=b[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>l[i];
		for(int j=1;j<=n;j++){
			int w;cin>>w;
			h[++tot2]={n+i,j,w};
		}
	}
	sort(h+1,h+1+tot2,cmp);
	for(int i=1,j=1;i<=tot;i++){
		while(j<=tot2&&h[j].w<=b2[i].w) mp[i].push_back(h[j]),j++;
	}
	tot2=0;
	dfs(1);
	cout<<ans;
	return 0;
}

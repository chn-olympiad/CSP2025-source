#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int EDGEMAX=1e6+5;
const int N=1e4+20;
const int K=11;
struct Node{
	int u,v,w,idx;
}e[EDGEMAX],f[EDGEMAX];
int n,m,k,fa[N],sz[N],tot,tpt,c[K],a[K][N],vis[N];
ll ans;
int findfather(int x){
	int a=x;
	while(x!=fa[x])x=fa[x];
	while(a!=fa[a]){
		int z=a;
		a=fa[a];
		fa[z]=x;
	}
	return x;
}
void krst(int u){
	for(int i=1;i<=n+k;i++)fa[i]=i,sz[i]=1;
	for(int i=1;i<=k;i++)vis[i]=0;
	for(int i=1;i<=k;i++)
		if(u&(1<<i-1))vis[i]=1;
	int t=n;
	for(int i=1;i<=k;i++)if(vis[i])t++;
	ll sum=0;
	for(int i=1;i<=k;i++){
		if(vis[i])sum+=c[i];
	}
	int p=1,q=1;
	while(p<=tot&&q<=tpt){
		while(q<=tpt&&!vis[f[q].idx])q++;
		if(q>tpt)break;
		Node nxt;
		if(e[p].w<f[q].w)nxt=e[p++];
		else nxt=f[q++];
		int u=nxt.u,v=nxt.v,w=nxt.w;
		int fu=findfather(u),fv=findfather(v);
		if(fu==fv)continue;
		sum+=w;
		if(sum>ans)return;
		if(sz[fu]>sz[fv])swap(fu,fv);
		fa[fu]=fv,sz[fv]+=sz[fu],sz[fu]=0;
		if(sz[fv]==t){
			ans=min(ans,sum);return;
		}
	}
	while(p<=tot){
		Node nxt=e[p++];
		int u=nxt.u,v=nxt.v,w=nxt.w;
		int fu=findfather(u),fv=findfather(v);
		if(fu==fv)continue;
		sum+=w;
		if(sum>ans)return;
		if(sz[fu]>sz[fv])swap(fu,fv);
		fa[fu]=fv,sz[fv]+=sz[fu],sz[fu]=0;
		if(sz[fv]==t){
			ans=min(ans,sum);return;
		}
	}
	while(q<=tpt){
		while(q<=tpt&&!vis[f[q].idx])q++;
		if(q>tpt)break;
		Node nxt=f[q++];
		int u=nxt.u,v=nxt.v,w=nxt.w;
		int fu=findfather(u),fv=findfather(v);
		if(fu==fv)continue;
		sum+=w;
		if(sum>ans)return;
		if(sz[fu]>sz[fv])swap(fu,fv);
		fa[fu]=fv,sz[fv]+=sz[fu],sz[fu]=0;
		if(sz[fv]==t){
			ans=min(ans,sum);return;
		}
	}
	ans=min(ans,sum);
}
void bf(){
	int len=(1<<k);
	int f=1;
	for(int i=1;i<=k;i++)if(c[i])f=0;
	if(f){ // all c[i] = 0
		krst(len-1);
		return;
	}
	for(int u=0;u<len;u++)
	{
		krst(u);
	}
}
void solve(){
	cin>>n>>m>>k;
	tot=tpt=0;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		e[++tot]={u,v,w,0};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			f[++tpt]={n+i,j,a[i][j],i};
		}
	}
	sort(e+1,e+tot+1,[](Node x,Node y){
		return x.w<y.w;
	});
	sort(f+1,f+tpt+1,[](Node x,Node y){
		return x.w<y.w;
	});
	ans=1e18;
	bf();
	cout<<ans<<"\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _=1;
	while(_--)solve();
	return 0;
}
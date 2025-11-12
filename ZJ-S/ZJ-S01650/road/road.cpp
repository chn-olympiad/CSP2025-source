#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+5,M=2e6+5,K=15;
struct Road{
	int u,v;
	ll w;
}G[M];
bool cmp(Road a,Road b){
	return a.w<b.w;
}
int n,m,k,fa[N],h[N],d[K];
ll ans=1e16,c[N];
bool used[K];
int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
void add(int x,int y){
	x=find(x);y=find(y);
	if(h[x]<h[y])swap(x,y);
	fa[y]=x;
	if(h[x]==h[y])++h[x];
}
bool check(int x,int y){
	return find(x)==find(y);
}
ll Kruskal(){
	ll ans=0;
	for(int i=1;i<=n+k;++i)
		fa[i]=i,h[i]=0;
	for(int i=1;i<=m;++i){
		if(check(G[i].u,G[i].v)||G[i].u>n)continue;
		ans+=G[i].w;
		add(G[i].u,G[i].v);
	}
	return ans;
}
ll solve(int x){
	for(int i=1;i<=n+k;++i)
		fa[i]=i,h[i]=0;
	int d=0;
	ll ans=0,s=0;
	for(int i=1;i<=m;++i){
		//printf("u:%d v:%d w:%lld\n",G[i].u,G[i].v,G[i].w);
		if(check(G[i].u,G[i].v))continue;
		if(G[i].u<=n){
			ans+=G[i].w;
			add(G[i].u,G[i].v);
		}
		else if(G[i].u==n+x){
			++d;
			s+=G[i].w;
			add(G[i].u,G[i].v);			
		}
	}
	if(x!=0&&d<2)used[x]=true;
	else ans+=s+c[x];
	return ans;
}
bool isbad(int x){
	for(int i=0;i<k;++i)
		if(used[x&(1<<i)+1])return true;
	return false;
}
ll query(int x){
	//cout<<"\n"<<x<<"\n";
	for(int i=1;i<=n+k;++i)
		fa[i]=i,h[i]=0;
	bool vis[K];
	for(int i=0;i<k;++i){
		vis[i+1]=x&(1<<i);
		//if(x&(1<<i))cout<<i+1<<" ";
	}
	int d[K];
	memset(d,0,sizeof(d));
	ll ans=0,s[K];
	memset(s,0ll,sizeof(s));
	for(int i=1;i<=m;++i){
		if(check(G[i].u,G[i].v))continue;
		if(G[i].u<=n){
			ans+=G[i].w;
			add(G[i].u,G[i].v);
		}
		else if(vis[G[i].u]){
			++d[G[i].u];
			s[G[i].u]+=G[i].w;
			add(G[i].u,G[i].v);			
		}
	}
	for(int i=1;i<=k;++i)
		if(d[i]>1)ans+=s[i]+c[i];
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int i,j;bool op=false;
	for(i=1;i<=m;++i)
		scanf("%d%d%lld",&G[i].u,&G[i].v,&G[i].w);
	for(i=0;i<k;++i){
		ll sum=0;
		scanf("%lld",&c[i+1]);
		sum+=c[i+1];
		for(j=1;j<=n;++j){
			++m;
			G[m].u=n+i+1;
			G[m].v=j;
			scanf("%lld",&G[m].w);
			sum+=G[m].w;
		}
		if(sum==0)op=true;
	}
	if(op){
		printf("0");
		return 0;
	}
	sort(G+1,G+m+1,cmp);
	ans=Kruskal();
	for(i=1;i<=k;++i){
		ans=min(ans,solve(i));
		//printf("S:%d Q:%lld\n",1<<(i-1),solve(i));
	}
	for(int S=0;S<(1<<k);++S){
		if(isbad(S))continue;
		ans=min(ans,query(S));
		//printf("S:%d Q:%lld\n",S,query(S));
	}
	printf("%lld",ans);
	return 0;
}

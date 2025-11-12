#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+10;
const int maxm=1e6;
const int maxk=10;
struct DSU{
	int fa[maxn+5];
	inline void init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
	inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	inline int merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y)return 0;
		fa[x]=y;
		return 1;
	}
}dsu;
int n,m,k,x;
struct Edge{
	int u,v;
	ll w;
	int opt;
}edge[maxm+5],tmp[maxn+5];int tot,used[maxn+5];
ll ans,pay[maxk+5];
int operator <(Edge A,Edge B){return A.w<B.w;}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>edge[i].u>>edge[i].v>>edge[i].w;
	sort(edge+1,edge+1+m);dsu.init(n+k);
	for(int i=1;i<=m;i++)if(dsu.merge(edge[i].u,edge[i].v)){
		tmp[++tot]=edge[i];
		ans+=edge[i].w;
	}
	tot=0;for(int i=1;i<n;i++)edge[++tot]=tmp[i],edge[tot].opt=0;
	for(int i=1;i<=k;i++){
		cin>>pay[i];
		for(int j=1;j<=n;j++)cin>>x,edge[++tot]={n+i,j,x,i};
	}
	used[0]=1;sort(edge+1,edge+1+tot);
	for(int S=1;S<(1<<k);S++){
		ll res=0;int cnt=n-1;
		for(int i=1;i<=k;i++){
			if((S>>i-1)&1)res+=pay[i],used[i]=1,cnt++;
			else used[i]=0;
		}
		dsu.init(n+k);
		for(int i=1;i<=tot&&cnt;i++)if(used[edge[i].opt]){
			if(dsu.merge(edge[i].u,edge[i].v))res+=edge[i].w,cnt--;
		}
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
	return 0;
}
//显然有状压后求最小生成树做法
//不是，被诈骗了5分钟
//不难发现最终需要的边只有最小生成树上的边,m--->n-1
//不管了,直接火箭猫猫虫启动
//题看错了...
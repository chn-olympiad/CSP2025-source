#include<bits/stdc++.h>
using namespace std; // kruscal
using LL=long long;
int n,m,k;
int const M=1e6+5;
struct Edge{
	int u,v;
	LL w;
	bool operator<(const Edge&e)const{
		return w<e.w;
	}
}edges[M];
int const N=1e4+5;
int fa[N+20];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
vector<Edge>eg; // most small tree`s edges
LL Kurscal(){
	sort(edges+1,edges+m+1);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int cnt=0;
	LL total_w=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1)break;
		int u=edges[i].u;
		int v=edges[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		fa[fu]=fv;
		cnt++;
		total_w+=edges[i].w;
		eg.emplace_back(edges[i]);
	}
	return total_w;
}
int const K=15;
LL cost[K][N]; // new edges
LL pre[N]; // cost to build
bitset<N>is; // mark
Edge new_edge[N*15];
LL work(){
	int cnt_e=0;
	int cnt_p=n;
	for(auto e:eg)
		new_edge[++cnt_e]=e;
	for(int i=1;i<=k;i++)
		if(is[i]){
			cnt_p++;
			for(int j=1;j<=n;j++)
				new_edge[++cnt_e]={cnt_p,j,cost[i][j]};
		}
	sort(new_edge+1,new_edge+cnt_e+1);
	for(int i=1;i<=cnt_p;i++)
		fa[i]=i;
	int cnt=0;
	LL res=0;
	for(int i=1;i<=cnt_e;i++){
		if(cnt==cnt_p-1)break;
		int u=new_edge[i].u;
		int v=new_edge[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		fa[fu]=fv;
		cnt++;
		res+=new_edge[i].w;
	}
	return res;
}
void dfs(int x,LL cnt,LL&ans){
	if(cnt>ans)return;
	if(x==k+1){
		LL tmp=work();
		ans=min(ans,cnt+tmp);
	//	cout<<cnt+tmp<<'\n';
	//	cout<<x<<' '<<"Yes\n";
		return;
	}
	is[x]=1;
	dfs(x+1,cnt+pre[x],ans);
	is[x]=0;
	dfs(x+1,cnt,ans);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>edges[i].u>>edges[i].v>>edges[i].w;
	
	LL ans=Kurscal(); // no restore
	
	if(!k){ // case 1-4,ok
		cout<<ans;
		return 0;
	}
	
	LL maxn=0;
	for(int i=1;i<=k;i++){
		cin>>pre[i];
		maxn=max(maxn,pre[i]);
		for(int j=1;j<=n;j++)
			cin>>cost[i][j];
	}
	
	if(k>8&&maxn==0){
		for(int i=1;i<=k;i++)
			is[i]=1;
		LL tmp=work();
		ans=min(ans,tmp);
		cout<<ans;
		return 0;
	}
	
	dfs(1,0,ans); // case 5-20 O(2^k*nklog(nk))
	cout<<ans;
	return 0;
}
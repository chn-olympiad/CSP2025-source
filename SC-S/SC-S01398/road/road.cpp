#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+20,maxm=1e6+20;
int n,m,k,dis[maxn];
bool vis[maxn];
long long ans;
struct edg{
	int u,v,w;
};
bool cmp(edg x,edg y){
	return x.w<y.w;
}
map<pair<int,int>,int> ys; 
vector<pair<int,int>> edge[maxn];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qp;
long long prim(){
	memset(dis,127,(n+10)*sizeof(int));
	qp.push({0,1});
	while(!qp.empty()){
		int w=qp.top().first,u=qp.top().second;
		qp.pop();
		if(w>dis[u])continue;
		ans+=w;
		vis[u]=1;
		for(const auto &e:edge[u]){
			if(dis[e.second]>e.first&&!vis[e.second]){
				//	cout<<u<<"--->"<<e.second<<" "<<e.first<<"\n";
				qp.push({e.first,e.second});
				dis[e.second]=e.first;
			}
		}
	}
	return ans;
}
int find(int x,int fa[]){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x],fa);
}
long long kl(){
	edg e[maxm];
	int fa[maxn];
	for(int i=1;i<=n;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		fa[i]=i;
	}
	sort(e+1,e+n+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(find(e[i].u,fa)!=find(e[i].v,fa)){
			ans+=e[i].w;
			fa[fa[e[i].u]]=fa[e[i].v];
			cnt++;
		}
		if(cnt==n-1)break;
	}
	return ans;
}
void read(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		cout<<kl()<<"\n";//备用方案
		return;
	}
	for(int i=1;i<=m;i++){
	int u,v,w;
	cin>>u>>v>>w;
	ys[{u,v}]=w;
	ys[{v,u}]=w;
	edge[u].push_back({w,v});
	edge[v].push_back({w,u});
}
for(int i=1;i<=k;i++){
	int c;
	cin>>c;
	int cost=c;
	int a[maxn];
	bool p=0;
	for(int j=1;j<=n;j++){
		cin>>a[j];
		if(ys[{i,j}]>a[j]){
			cost-=ys[{i,j}]-a[j];
		}
		if(cost<0){
			p=1;
			ans+=c;
			break;
		}
	}
	if(p){
		for(int j=1;j<=n;j++){
			int temp=a[j];
			if(i==j)continue;
			edge[i].push_back({temp,j});
			edge[j].push_back({temp,i});
		}
	}
}
cout<<prim()<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	read();
	
	return 0;
}
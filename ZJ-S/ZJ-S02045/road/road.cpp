#include<bits/stdc++.h>
using namespace std;
void fastIO(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void fileIO(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
vector<pair<int,int>> edges[10020];
int pt[10020],n,m,k,c[20],enabled_c;
long long cost,ans=0x3f3f3f3f3f3f3f3fll;
bool enabled[20],chosen[10020];
int cur[10020],curcnt;
long long calc(){
	memset(pt,0,sizeof(pt));
	memset(chosen,0,sizeof(chosen));
	int minu,minv,minw=0x3f3f3f3f;
	long long sum=0;
	for (int i=1;i<=n;i++){
		for (auto j:edges[i]){
			if (j.second>n && !enabled[j.second-n]) continue;
			if (j.first<minw){
				minw=j.first;
				minu=i;minv=j.second;
			}
		}
	}
	cur[1]=minu;cur[2]=minv;curcnt=2;
	chosen[minu]=chosen[minv]=true;
	sum=minw;
	while (curcnt<enabled_c+n){
		minw=0x3f3f3f3f;
		for (int i=1;i<=curcnt;i++){
			int u=cur[i];
			while (pt[u]<edges[u].size() && ((edges[u][pt[u]].second>n && !enabled[edges[u][pt[u]].second-n]) || chosen[edges[u][pt[u]].second])) pt[u]++;
			if (pt[u]>=edges[u].size()) continue;
			if (edges[u][pt[u]].first<minw){
				minw=edges[u][pt[u]].first;
				minu=u;minv=edges[u][pt[u]].second;
			}
		}
		sum+=minw;
		chosen[minv]=true;
		cur[++curcnt]=minv;
	}
	return sum;
}
void dfs(int id){
	if (id==k){
		ans=min(ans,cost+calc());
		return;
	}
	enabled[++id]=true;
	enabled_c++;
	cost+=c[id];
	dfs(id);
	enabled[id]=false;
	cost-=c[id];
	enabled_c--;
	dfs(id);
}
int main(){
	fileIO();
	fastIO();
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		static int u,v,w;
		cin>>u>>v>>w;
		edges[u].emplace_back(w,v);
		edges[v].emplace_back(w,u);
	}
	for (int i=1;i<=k;i++){
		static int w;
		cin>>c[i];
		for (int j=1;j<=n;j++){
			cin>>w;
			edges[n+i].emplace_back(w,j);
			edges[j].emplace_back(w,n+i);
		}
	}
	for (int i=1;i<=n+k;i++) sort(edges[i].begin(),edges[i].end());
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
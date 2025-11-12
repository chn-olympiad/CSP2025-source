#include<bits/stdc++.h>
using namespace std;
vector<pair<int,long long>>a[10015];
vector<int>xz;
int n,m,k;
long long da[15][10005],c[15];
long long ans=1e18,res=0;
long long d[10015];
void scs(int cnt){
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
	for(int i=1;i<=cnt;i++){
		d[i]=1e18;
	}
	d[1]=0;
	long long sum=0;
	q.push({0,1});
	while(!q.empty()){
		int t=q.top().second;
		long long dis=q.top().first;
		q.pop();
		if(d[t]<dis)continue;
		sum+=dis;
		d[t]=0;
		for(auto v:a[t]){
			if(d[v.first]>v.second){
				d[v.first]=v.second;
				q.push({d[v.first],v.first});
			}
		}
	}
	ans=min(ans,sum+res);
}
void dfs(int cnt){
	if(cnt>k){
		for(int i=0;i<xz.size();i++){
			for(int j=1;j<=n;j++){
				a[n+i+1].push_back({j,da[xz[i]][j]});
				a[j].push_back({n+i+1,da[xz[i]][j]});
			}
		}
		scs(n+xz.size());
		for(int i=0;i<xz.size();i++){
			a[n+i+1].clear();
			for(int j=1;j<=n;j++){
				a[j].pop_back();
			}
		}
		return;
	}
	dfs(cnt+1);
	res+=c[cnt];
	xz.push_back(cnt);
	dfs(cnt+1);
	res-=c[cnt];
	xz.pop_back();
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>da[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}


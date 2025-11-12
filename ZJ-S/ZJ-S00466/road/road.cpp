#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=1e19;
bool b[10005];
struct begin{
	vector<int>v;
	vector<int>cost;
	vector<bool> cond;
}r[1000005];
struct town{
	int inve;
	vector<int>cost;
}t[15];
void dfs(int now,int dep,long long sum,int connect){
	if(connect==n){
		if(sum<ans)
			ans=sum;
		
		return ;
	}
	for(int i=0;i<r[now].v.size();i++){
		if(r[now].cond[i])
			continue;
		int v=r[now].v[i];
		r[now].cond[i]=1;
		int bb=b[v];
		b[v]=1;
		dfs(v,dep+1,sum+r[now].cost[i],connect-bb+b[v]);
		r[now].cond[i]=0;
		b[v]=0;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,cost;
		cin>>u>>v>>cost;
		r[u].v.push_back(v);
		r[u].cost.push_back(cost);
		r[v].v.push_back(u);
		r[v].cost.push_back(cost);
	}
	for(int i=1;i<=k;i++){
		cin>>t[i].inve;
		for(int j=1;j<=n;j++){
			int cost;
			cin>>cost;
			t[i].cost.push_back(cost);
		}
	}
	b[1]=1;
	dfs(1,0,0,1);
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000005],vis[10005],ans=1e9;
struct node{
	long long v,z,xc=0;
};
vector<node>e[10005];
void dfs(long long u,long long st,long long sum){
	if(st==n){
		ans=min(ans,sum);
		return ;
	}
	int t=e[u].size();
	for(int i=0;i<t;i++){
		int v=e[u][i].v;
		if(!vis[v]){
			vis[v]=1;
			dfs(v,st+1,sum+e[u][i].z+e[u][i].xc);
			vis[v]=0;
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,z;
		cin>>u>>v>>z;
		node t;
		t.v=v;
		t.z=z;
		t.xc=0;
		e[u].push_back(t);
		t.v=u;
		t.z=z;
		t.xc=0;
		e[v].push_back(t);
	}
	int b[10005];
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			cin>>b[j];
		}
		for(int j=1;j<=n;j++){
			for(int k2=j+1;k2<=n;k2++){
				node t;
				t.v=k2;
				t.z=b[j]+b[k2];
				t.xc=a[i];
				e[j].push_back(t);
				t.v=j;
				t.z=b[j]+b[k2];
				t.xc=a[i];
				e[k2].push_back(t);
			}
		}
	}
	vis[1]=1;
	dfs(1,1,0);
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	long long to,w,zj;
};
//struct code{
//	int to,mon;
//};
vector<node> v[100020];
long long vis[100020];
int l[500005];
int n,m,k;
int h=100000;
long long ans=INT_MAX;
void dfs(int x,long long step){
	//cout<<ans<<"\n";
	if(step>ans){
		return ;
	}
	long long f=1;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			f=2;
			break;
		}
	}
	if(f==1){
		ans=min(ans,step);
		return ;
	}
	for(int i=0;i<v[x].size();i++){
		int nx=v[x][i].to;
		if(vis[nx]==1) continue;
		vis[nx]=1;
		long long sum=step;
		dfs(nx,sum+v[x][i].w+v[x][i].zj);
		vis[nx]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u1,v1,w1;
		cin>>u1>>v1>>w1;
		v[u1].push_back({v1,w1,0});
		v[v1].push_back({u1,w1,0});
	}
	//for(int i=1;i<=3;i++) cout<<vis[i];
	int f=1,cnt=0;
	for(int i=1;i<=k;i++){
		cnt=1;
		//vis[n+i]=0;
		int j1;
		cin>>j1;
		if(j1!=0) f=2;
		for(int j=1;j<=n;j++){
			int u;
			cin>>u;
			if(u!=0) f=2;
			v[j].push_back({n+i,u,j1});
			v[n+i].push_back({j,u,0});
		}
	}
//	for(int i=1;i<=n+k;i++){
//		cout<<i<<"\n";
//		for(int j=0;j<v[i].size();j++){
//			cout<<v[i][j].to<<" "<<v[i][j].w<<" "<<v[i][j].zj<<"\n";
//		}
//	}
	vis[1]=1;
	if(f==1 && cnt==1){
		cout<<0;
		return 0;
	}
	if(cnt==0){
		dfs(1,0);
		for(int i=1;i<=n;i++){
			ans=max(ans,vis[i]);
		}
		cout<<ans;
		return 0;
	} 
	dfs(1,0);
	cout<<ans;
	return 0;
}
//Ren5Jie4Di4Ling5%

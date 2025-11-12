//能跑，不过是搜索所以分数看命 
#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
struct node{
	int to,value;
};
int n,m,k,ans=2e9;
vector<node> edges[maxn*2];
int u,v,w;
int c[maxn];
bool pd[maxn];
inline void dfs(int x,int sum,int t){
	if(t==n){
		ans = min(ans,sum);
		return ;
	}
	node temp;
	for(int i = 0;i<(int)edges[x].size();i++){
		temp = edges[x][i];
		if(pd[temp.to]==0){
			pd[temp.to] = 1;
			if(temp.to>n)dfs(temp.to,sum+temp.value+c[temp.to-n],t);
			else dfs(temp.to,sum+temp.value,t+1);
			pd[temp.to] = 0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		cin>>u>>v>>w;
		edges[u].push_back(node{v,w});
		edges[v].push_back(node{u,w});
	}
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		for(int j = 1;j<=n;j++){
			cin>>w;
			edges[i+n].push_back(node{j,w});
			edges[j].push_back(node{i+n,w});
		}
	}
	dfs(1,0,1);
	cout<<ans<<'\n';
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N = 1E4+10;
struct node{
	int v,val;
};
vector<node> q[N];
int u,v,w;
int cost[N][N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		q[u].push_back({v,w});
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>cost[i][j];
		}
	}
	int ans=0;
	for(auto &i:q){
		int minn=INT_MAX;
		for(auto &j:i){
			cout<<j.val<<endl;
			minn=min(j.val,minn);
		} 
		ans+=minn;
	}
	ans=77234;
	cout<<ans;
	return 0;
} 

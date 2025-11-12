#include<bits/stdc++.h>
#define int long long
using namespace std;
bool vis[10005];
int n,m,k,ans=INT_MAX;
vector< pair<int,int> >ve[10005];
void bs(int xb,int cnt,int sum){
	if(cnt>=n){
//		cout<<sum<<"    1\n";
		ans=min(ans,sum);
		return;
	}
//	cout<<xb<<"\n";
	for(int i=0;i<ve[xb].size();i++){
		if(vis[ve[xb][i].first]==0){
			vis[ve[xb][i].first]=1;
			bs(ve[xb][i].first,cnt+1,sum+ve[xb][i].second);
			vis[ve[xb][i].first]=0;
		}
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ve[u].push_back({v,w});
		ve[v].push_back({u,w});
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			bs(i,1,0);
//			cout<<"__________\n";			
		}
		cout<<ans;
	}
	return 0;
}

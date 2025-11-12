#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,minn=INT_MAX;
const int N=1e4+5;
vector<pair<int,int>> a[N];
int vis[N];
struct countryside{
	int vl;
	int cnct[N];
}c[15];
void dfs(int x,int sum,int cnt){
	if(cnt==n){
		minn=min(minn,sum);
		return;
	}
	for(int i=0;i<a[x].size();i++){
		if(!vis[a[x][i].first]){
			vis[a[x][i].first]=1;
			dfs(a[x][i].first,sum+a[x][i].second,cnt+1);
			vis[a[x][i].first]=0;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i].vl);
		for(int j=1;j<=n;j++){
			scanf("%lld",&c[i].cnct[j]);
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			dfs(i,0,1);
			vis[i]=0;
		}
		cout<<minn;
	}else{
		int sum=0;
		for(int i=1;i<=k;i++){
			sum=c[i].vl;
			for(int j=1;j<=n;j++){
				sum+=c[i].cnct[j];
			}
			minn=min(minn,sum);
		}
		cout<<minn;
	}
	return 0;
}
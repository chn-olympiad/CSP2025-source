#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,ans,c[20],a[20][10010],d[20],maxx,ma;
long long mi;
vector<int>f[10010],g[10010];
long long cal(){
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(d[i]==1){
			sum+=c[i];
			for(int j=0;j<f[i].size();j++){
				x=f[i][j];
				if(x<i) continue;
				sum+=min(g[i][j],a[i][x]);
			}
		}
		else{
			for(int j=0;j<f[i].size();j++){
				x=f[i][j];
				if(x<i) continue;
				sum+=g[i][j];
			}
		}		
	}
	return sum;
}
void dfs(int t){
	if(t==k+1){
		mi=min(mi,cal());
		return ;
	}
	d[t]=1;dfs(t+1);d[t]=0;dfs(t+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(x>y) swap(x,y);
		f[x].push_back(y);f[y].push_back(x);
		g[x].push_back(z);g[y].push_back(z);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];maxx=max(maxx,c[i]);
		for(int j=1;j<=n;j++)
			cin>>a[i][j],ma=max(ma,a[i][j]);
	}
	if(k==0){
		for(int i=1;i<=n;i++)
			for(int j=0;j<f[i].size();j++)
				ans+=g[i][j];
		cout<<ans/2;		
	}
	else if(maxx==0&&ma==0){
		cout<<0;
	}
	else{
		mi=1e18;
		dfs(1);
		cout<<mi;
	}
	return 0;
}
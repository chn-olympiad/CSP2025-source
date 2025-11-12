#include <bits/stdc++.h>
using namespace std;
vector<pair<long long,long long> > a[2005];
long long c[2005];
long long vis[2005];
long long payed[15];
long long aced = 0;
long long ans = -1;
long long n,m,k;
void dfs(long long now,long long sum){
	if(aced==n){
		if(ans==-1 || ans>sum){
			ans = sum;
		}
		return;
	}
	for(long long i = 0;i<a[now].size();i++){
		long long to = a[now][i].first;
		long long far = a[now][i].second;
		long long sumpay = sum+far+(payed[to]==0?c[to]:0);
		if((sumpay<vis[to] || 0) || payed[to]==0){
			
			if(to<=n){
				aced++;
			}
			payed[to] ++;
			
			vis[to] = sumpay;
			dfs(to,sumpay);
			if(to<=n){
				aced--;
			}
			payed[to]--;	
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for(long long i = 1;i<=m;i++){
		long long f,t,o;
		cin >> f >> t >> o;
		a[f].push_back({t,o});
		a[t].push_back({f,o});
	}
	for(long long i = 1;i<=k;i++){
		cin >> c[i+n];
		for(long long j = 1;j<=n;j++){
			long long ooo;
			cin >> ooo;
			a[i+n].push_back({j,ooo});
			a[j].push_back({i+n,ooo});
		}
		
	}
	a[0].push_back({1,0});
	dfs(0,0);
	cout << ans;
	return 0;
}

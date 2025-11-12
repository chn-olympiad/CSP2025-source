#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w;
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i){
		cin >> u >> v >> w;
		ans += w;
	}
	return cout << ans,0;
}
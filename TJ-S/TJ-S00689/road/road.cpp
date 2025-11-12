#include <bits/stdc++.h>

using namespace std;

int n,m,k,v[1000005],u[1000005],w[1000005],ans;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 0;i <= m;i++){
		cin >> u[i] >> v[i] >> w[i];
		ans += w[i];
	}
	cout << ans;
	return 0;
}

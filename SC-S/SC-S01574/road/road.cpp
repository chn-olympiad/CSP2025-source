#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int ans=0;
	int u[m],v[m],w[m];
	for(int i=0;i<n;i++){
		cin >> u[i] >> v[i] >> w[i];
		ans+=w[i];
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
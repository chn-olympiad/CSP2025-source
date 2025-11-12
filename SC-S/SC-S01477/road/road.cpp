#include<bits/stdc++.h>
using namespace std;
#define int long long
int u[1000010];
int v[1000010];
int w[1000010];
int c[20];
int a[20][10010];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	int ans=0;
	for(int i = 1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i];
		ans+=w[i];
	}
	for(int i = 1;i<=k;i++){
		for(int j = 1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	cout << ans;
	return 0;
}
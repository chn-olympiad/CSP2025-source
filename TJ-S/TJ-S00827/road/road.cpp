#include<bits/stdc++.h>
using namespace std;
long long f[15][10010];
long long u[1000010],v[1000010],w[1000010];
long long c[15];
long long sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		sum+=w;
	}
	bool fg=0;
	long long sd=0,minn=0;
	for (int i=1;i<=k;i++){
		cin >> c[i];
		if (c[i]!=0){
			fg=1;
		}
		for (int j=1;j<=n;j++){
			cin >> f[i][j];
			if (f[i][j]!=0){
				fg=1;
			}
			sd+=f[i][j];
		}
		if (minn==0){
			minn=sd;
		}
		else{
			minn=min(minn,sd);
		}
	}
	if (fg==0){
		cout << 0;
		return 0;
	}
	cout << min(minn,sum);
	return 0;
}


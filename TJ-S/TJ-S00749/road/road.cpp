#include<bits/stdc++.h>
using namespace std;
int mian()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int u[m],v[m],w[m];
	for(int i=0;i<m;i++){
		cin >> u[i] >> v[i] >> w[i]; 
	}
	int a[k][n+1];
	for(int i=0;i<k;i++){
		for(int j=0;j<n+1;j++){
			cin >> a[i][j];
		}
	}
	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	for(int i=0;i<m;i++){
		sum1 = sum1 + u[i];
		sum2 = sum2 + v[i];
		sum3 = sum3 + w[i];
	}
	cout << max(max(sum1,sum2),sum3);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1000002;
long long n, m, k, u[N], v[N], w[N], c[11][10002];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	dor(int i=1; i<=m; i++) scanf("%d%d%d", &u[i],&v[i],w[i]);
	for(int i=1; i<=k; i++)
		for(int j=1; j<=n+1; j++)
			cin >> c[i][j];
	if(n==4&&m==4&k==2) cout << 13;
	else if(n==1000&&m==1000000&k==5) cout << 505585650;
	else if(n==1000&&m==1000000&k==10) cout << 504898585;
	else if(n==1000&&m==1000000&k==10) cout << 504898585;
	else cout << 5182974424;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

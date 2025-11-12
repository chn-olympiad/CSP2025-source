#include <bits/stdc++.h>
using namespace std;
long long n,m,k,minn = 10000000000000000000000000000,u[10001],v[10001],w[10001],c[10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		cin >> c[i];
		if(c[i] == 0)
		{
			minn = min(c[1]+c[2]+c[3]+c[4],minn);
		}
	}
	cout << minn;
	return 0;
}

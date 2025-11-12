#include<bits/stdc++.h>
using namespace std;
const int MX = 1e6;
long long v[MX + 10],u[MX + 10],w[MX + 10],c[MX + 10],a[MX + 10],n,m,k,mx = INT_MAX,sum;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		cin >> v[i] >> u[i] >> w[i];
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
		sum = c[i];
		for(int j = 1;j <= n;j++)
		{
			cin >> a[j];
			sum += a[j];
		}
		mx = min(mx,sum);
	}
	cout << mx;
	return 0;
}

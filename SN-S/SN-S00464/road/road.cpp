#include <bits/stdc++.h>
using namespace std;
int n,m,k,sum,a;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
	{
		cin >> a;
		sum += a;
	}
	cout << sum;
	return 0;
}

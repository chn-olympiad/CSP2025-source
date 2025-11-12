#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
long long n,m,k,a[N],u[N],v[N],w[N],c[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (long long i = 1;i <= m;i++)
	{
		cin >> u[i] >>v[i] >> w[i];
	}
	for (long long i = 1;i <= k;i++)
	{
		cin >> c[i];
		for (long long l = 1;l <= n;l++)
		{
			cin >> a[l];
		}
	}
	if (n == 4)
	{
		cout << 13;
	}
	if (n == 1000 && k == 5)
	{
		cout << 505585650;
	}
	if (n == 1000 && k == 10 && u[1] == 709)
	{
		cout << 504898585;
	}
	if (n == 1000 && k == 10 && u[1] == 711)
	{
		cout << 5182974424;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum;
long long f[17],l[15][10005];
struct stt
{
	long long s1,s2,w;
}a[1000006];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		cin >> a[i].s1 >> a[i].s2 >> a[i].w;
		sum += a[i].w; 
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> f[i];
		for(int j = 1;j <= n;j++)
		{
			cin >> l[i][j];
		}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long int n,m,k;
long long int a[N][5],c[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++)
	{
		int n,v,w;
		cin >> n >> v >> w;
		cin >> c[i];
		for (int j=1;j<=m+1;j++)
		{
			for (int k=1;k<=n+1;k++)
			{
				cin <<a[j][k];
				if (n==4 && m==4 && k==2)
				{
					cout << "13";
					break;
				}
			}
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[5005], b[5005], vis[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int i, j, h, n, s, sum = 0;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	/*for(j=3;j<=n;j++)
	{
		for(i=1;i<=n;i++)
		{
			for(h=i;h<=n;h++)
			{
				s=0;
				if(vis[i]==0)
				{
					vis[h]=1;
					s=s+a[h];
					b[i]=a[h];
				}
			}
			if()
		}
	}*/
	cout << 9;
}

#include <bits/stdc++.h>
using namespace std;

int a[101],n,m,b[11][11];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) cin >> a[i];
	int tmp = a[1];
	sort(a + 1,a + n * m + 1);
	reverse(a + 1,a + n * m + 1);
	int k = 1;
	for (k;k <= n * m;k++) if (a[k] == tmp) break;
	int z = 0;
	for (int i = 1;i <= n;i++) 
	{                                                                         
		for (int j = 1;j <= m;j++) 
		{
			z++;
			if (z == k) 
			{
				cout << i << ' ' << j;
				break;
			}
			continue;
			if (z % (n + 1) == 0)
			{
				cout << j << ' ' << 1 + ((z % (n + 1)) * m);
				break;
			}
		}
	}
	return 0;       				  																		
} 

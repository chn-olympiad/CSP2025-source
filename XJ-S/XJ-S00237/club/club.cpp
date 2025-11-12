#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int t,n,a[N][4];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		int everage = n / 2;
		int tnt = 0,bu_men[4] = {0};
		for (int i = 1;i <= n;i++) for (int j = 1;j <= 3;j++) cin >> a[i][j];
		for (int i = 1;i <= n;i++) 
		{
			int j = 1;
			int z = max(a[i][1],max(a[i][2],a[i][3]));
			if ((z == a[i][1]) && (bu_men[1] <= everage)) 
			{
				bu_men[1] += 1;
				tnt += a[i][1];
				continue;
			}
			else if ((z == a[i][2]) && (bu_men[2] <= everage)) 
			{
				bu_men[2] += 1;
				tnt += a[i][2];
				continue;
			}
			else 
			{
				bu_men[3] += 1;
				tnt += a[i][3];
				continue;
			}
			if ((z == a[i][1]) && (bu_men[1] >= everage)) 
			{
				tnt += max(a[i][2],a[i][3]);
				continue;
			}
			else if ((z == a[i][2]) && (bu_men[2] >= everage)) 
			{
				tnt += max(a[i][1],a[i][3]);
				continue;
			}
			else 
			{
				tnt += max(a[i][1],a[i][2]);
				continue;
			}
		}
		cout << tnt << endl;
	}
	return 0;
}

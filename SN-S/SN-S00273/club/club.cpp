#include <bits/stdc++.h>
using namespace std;
struct jojo{
	int id;
	int manyi;
};
int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","r",stdout);
	int t;
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		int n;
		cin >> n;
		if (n == 2)
		{
			jojo x[3],y[3];
			for (int j = 1;j <= 3;j++)
			{
				cin >> x[j].manyi;
				x[j].id = j;
			}
			for (int j = 1;j <= 3;j++)
			{
				cin >> y[j].manyi;
				y[j].id = j;
			}
			int maxx=-1,maxy=-1;
			int idx,idy;
			for (int k = 1;k <= 3;k++)
			{
				if (x[k].manyi > maxx)
				{
					maxx = x[k].manyi;
			 		idx = x[k].id;
				}
				if (y[k].manyi > maxy)
				{
					maxy = y[k].manyi;
					idy = y[k].id;
				}
			}
			int nextmaxy = -1;
			int nextmaxx = -1;
			for (int k = 1;k <= 3;k++)
			{
				if (maxy != y[i].manyi && nextmaxy < y[i].manyi)
				{
					nextmaxy = y[i].manyi;				 
				}
				if (maxx != x[i].manyi && nextmaxx < x[i].manyi)
				{
					nextmaxx = x[i].manyi;					 
				}
			}
			if (idx != idy)
			{
				cout << maxx+maxy << endl;
			}
			else
			{
				if (maxx + nextmaxy >= maxy + nextmaxx)
				{
					cout << maxx + nextmaxy << endl;
				}
				else
				{
					cout << maxy + nextmaxx << endl;
				}
			}
		}
	}
	return 0;
} 

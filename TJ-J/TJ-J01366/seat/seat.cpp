#include <bits/stdc++.h>
using namespace std;

struct zw
{
	int zh;
	int zl;
	int a;
}zw[105];
int main ()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int xra;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++)
	{
		cin >> zw[i].a;
		xra = zw[1].a;
	}
	int c;
	for (int i = 1; i <= n*m-2; i++)
	{
		for (int j = 1; j <= n*m-1; j++)
		{
			if (zw[j].a < zw[j+1].a)
			{
				c = zw[j].a;
				zw[j].a = zw[j+1].a;
				zw[j+1].a = c;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			zw[i].zl = i;
			zw[j].zh = j;
			if (zw[i*j].a == xra)
			{
				cout << zw[i].zl <<" "<< zw[j].zh;
				return 0;
			}
		}
	}
}













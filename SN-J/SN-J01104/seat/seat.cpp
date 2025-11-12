//SN-J01104 陈安旭 西安滨河学校 
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
long long m , n , r , ii , jj , fx = 0 , bjx = 1, bjy = 1 , qwer[500][500];
long long a[MAXN];

bool cmp(long long c , long long d)
{
	return c > d;
}


signed main()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for (long long i = 1;i <= m * n;i++)
	{
		cin >> a[i];
	}
	r = a[1];
	sort (a + 1 , a + m * n + 1 , cmp);
	for (long long i = 1;i <= m * n;i++)
	{
		if (a[i] == r)
		{
			cout << bjx << " " << bjy;
			return 0;
		}
		if (fx == 0 && bjy + 1 <= n)
		{
			bjy += 1;
		}
		else if (fx == 0 && bjy + 1 > n)
		{
			bjx += 1;
			fx = 1;
		}
		else if (fx == 1 && bjy - 1 >= 1)
		{
			bjy -= 1;
		}
		else if (fx == 1 && bjy - 1 < 1)
		{
			bjx += 1;
			fx = 0;
		}
	}
 	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n,T;
struct club
{
	long long a,b,c;
};
club a[1000000];
int cmp1(club a,club b)
{
	return min((a.a - a.b),(a.a - a.c)) <= min((b.a - b.b),(b.a - b.c));
}
int cmp2(club a,club b)
{
	return min((a.b - a.a),(a.b - a.c)) <= min((b.b - b.a),(b.b - b.c));
}
int cmp3(club a,club b)
{
	return min((a.c - a.a),(a.c - a.b)) <= min((b.c - b.a),(b.c - b.b));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--)
	{
		long long sum = 0,x = 0,y = 0,z = 0;
		cin >> n;
		for (long long i = 1;i <= n;i++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
			if (a[i].a >= a[i].b)
			{
				if (a[i].a >= a[i].c)
				{
					sum += a[i].a;
					x++;
				}
				else
				{
					sum += a[i].c;
					z++;
				}
			}
			else
			{
				if (a[i].b >= a[i].c) 
				{
					sum += a[i].b;
					y++;
				}
				else
				{
					sum += a[i].c;
					z++; 
				}
			}
			//cout << sum << endl;
		}
//		for (int i = 1;i <= n;i++)
//		{
//			cout << a[i].a << ' ' << a[i].b << ' ' << a[i].c << endl;
//		}
		//cout << x << ' ' << y << ' ' << z << endl;
		if (x <= n / 2 && y <= n / 2 && z <= n / 2) 
		{
			cout << sum << endl;
			continue;
		}
		else
		{
			if (x > n / 2)
			{
				sort(a + 1,a + n + 1,cmp1);
				for (long long i = 1;i <= n;i++)
				{
					if (x <= n / 2) break;
					if (a[i].a >= a[i].b && a[i].a >= a[i].c)
					{
						sum = sum - a[i].a + max(a[i].b,a[i].c);
						x--;
					}
					
				}
			}
			else if (y > n / 2)
			{
				sort(a + 1,a + n + 1,cmp2);
				for (long long i = 1;i <= n;i++)
				{
					if (y <= n / 2) break;
					if (a[i].b >= a[i].a && a[i].b >= a[i].c)
					{
						sum = sum - a[i].b + max(a[i].a,a[i].c);
						y--;
					}
				}
			}
			else if (z > n / 2)
			{
				sort(a + 1,a + n + 1,cmp3);
				//for (int i = 1;i <= n;i++) cout << a[i].a << ' ' << a[i].b << ' ' << a[i].c << endl;
				for (long long i = 1;i <= n;i++)
				{
					if (z <= n / 2) break;
					if (a[i].c >= a[i].a && a[i].c >= a[i].b)
					{
						sum = sum - a[i].c + max(a[i].a,a[i].b);	
						z--;
					}
				} 
			}
			cout << sum << endl;
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,ans,member1,member2,member3,x;
struct club
{
	int a,b,c,prefer;
}a[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> x;
	for (int q = 1;q <= x;q++)
	{		cin >> n;
		ans = 0;
		member1 = 0;
		member2 = 0;
		member3 = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
			if (a[i].a > a[i].b && a[i].a > a[i].c)
			{
				if (member1 < n / 2)
				{
					member1++;
					ans += a[i].a;
				}
			}
			else if (a[i].b > a[i].a && a[i].b > a[i].c)
			{
				if (member2 < n / 2)
				{
					member2++;
					ans += a[i].b;
				}
			}
			else if (a[i].c > a[i].a && a[i].c > a[i].b)
			{
				if (member3 < n / 2)
				{
					member3++;
					ans += a[i].c;
				}
			}
			else if (a[i].a == a[i].b || a[i].b == a[i].c)
			{
				if (member1 < n / 2)
				{
					member1++;
					ans += a[i].a;
				}
				else if (member2 < n / 2)
				{
					member2++;
					ans += a[i].b;
				}
				else 
				{
					member3++;
					ans += a[i].b;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
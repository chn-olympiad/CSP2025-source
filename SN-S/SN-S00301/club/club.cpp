//曹子睿 SN-S00301 浐灞第七初级中学 
#include<bits/stdc++.h>
#define longlong ll
using namespace std;
int T, n, ans, cnt;
struct
{
	int x, y, z;
}a[20010];
int r1, r2, r3; 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","W",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		r1 = 0, r2 = 0, r3 = 0;
		for(int i = 1; i <= n ; i++)
		{
			a[i].x = 0, a[i].y = 0, a[i].z = 0;
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		for(int i = 1; i <= n; i++)
		{
			
			if(a[i].x > a[i].y && a[i].x > a[i].z)
			{
				r1++;
				ans += a[i].x;
			 } 
			if(a[i].y > a[i].x && a[i].y > a[i].z)
			{
				r2++;
				ans += a[i].y;
			 } 
			if(a[i].z > a[i].x && a[i].z > a[i].y)
			{
				r3++;
				ans += a[i].z;
			 } 
		}
		if(r1 > n / 2)
		{
			cnt = r1 - n / 2;
			while(cnt--)
			{
				n = a[1].x;
				for(int i = 1; i < n; i++)
				{
					n = min(n, a[i + 1].x);
				}
				ans -= n;
				for(int i = 1; i <= n; i++)
				{
					if(a[i].x == n)
					{
						ans += max(a[i].y, a[i].z);
						break;
					 } 
				}	
			}
			cout << ans << endl;
			continue;
		}
		if(r2 > n / 2)
		{
			cnt = r2 - n / 2;
			while(cnt--)
			{
				n = a[1].y;
				for(int i = 1; i < n; i++)
				{
					n = min(n, a[i + 1].y);
				}
				ans -= n;
				for(int i = 1; i <= n; i++)
				{
					if(a[i].y == n)
					{
						ans += max(a[i].x, a[i].z);	
						break;
					 } 
				}

			}
			cout << ans << endl;
			continue;
		}
		if(r3 > n / 2)
		{
			cnt = r3 - n / 2;
			while(cnt--)
			{
				n = a[1].z;
				for(int i = 1; i < n; i++)
				{
					n = min(n, a[i + 1].z);
				}
				ans -= n;
				for(int i = 1; i <= n; i++)
				{
					if(a[i].z == n)
					{
						ans += max(a[i].y, a[i].x);
						break;
					 } 
				}
			}
			continue;
			cout << ans << endl;
		}
		if(r1 <= n / 2 && r2 <= n / 2 && r3 <= n / 2)
		{
			cout << ans << endl;
			continue;
		}

	}
	return 0;
}

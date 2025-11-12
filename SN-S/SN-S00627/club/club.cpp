#include <bits/stdc++.h>
using namespace std;
int t,n;
struct h
{
	int x,y,z,Max,num;
}a[100005];
bool cmp1(h x1,h x2)
{
	return x1.x > x2.x;
}
bool cmp2(h x1,h x2)
{
	return x1.y > x2.y;
}
int flag = 1,ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].y != 0) flag = 2;
			else if(a[i].z != 0) flag = 3;
		}
		if(flag == 1)
		{
			sort(a+1,a+1+n,cmp1);
			for(int i = 1; i <= n / 2; i++)
			{
				ans += a[i].x;
			}
			cout << ans << "\n";
		}
		else if(flag == 2)
		{
			int ans1 = 0;
			sort(a+1,a+1+n,cmp1);
			for(int i = 1; i <= n / 2; i++)
			{
				ans1 += a[i].x;
			}
			sort(a+1,a+1+n,cmp2);
			for(int i = 1; i <= n / 2; i++)
			{
				ans1 += a[i].y;
			}
			int ans2 = 0;
			sort(a+1,a+1+n,cmp2);
			for(int i = 1; i <= n / 2; i++)
			{
				ans2 += a[i].y;
			}
			sort(a+1,a+1+n,cmp1);
			for(int i = 1; i <= n / 2; i++)
			{
				ans2 += a[i].x;
			}
			ans = max(ans1,ans2);
			cout << ans << "\n";
		}
	}
	return 0;
}

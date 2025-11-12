#include <bits/stdc++.h>
using namespace std;

struct cl
{
	int x,y,z;
};

cl a[100005];

bool cmp1(cl x,cl y)
{
	return x.x > y.x;
}

bool cmp2(cl x,cl y)
{
	return x.y > y.y;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n,cnt = 0,cnt1 = 0;
		cin >> n;
		for(int i = 1;i <= n;i++)
			cin >> a[i].x >> a[i].y >> a[i].z;
		sort(a+1,a+n+1,cmp1);
		int m = n / 2,kx = 0,ky = 0;
		for(int i = 1;i <= n;i++)
		{
			if((a[i].x < a[i].y || kx == m) && ky < m)
			{
				cnt += a[i].y;
				ky++;
			}
			else
			{
				cnt += a[i].x;
				kx++;
			}
		}
		sort(a+1,a+n+1,cmp2);
		kx = 0,ky = 0;
		for(int i = 1;i <= n;i++)
		{
			if((a[i].x < a[i].y || kx == m) && ky < m)
			{
				cnt1 += a[i].y;
				ky++;
			}
			else
			{
				cnt1 += a[i].x;
				kx++;
			}
		}
		cout << max(cnt,cnt1);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
struct point{
	int x,y,z;
}a[100009];
int t;
struct point b[100009];
struct point c[100009];
struct point d[100009];
int n;
bool cmp(point u,point v)
{
	return u.x-max(u.y,u.z)>v.x-max(v.y,v.z);
}
bool cmp2(point u,point v)
{
	return u.y-max(u.x,u.z)>v.y-max(v.x,v.z);
}
bool cmp3(point u,point v)
{
	return u.z-max(u.x,u.y)>v.z-max(v.x,v.y);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d", &t);
	for(int i = 1; i<=t; ++i)
	{
		scanf("%d", &n);
		for(int i = 1; i<=n; ++i)
		{
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
		}
		int t = 0,p = 0,u = 0;
		for(int i = 1; i<=n; ++i)
		{
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
			{
				t++;
				b[t].x=a[i].x;
				b[t].y=a[i].y;
				b[t].z=a[i].z;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
			{
				p++;
				c[p].x=a[i].x;
				c[p].y=a[i].y;
				c[p].z=a[i].z;
			}
			else
			{
				u++;
				d[u].x=a[i].x;
				d[u].y=a[i].y;
				d[u].z=a[i].z;
			}
		}
		int s = 0;
		for(int i = 1; i<=n; ++i)
		{
			s+=max(max(a[i].x,a[i].y),a[i].z);
		}
		if(t<=n/2&&p<=n/2&&u<=n/2)
		{
			printf("%lld\n", s);
		}
		if(t>n/2)
		{
			sort(b+1,b+n+1,cmp);
			int an = 0;
			for(int i = n/2+1; i<=t; ++i)
			{
				an+=b[i].x-max(b[i].y,b[i].z);
			}
			printf("%lld\n", s-an);
		}
		else if(p>n/2)
		{
			sort(c+1,c+n+1,cmp2);
			int an = 0;
			for(int i = n/2+1; i<=p; ++i)
			{
				an+=c[i].y-max(c[i].x,c[i].z);
			}
			printf("%lld\n", s-an);
		}
		else if(u>n/2)
		{
			sort(d+1,d+n+1,cmp3);
			int an = 0;
			for(int i = n/2+1; i<=u; ++i)
			{
				an+=d[i].z-max(d[i].x,d[i].y);
			}
			printf("%lld\n", s-an);
		}
	}
	return 0;
}

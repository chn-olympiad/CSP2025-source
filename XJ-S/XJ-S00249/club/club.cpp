#include <bits/stdc++.h>
using namespace std;
int n,t,maxn;
struct T
{
	long long sum;
	int num;
};
struct P
{
	int x,y,z;
}a[100005];
bool cmp1(P m,P u)
{
	return m.x>u.x;
}
bool cmp2(P m,P u)
{
	if (m.x + m.y > u.x +u.y)
	{
		if (m.x > u.x)
		{
			if (m.y < u.y )
			{
				return true;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}
	return false;
}
bool cmp3(P m,P u)
{
	return m.x+m.y+m.z<u.x+u.y+u.z;
}
bool cmp4(P m,P u)
{
	return m.y > u.y;
}
bool cmp5(P m,P u)
{
	return m.z > u.z;
}
bool flag1,flag2,flag3,flag4;
T l1,l2,l3;
int main()
{	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	
	cin >> t;
	while(t--)
	{
		flag1 = true;
		flag2 = true;
		flag3 = true;
		flag4 = true;
		cin >> n;
		l1.sum = l1.num = l2.sum = l2.num = l3.num = l3.sum = 0;
		int sm = 0;
		maxn = -11111;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].y != 0 || a[i].z != 0 || a[i].x == 0)
				flag1 = false;
			if (a[i].z != 0 || a[i].x == 0)flag2=false;
			if (a[i].x != 0 || a[i].z!=0 || a[i].y == 0)flag3 = false;
			if (a[i].x != 0 || a[i].y!=0 || a[i].z == 0)flag4 = false;
		}
		if (flag1)
		{
			sort(a+1,a+n+1,cmp1);
			for (int i = 1;i <= n/2;i++)
			{
				sm+=a[i].x;
			}
			cout << sm << endl;
			continue;
		}
		if (flag3)
		{
			sort(a+1,a+n+1,cmp4);
			for (int i = 1;i <= n/2;i++)
			{
				sm+=a[i].y;
			}
			cout << sm << endl;
			continue;
		}
		if (flag4)
		{
			sort(a+1,a+n+1,cmp5);
			for (int i = 1;i <= n/2;i++)
			{
				sm+=a[i].z;
			}
			cout << sm << endl;
			continue;
		}
		/*if (flag2 && !flag1)
		{
			sort(a+1,a+n+1,cmp2);
			for (int i = 1;i <= n/2;i++)
			{
				sm+=a[i].x;
			}
			for (int i = n/2+1;i <= n;i++)
				sm+=a[i].y;
			cout << sm << endl;
			continue;
		}*/
		sort(a+1,a+n+1,cmp3);
		for (int i = 1;i <= n;i++)
		{
			maxn = max(a[i].x,max(a[i].y,a[i].z));
			if (maxn == a[i].x)
			{
				if(l1.num < n/2)
				{
					l1.sum+=maxn;
					l1.num++;
				}
				else
				{
					if (a[i].z > a[i].y)
					{
						l3.sum+=maxn;
						l3.num++;
					}
					else
					{
						l2.sum+=maxn;
						l2.num++;
					}
				}
			}
			else if (maxn == a[i].y)
			{
				if(l2.num < n/2)
				{
					l2.sum+=maxn;
					l2.num++;
				}
				else
				{
					if (a[i].x > a[i].z)
					{
						l1.sum+=maxn;
						l1.num++;
					}
					else
					{
						l3.sum+=maxn;
						l3.num++;
					}
				}
				
			}
			else if (maxn == a[i].z)
			{
				if(l3.num < n/2)
				{
					l3.sum+=maxn;
					l3.num++;
				}
				else
				{
					if (a[i].x > a[i].y)
					{
						l1.sum+=maxn;
						l1.num++;
					}
					else
					{
						l2.sum+=maxn;
						l2.num++;
					}
				}
			}
		}
		cout << l1.sum+l2.sum+l3.sum << endl;
	}
	return 0;
}

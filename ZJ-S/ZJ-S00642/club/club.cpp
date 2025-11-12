#include <bits/stdc++.h>
using namespace std;
int n;
//int a[100010];
struct node
{
	int id;
	long long x,y,z;
	long long mx;
	long long qwq;
	bool operator < (const node &cmp) const
	{
		return mx < cmp.mx;
	}
};
priority_queue < node > q;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	long long t1,t2,t3,t4;
	long long c1,c2,c3;
	int lst;
	node ww,vv;
	long long a,b,c;
	long long ret = 0;
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)
		{
			scanf("%lld %lld %lld",&a,&b,&c);
			vv.x = a;
			vv.y = b;
			vv.z = c;
			vv.id = i;
			t1 = max(a,max(b,c));
			if(t1 == a)
			{
				t2 = max(b,c);
				vv.mx = t1 - t2;
				vv.qwq = 1;
				q.push(vv);
				continue;
			}
			if(t1 == b)
			{
				t2 = max(a,c);
				vv.mx = t1 - t2;
				vv.qwq = 2;
				q.push(vv);
				continue;
			}
			if(t1 == c)
			{
				t2 = max(a,b);
				vv.mx = t1 - t2;
				vv.qwq = 3;
				q.push(vv);
				continue;
			}
			
		}
		c1 = 0;
		c2 = 0;
		c3 = 0;
		ret = 0;
		while(!q.empty())
		{
			ww = q.top();
			q.pop();
			t1 = 0;
			t2 = 0;
			t3 = 0;
			if(ww.qwq == 1)
			{
				if(c1 >= (n / 2))
				{
					if(ww.y == -1)
					{
						t1 = 0;
						t2 = 3;
					}
					else if(ww.z == -1)
					{
						t1 = 0;
						t2 = 2;
					}
					else
					{
						if(ww.y > ww.z)
						{
							t1 = ww.y - ww.z;
							t2 = 2;
						}
						else
						{
							t1 = ww.z - ww.y;
							t2 = 3;
						}
					}
					ww.x = -1;
					ww.mx = t1;
					ww.qwq = t2;
					q.push(ww);
					continue;
				}
				ret += ww.x;
				c1++;
				continue;
			}
			//
			if(ww.qwq == 2)
			{
				if(c2 >= (n / 2))
				{
					if(ww.x == -1)
					{
						t1 = 0;
						t2 = 3;
					}
					else if(ww.z == -1)
					{
						t1 = 0;
						t2 = 1;
					}
					else
					{
						if(ww.x > ww.z)
						{
							t1 = ww.x - ww.z;
							t2 = 1;
						}
						else
						{
							t1 = ww.z - ww.x;
							t2 = 3;
						}
					}
					ww.y = -1;
					ww.mx = t1;
					ww.qwq = t2;
					q.push(ww);
					continue;
				}
				ret += ww.y;
				c2++;
				continue;
			}
			//
			if(ww.qwq == 3)
			{
				if(c3 >= (n / 2))
				{
					if(ww.x == -1)
					{
						t1 = 0;
						t2 = 2;
					}
					else if(ww.y == -1)
					{
						t1 = 0;
						t2 = 1;
					}
					else
					{
						if(ww.x > ww.y)
						{
							t1 = ww.x - ww.y;
							t2 = 1;
						}
						else
						{
							t1 = ww.y - ww.x;
							t2 = 2;
						}
					}
					ww.z = -1;
					ww.mx = t1;
					ww.qwq = t2;
					q.push(ww);
					continue;
				}
				ret += ww.z;
				c3++;
				continue;
			}
		}
		printf("%lld\n",ret);
	}
	return 0;
}

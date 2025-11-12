#include<bits/stdc++.h>
using namespace std;
long long t,n,sum[4],a[200010][4];
struct node
{
	long long cha,id;
	bool operator < (const node&cmp)const
	{
		return cmp.cha<cha;
	}
};
priority_queue<node> q1,q2,q3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(long long T=1;T<=t;T++)
	{
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		long long ans=0;
		for(long long i=1;i<=n;i++)
		{
			node h,g;
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				ans+=a[i][1];sum[1]++;
				if(a[i][1]-a[i][2]<=a[i][1]-a[i][3])
				{
					h.cha=a[i][1]-a[i][2];h.id=2;
				}
				else
				{
					h.cha=a[i][1]-a[i][3];h.id=3;
				}
				q1.push(h);
				if(sum[1]>n/2)
				{
					g=q1.top();q1.pop();
					sum[1]--;sum[g.id]++;ans-=g.cha;
					g.cha=(-g.cha);
					if(g.id==2)
					{
						g.id=1;q2.push(g);
					}
					else
					{
						g.id=1;q3.push(g);
					}
				}
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				ans+=a[i][2];sum[2]++;
				if(a[i][2]-a[i][1]<=a[i][2]-a[i][3])
				{
					h.cha=a[i][2]-a[i][1];h.id=1;
				}
				else
				{
					h.cha=a[i][2]-a[i][3];h.id=3;
				}
				q2.push(h);
				if(sum[2]>n/2)
				{
					g=q2.top();q2.pop();
					sum[2]--;sum[g.id]++;ans-=g.cha;
					g.cha=(-g.cha);
					if(g.id==1)
					{
						g.id=2;q1.push(g);
					}
					else
					{
						g.id=2;q3.push(g);
					}
				}
			}
			else
			{
				ans+=a[i][3];sum[3]++;
				if(a[i][3]-a[i][1]<=a[i][3]-a[i][2])
				{
					h.cha=a[i][1]-a[i][1];h.id=1;
				}
				else
				{
					h.cha=a[i][3]-a[i][2];h.id=2;
				}
				q2.push(h);
				if(sum[3]>n/2)
				{
					g=q3.top();q3.pop();
					sum[3]--;sum[g.id]++;ans-=g.cha;
					g.cha=(-g.cha);
					if(g.id==1)
					{
						g.id=3;q1.push(g);
					}
					else
					{
						g.id=3;q2.push(g);
					}
				}
			}
		}
		printf("%lld\n",ans);
		while(!q1.empty())
		{
			q1.pop();
		}
		while(!q2.empty())
		{
			q2.pop();
		}
		while(!q3.empty())
		{
			q3.pop();
		}
	}
	return 0;
}

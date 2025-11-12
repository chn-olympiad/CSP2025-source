#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100010],b[100010],c[100010],d[100010],e[100010];
struct node
{
	int id,d,p;
}f[100010];
bool cmp(node x,node y)
{
	if(x.d>y.d)
	{
		return 1;
	}
	return 0;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--)
	{
		int n;
		scanf("%lld",&n);
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			sum+=a[i];
			d[i]=b[i]-a[i];
			e[i]=c[i]-a[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(d[i]>=e[i])
			{
				f[i].d=d[i];
				f[i].p=0;
			}
			else
			{
				f[i].d=e[i];
				f[i].p=1;
			} 
			f[i].id=i;
		}
		sort(f+1,f+1+n,cmp);
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n/2;i++)
		{
			if(f[i].p==0)
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
			sum+=f[i].d;
		}
		int i=n/2+1;
		while(f[i].d>0&&i<=n)
		{
			if(f[i].p==0)
			{
				if(cnt1>=n/2)
				{
					i++;
					continue;
				}
				cnt1++;
			}
			else
			{
				if(cnt2>=n/2)
				{
					i++;
					continue;
				}
				cnt2++;
			}
			sum+=f[i].d;
			i++;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
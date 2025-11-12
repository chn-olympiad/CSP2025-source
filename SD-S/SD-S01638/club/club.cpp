#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct member
{
	int x,y,z;
}a[10001];
bool cmp(member p,member q)
{
	return max(max(p.x,p.y),p.z)>max(max(q.x,q.y),q.z);
}
int n,t,cnt1,cnt2,cnt3,cntfl;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		ll ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		cntfl=n;
		while(cntfl>0)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=cntfl;i++)
			{
				if(a[i].x!=0&&a[i].x==max(max(a[i].x,a[i].y),a[i].z))
				{
					if(cnt1<n/2)
					{
						cnt1++;
						ans+=(ll)(a[i].x);
						a[i].x=0;
						a[i].y=0;
						a[i].z=0;
					}
					else
					{
						a[i].x=0;
					}
				}
				if(a[i].y!=0&&a[i].y==max(max(a[i].x,a[i].y),a[i].z))
				{
					if(cnt2<n/2)
					{
						cnt2++;
						ans+=(ll)(a[i].y);
						a[i].x=0;
						a[i].y=0;
						a[i].z=0;
					}
					else
					{
						a[i].y=0;
					}
				}
				if(a[i].z!=0&&a[i].z==max(max(a[i].x,a[i].y),a[i].z))
				{
					if(cnt3<n/2)
					{
						cnt3++;
						ans+=(ll)(a[i].z);
						a[i].x=0;
						a[i].y=0;
						a[i].z=0;
					}
					else
					{
						a[i].z=0;
					}
				}
				if(a[i].x==0&&a[i].y==0&&a[i].z==0)
				{
					cntfl--;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

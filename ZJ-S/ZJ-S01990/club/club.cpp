#include<bits/stdc++.h>
using namespace std;
int n,n1,n2,n3;
long long ans;
struct peo
{
	int x,y,z,m;
}a[100007];
bool cmp1(peo u,peo v)
{
	if(v.m!=1) return 1;
	if(u.m!=1&&v.m==1) return 0;
	return min(u.x-u.y,u.x-u.z)<min(v.x-v.y,v.x-v.z);
}
bool cmp2(peo u,peo v)
{
	if(v.m!=2) return 1;
	if(u.m!=2&&v.m==2) return 0;
	return min(u.y-u.x,u.y-u.z)<min(v.y-v.x,v.y-v.z);
}
bool cmp3(peo u,peo v)
{
	if(v.m!=3) return 1;
	if(u.m!=3&&v.m==3) return 0;
	return min(u.z-u.y,u.z-u.x)<min(v.z-v.y,v.z-v.x);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		n1=0;
		n2=0;
		n3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x>=a[i].z&&a[i].x>=a[i].y)
			{
				ans+=a[i].x;
				a[i].m=1;
				n1++;
			}
			else if(a[i].x<=a[i].y&&a[i].y>=a[i].z)
			{
				ans+=a[i].y;
				a[i].m=2;
				n2++;
			}
			else
			{
				ans+=a[i].z;
				a[i].m=3;
				n3++;
			}
		}
		if(n1*2>n)
		{
			sort(a+1,a+n+1,cmp1);
			n1-=n/2;
			for(int i=1;i<=n1;i++)
			{
				ans-=min(a[i].x-a[i].y,a[i].x-a[i].z);
			}
		}
		else if(n2*2>n)
		{
			sort(a+1,a+n+1,cmp2);
			n2-=n/2;
			for(int i=1;i<=n2;i++)
			{
				ans-=min(a[i].y-a[i].z,a[i].y-a[i].x);
			}
		}
		else if(n3*2>n)
		{
			sort(a+1,a+n+1,cmp3);
			n3-=n/2;
			for(int i=1;i<=n3;i++)
			{
				ans-=min(a[i].z-a[i].y,a[i].z-a[i].x);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

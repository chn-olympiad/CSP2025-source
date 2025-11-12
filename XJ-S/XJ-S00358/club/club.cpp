#include<bits/stdc++.h>
using namespace std;
long long int i,j,k,n,my,xm,ym,zm,cmdy,t,ans1,ans2,ans3,ans4,ans5,ans6,ans;
struct node
{
	long long int x,z,y,f;
}a[1000005],cp[1000005];
bool cmp(node a,node b)
{
	if(cmdy==10)
	{
		return a.f<b.f;
	}
	else
	if(cmdy==1)
	{
		if(a.x!=b.x)
		return a.x>b.x;
		else
		if(a.y!=b.y)
		return a.y<b.y;
		else
		if(a.z!=b.z)
		return a.z<b.z;
		else
		return a.f<b.f; 
	}
	else
	if(cmdy==2)
	{
		if(a.x!=b.x)
		return a.x>b.x;
		else
		if(a.z!=b.z)
		return a.z<b.z;
		else
		if(a.y!=b.y)
		return a.y<b.y;
		else
		return a.f<b.f; 
	}
	else
	if(cmdy==3)
	{
		if(a.y!=b.y)
		return a.y>b.y;
		else
		if(a.x!=b.x)
		return a.x<b.x;
		else
		if(a.z!=b.z)
		return a.z<b.z;
		else
		return a.f<b.f; 
	}
	else
	if(cmdy==4)
	{
		if(a.y!=b.y)
		return a.y>b.y;
		else
		if(a.z!=b.z)
		return a.z<b.z;
		else
		if(a.x!=b.x)
		return a.x<b.x;
		else
		return a.f<b.f; 
	}
	else
	if(cmdy==5)
	{
		if(a.z!=b.z)
		return a.z>b.z;
		else
		if(a.x!=b.x)
		return a.x<b.x;
		else
		if(a.y!=b.y)
		return a.y<b.y;
		else
		return a.f<b.f; 
	}
	else
	if(cmdy==6)
	{
		if(a.z!=b.z)
		return a.z>b.z;
		else
		if(a.y!=b.y)
		return a.y<b.y;
		else
		if(a.x!=b.x)
		return a.x<b.x;
		else
		return a.f<b.f; 
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cmdy=0;
		memset(a,0,sizeof(a));
		my=0;
		ans1=0;
		ans2=0;
		ans3=0;
		ans4=0;
		ans5=0;
		ans6=0;
		xm=0; ym=0; zm=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z);
			xm+=a[i].x; ym+=a[i].y; zm+=a[i].z;
			cp[i].x=a[i].x; cp[i].y=a[i].y; cp[i].z=a[i].z; cp[i].f=0;
		}
		cmdy=1;
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n/2;i++)
		{
			if(a[i].f!=1)
			{
				ans1+=a[i].x;
				a[i].f=1;
			}
		}		
		cmdy=10;
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n/2;i++)
		{
			if(a[i].y>a[i].z&&a[i].f!=1)
			{
				ans1+=a[i].y;
				a[i].f=1;
			}
			else
			if(a[i].z>=a[i].x&&a[i].f!=1)
			{
				ans1+=a[i].z;
				a[i].f=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			a[i].x=cp[i].x;
			a[i].y=cp[i].y;
			a[i].z=cp[i].z;
			a[i].f=0;
		}
		cmdy=2;
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n/2;)
		{
			if(a[i].f!=1)
			{
				ans2+=a[i].x;
				a[i].f=1;
				i++;
			}
		}
		cmdy=10;
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n/2;i++)
		{
			if(a[i].y>a[i].z&&a[i].f!=1)
			{
				ans2+=a[i].y;
				a[i].f=1;
			}
			else
			if(a[i].z>=a[i].x&&a[i].f!=1)
			{
				ans2+=a[i].z;	
				a[i].f=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			a[i].x=cp[i].x;
			a[i].y=cp[i].y;
			a[i].z=cp[i].z;
			a[i].f=0;
		}
		cmdy=3;
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n/2;i++)
		{
			if(a[i].f!=1)
			{
				ans3+=a[i].y;
				a[i].f=1;
			}
		}
		cmdy=10;
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n/2;i++)
		{
			if(a[i].x>a[i].z&&a[i].f!=1)
			{
				ans3+=a[i].x;
				a[i].f=1;
			}
			else
			if(a[i].z>=a[i].x&&a[i].f!=1)
			{
				ans3+=a[i].z;
				a[i].f=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			a[i].x=cp[i].x;
			a[i].y=cp[i].y;
			a[i].z=cp[i].z;
			a[i].f=0;
		}
		cmdy=4;
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n/2;i++)
		{
			if(a[i].f!=1)
			{
				ans4+=a[i].y;
				a[i].f=1;
			}
		}
		cmdy=10;
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n/2;i++)
		{
			if(a[i].x>a[i].z&&a[i].f!=1)
			{
				ans4+=a[i].x;
				a[i].f=1;
			}
			else
			if(a[i].z>=a[i].x&&a[i].f!=1)
			{
				ans4+=a[i].z;
				a[i].f=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			a[i].x=cp[i].x;
			a[i].y=cp[i].y;
			a[i].z=cp[i].z;
			a[i].f=0;
		}
		cmdy=5;
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n/2;i++)
		{
			if(a[i].f!=1)
			{
				ans5+=a[i].z;
				a[i].f=1;
			}
		}
		cmdy=10;
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n/2;i++)
		{
			if(a[i].x>a[i].y&&a[i].f!=1)
			{
				ans5+=a[i].x;
				a[i].f=1;
			}
				else
			{
				if(a[i].y>=a[i].x&&a[i].f!=1)			
				ans5+=a[i].y;
				a[i].f=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			a[i].x=cp[i].x;
			a[i].y=cp[i].y;
			a[i].z=cp[i].z;
			a[i].f=0;
		}
		cmdy=6;
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n/2;i++)
		{
			if(a[i].f!=1)
			{
				ans6+=a[i].z;
				a[i].f=1;
			}
		}
		cmdy=10;
		sort(a+1,a+n+1,cmp);
		for(i=1;i<=n/2;i++)
		{
			if(a[i].x>a[i].y&&a[i].f!=1)
			{
				ans6+=a[i].x;
				a[i].f=1;
			}
			else
			if(a[i].y>=a[i].x&&a[i].f!=1)
			{
				ans6+=a[i].y;
				a[i].f=1;
			}
		}
		ans=max(ans1,max(ans2,max(ans3,max(ans4,max(ans5,ans6)))));
		cout<<ans<<endl;
	}
	return 0;
}

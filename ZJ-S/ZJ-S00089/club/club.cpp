#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
struct node
{
	int a,b,c;
}a[100005];
int tot;
bool cmp(node a,node b)
{
	return max(a.b-a.a,a.c-a.a)>max(b.b-b.a,b.c-b.a);
}
int work()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i].a;
	}
	sort(a+1,a+1+n,cmp);
	int b=0,c=0;
	for(int i=1;i<=n/2;i++)
	{
		if(a[i].a-a[i].b<a[i].a-a[i].c)
		{
			ans=ans-a[i].a+a[i].b;
			b++;
		}
		else if(a[i].a-a[i].b>a[i].a-a[i].c)
		{
			ans=ans-a[i].a+a[i].c;
			c++;
		}
		else if(a[i].a-a[i].b==a[i].a-a[i].c)
		{
			if(b<c)
				b++;
			else
				c++;
			ans=ans-a[i].a+a[i].c;
		}
	}
	for(int i=n/2+1;i<=n;i++)
	{
		if(b==n/2&&a[i].a<a[i].c)
		{
			c++;
			ans=ans-a[i].a+a[i].c;
		}
		else if(c==n/2&&a[i].a<a[i].b)
		{
			b++;
			ans=ans-a[i].a+a[i].b;
		}
		else if(c!=n/2&&b!=n/2&&a[i].a<a[i].b&&a[i].a<a[i].c)
		{
			if(a[i].b-a[i].a>a[i].c-a[i].a)
			{
				b++;
				ans=ans-a[i].a+a[i].b;
			}
			else
			{
				c++;
				ans=ans-a[i].a+a[i].c;
			}
		}
		else if(c<n/2&&a[i].a<a[i].c)
		{
			c++;
			ans=ans-a[i].a+a[i].c;
		}
		else if(b<n/2&&a[i].a<a[i].b)
		{
			b++;
			ans=ans-a[i].a+a[i].b;
		}
	}
	return ans;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
    while(t--)
    {
    	scanf("%lld",&n);
    	for(int i=1;i<=n;i++)
    	{
    		scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
		}
		int maxn=0;
		maxn=max(work(),maxn);
		for(int i=1;i<=n;i++)
    	{
    		swap(a[i].a,a[i].b);
		}
		maxn=max(work(),maxn);
		for(int i=1;i<=n;i++)
    	{
    		swap(a[i].a,a[i].c);
		}
		maxn=max(work(),maxn);
		printf("%lld\n",maxn);
	}
}   

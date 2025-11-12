#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,c,maxn,mid;
}a[100010];
bool cmp(node a,node b)
{
	if((a.maxn-a.mid)==(b.maxn-b.mid))
	{
		return a.maxn>b.maxn;
	}
	return (a.maxn-a.mid)>(b.maxn-b.mid);
}
int qmax(int a,int b,int c)
{
	if(a>b)
	{
		if(c>a)return c;
		return a;
	}
	if(c>b)return c;
	return b;
}
int qmin(int a,int b,int c)
{
	if(a<b)
	{
		if(c<a)return c;
		return a;
	}
	if(c<b)return c;
	return b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].maxn=qmax(a[i].a,a[i].b,a[i].c);
			a[i].mid=a[i].a+a[i].b+a[i].c-qmin(a[i].a,a[i].b,a[i].c)-a[i].maxn;
		}
		sort(a+1,a+n+1,cmp);
		int ans=0,an=0,bn=0,cn=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].a==a[i].maxn)
			{
				if(an*2<n)
				{
					an++;
					ans+=a[i].maxn;
				}
				else
				{
					ans+=a[i].mid;
				}
			}
			else if(a[i].b==a[i].maxn)
			{
				if(bn*2<n)
				{
					bn++;
					ans+=a[i].maxn;
				}
				else
				{
					ans+=a[i].mid;
				}
			}
			else
			{
				if(cn*2<n)
				{
					cn++;
					ans+=a[i].maxn;
				}
				else
				{
					ans+=a[i].mid;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//HI CCF
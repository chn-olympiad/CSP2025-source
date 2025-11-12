#include<iostream>
#include<algorithm>
using namespace std;
int t,n;
struct node
{
	int a,b,c,m1,m2,d;
}p[100001];
bool cmp(node x,node y)
{
	if(x.d>y.d)
	{
		return 1;
	}
	if(x.d==y.d)
	{
		if(x.m1>y.m1)
		{
			return 1;
		}
		return 0;
	}
	return 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].a>>p[i].b>>p[i].c;
			int n1=p[i].a,n2=p[i].b,n3=p[i].c;
			if(n1>n2)
			{
				swap(n1,n2);
			}
			if(n2>n3)
			{
				swap(n2,n3);
			}
			if(n1>n2)
			{
				swap(n1,n2);
			}
			p[i].m1=n3;
			p[i].m2=n2;
			p[i].d=p[i].m1-p[i].m2;
		}
		sort(p+1,p+n+1,cmp);
		int c1=0,c2=0,c3=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i].a==p[i].m1)
			{
				if(c1==n/2)
				{
					ans+=p[i].m2;
				}
				else
				{
					c1++;
					ans+=p[i].a;
				}
			}
			else if(p[i].b==p[i].m1)
			{
				if(c2==n/2)
				{
					ans+=p[i].m2;
				}
				else
				{
					c2++;
					ans+=p[i].b;
				}
			}
			else
			{
				if(c3==n/2)
				{
					ans+=p[i].m2;
				}
				else
				{
					c3++;
					ans+=p[i].c;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
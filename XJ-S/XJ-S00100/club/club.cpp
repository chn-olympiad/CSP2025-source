#include <bits/stdc++.h>
using namespace std;
long long int t,n,ans,a1,b1,c1,ans1,f,flag;
struct node
{
	long long int a,b,c,d,e;
}q[100005];
bool cmp(node a,node b)
{
	if(a.d==b.d)
	{
		return a.e>b.e;
	}
	else
	{
		return a.d>b.d;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0,a1=0,b1=0,c1=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>q[i].a>>q[i].b>>q[i].c;
			q[i].d=(q[i].a-q[i].b)*(q[i].a-q[i].b);
			q[i].e=(q[i].b-q[i].c)*(q[i].b-q[i].c);	
		}
		sort(q+1,q+1+n,cmp);
		for(int i=1;i<=n;i++)
		{

			flag=0;
			if(a1<n/2)
			{
				if(q[i].a>=q[i].b&&q[i].a>=q[i].c&&flag==0)
				{
					
					flag=1;
					ans+=q[i].a;
					a1++;
				}
			}
			q[i].a=0;
			if(b1<n/2)
			{
				if(q[i].b>=q[i].a&&q[i].b>=q[i].c&&flag==0)
				{
					flag=1;
					ans+=q[i].b;
					b1++;
				}
			}
			q[i].b=0;
			if(c1<n/2)
			{
				if(q[i].c>=q[i].b&&q[i].c>=q[i].a&&flag==0)
				{
					flag=1;
					ans+=q[i].c;
					c1++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

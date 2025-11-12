#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long int d1,d2,d3,maxn;
}a[10000005];
bool cmp(node a,node b)
{
	return a.maxn>b.maxn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long int n,i,j,t;
	cin>>t;
	while(t--)
	{
		long long int s1=0,s2=0,s3=0,p1,p2,p3,ans=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
		cin>>a[i].d1>>a[i].d2>>a[i].d3;
		a[i].maxn=max(max(a[i].d1,a[i].d2),a[i].d3);
		}
		if(n==2)
		{
			long long int maxn=-1;
			if(a[1].d1+a[2].d2>maxn)
			maxn=a[1].d1+a[2].d2;
			if(a[1].d1+a[2].d3>maxn)
			maxn=a[1].d1+a[2].d3;
			if(a[1].d2+a[2].d1>maxn)
			maxn=a[1].d2+a[2].d1;
			if(a[1].d2+a[2].d3>maxn)
			maxn=a[1].d2+a[2].d3;
			if(a[1].d3+a[2].d1>maxn)
			maxn=a[1].d3+a[2].d1;
			if(a[1].d3+a[2].d2>maxn)
			maxn=a[1].d3+a[2].d2;
			cout<<maxn<<endl; 
			continue;
		}
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=n;i++)
		{
		p1=a[i].d1,p2=a[i].d2,p3=a[i].d3;
		if(p1>p2&&p1>p3)
		{
			s1++;
			if(s1<=n/2)
			ans+=p1;
			else
			if(p2>p3)
			{
				s2++;
				ans+=p2;
			}
			else
			{
				s3++;
				ans+=p3;
			}
		}
		if(p2>p1&&p2>p3)
		{
			s2++;
			if(s2<=n/2)
			ans+=p2;
			else
			if(p1>p3)
			{
				s1++;
				ans+=p1;
			}
			else
			{
				s3++;
				ans+=p3;
			}
		}
		if(p3>p1&&p3>p2)
		{
			s3++;
			if(s3<=n/2)
			ans+=p3;
			else
			if(p1>p2)
			{
				s1++;
				ans+=p1;
			}
			else
			{
				s2++;
				ans+=p2;
			}
		}		
		}
		cout<<ans<<endl;
	}
	return 0;
}

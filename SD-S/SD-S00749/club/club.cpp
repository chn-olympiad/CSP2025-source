#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long a,b,c,m1,m2,w1,w2;
}a[100020];
bool cmp (node a,node b)
{
	return (a.m1-a.m2)>(b.m1-b.m2);
}
long long cnt[12];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long T,i,j;
	cin>>T;
	while (T--)
	{
		long long n;
		cin>>n;
		for (i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if (a[i].a<a[i].b)
			{
				a[i].m1=a[i].b;
				a[i].m2=a[i].a;
				a[i].w1=2;
				a[i].w2=1;
			}
			else
			{
				a[i].m1=a[i].a;
				a[i].m2=a[i].b;
				a[i].w1=1;
				a[i].w2=2;
			}
			if (a[i].c>a[i].m1)
			{
				a[i].m2=a[i].m1;a[i].m1=a[i].c;a[i].w2=a[i].w1;a[i].w1=3;
			}
			else if (a[i].c>a[i].m2)
			{
				a[i].m2=a[i].c;a[i].w2=3;
			}
		}	sort(a+1,a+n+1,cmp);
		long long ans=0;
		for (i=1;i<=n;i++)
		{
			if (cnt[a[i].w1]!=n/2)
			{
				cnt[a[i].w1]++;
				ans+=a[i].m1;
			}
			else
			{
				cnt[a[i].w2]++;
				ans+=a[i].m2;
			}
		}
		cout<<ans<<"\n";
		for (i=1;i<=n;i++) a[i].a=0,a[i].b=0,a[i].c=0,a[i].m1=0,a[i].m2=0,a[i].w1=0,a[i].w2=0;
		for (i=1;i<=3;i++) cnt[i]=0;
	}
	
	return 0;
}


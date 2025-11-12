#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int a[100005];
int b[100005];
int c[100005];

int p[100005];

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
			cin>>a[i]>>b[i]>>c[i];
		}
		int c1=0,c2=0,c3=0;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=b[i]&&a[i]>=c[i])
			{
				c1++;
				ans+=a[i];
			}
			else if(b[i]>=a[i]&&b[i]>=c[i])
			{
				c2++;
				ans+=b[i];
			}
			else if(c[i]>=a[i]&&c[i]>=b[i])
			{
				c3++;
				ans+=c[i];
			}
		}
		if(c1>n/2)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]>=b[i]&&a[i]>=c[i])
				{
					p[++cnt]=a[i]-max(b[i],c[i]);
				}
			}
			sort(p+1,p+cnt+1);
			for(int i=1;i<=c1-n/2;i++)
			{
				ans-=p[i];
			}
		}
		else if(c2>n/2)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(b[i]>=a[i]&&b[i]>=a[i])
				{
					p[++cnt]=b[i]-max(a[i],c[i]);
				}
			}
			sort(p+1,p+cnt+1);
			for(int i=1;i<=c2-n/2;i++)
			{
				ans-=p[i];
			}
		}
		else if(c3>n/2)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(c[i]>=b[i]&&c[i]>=a[i])
				{
					p[++cnt]=c[i]-max(b[i],a[i]);
				}
			}
			sort(p+1,p+cnt+1);
			for(int i=1;i<=c3-n/2;i++)
			{
				ans-=p[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
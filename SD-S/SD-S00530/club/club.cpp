#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long t,n,ans,cnt;
struct Pm
{
	long long mo,md,mt;
	long long mx,cx;
	short int mxh;
	long long deg;
}a[N];
bool cmp(Pm a,Pm b)
{
	if(a.mxh==b.mxh)return a.mx>b.mx;
	return a.mxh<b.mxh;
}
bool cms(Pm a,Pm b)
{
	return a.deg<b.deg;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int p=1;p<=t;p++)
	{
		ans=0;
		cin>>n;
		long long u=n/2,qe=0,qd=0,qf=0,qee=0,qdd=0,qff=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].mo>>a[i].md>>a[i].mt;
			a[i].mx=max(a[i].mo,max(a[i].md,a[i].mt));
			if(max(a[i].mo,max(a[i].md,a[i].mt))==a[i].mo)
			{
				a[i].mxh=1;
				if(max(a[i].md,a[i].mt)==a[i].md)
				{
					a[i].cx=a[i].md;
				}
				else
				{
					a[i].cx=a[i].mt;
				}
			}
			else if(max(a[i].mo,max(a[i].md,a[i].mt))==a[i].md)
			{
				a[i].mxh=2;
				if(max(a[i].mo,a[i].mt)==a[i].mo)
				{
					a[i].cx=a[i].mo;
				}
				else
				{
					a[i].cx=a[i].mt;
				}
			}
			else
			{
				a[i].mxh=3;
				if(max(a[i].mo,a[i].md)==a[i].md)
				{
					a[i].cx=a[i].md;
				}
				else
				{
					a[i].cx=a[i].mo;
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(a[i].mxh==1)qe++;
			if(a[i].mxh==2)qd++;
			if(a[i].mxh==3)qf++;
		}
		if(qe<=u&&qd<=u&&qf<=u)
		{
			for(int i=1;i<=n;i++)
			{
				ans+=a[i].mx;
			}
			cout<<ans<<endl;
			continue;
		}
		else
		{
			if(qe>u)
			{
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=qe;i++)
				{
					a[i].deg=a[i].mx-a[i].cx;
				}
				sort(a+1,a+qe+1,cms);
				for(int i=1;i<=qe-u;i++)
				{
					a[i].mx=a[i].mx-a[i].deg;
				}
				for(int i=1;i<=n;i++)
				{
					ans+=a[i].mx;
				}
				cout<<ans<<endl;
			}
			else if(qd>u)
			{
				sort(a+1,a+n+1,cmp);
				for(int i=qe+1;i<=qe+qd;i++)
				{
					a[i].deg=a[i].mx-a[i].cx;
				}
				sort(a+qe+1,a+qe+qd+1,cms);
				for(int i=qe+1;i<=qe+qd-u;i++)
				{
					a[i].mx=a[i].mx-a[i].deg;
				}
				for(int i=1;i<=n;i++)
				{
					ans+=a[i].mx;
				}
				cout<<ans<<endl;
			}
			else if(qf>u) 
			{
				sort(a+1,a+n+1,cmp);
				for(int i=qe+qd+1;i<=n;i++)
				{
					a[i].deg=a[i].mx-a[i].cx;
				}
				sort(a+qe+qd+1,a+n+1,cms);
				for(int i=qe+qd+1;i<=u;i++)
				{
					a[i].mx=a[i].cx;
				}
				for(int i=1;i<=n;i++)
				{
					ans+=a[i].mx;
				}
				cout<<ans<<endl;
			}	
		}
	}
	
	return 0;
}

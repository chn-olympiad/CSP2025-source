#include<bits/stdc++.h>
using namespace std;
struct point
{
	int a,b,c;
};
int T,n;
bool cmpa(point x,point y)
{
	return x.a>y.a;
}
bool cmpb(point x,point y)
{
	return x.b>y.b;
}
bool cmpc(point x,point y)
{
	return x.c>y.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		point a[100001];
		int ans=0,sa=0,sb=0,sc=0,t=0,ta=0,tb=0,tc=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			ta+=a[i].a,tb+=a[i].b,tc+=a[i].c;
		}
		if(ta>=tb&&ta>=tc)sort(a+1,a+n+1,cmpa);
		else if(tb>=ta&&tb>=tc)sort(a+1,a+n+1,cmpb);
		else sort(a+1,a+n+1,cmpc);
		for(int i=n;i>=1;i--)
		{
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c&&sa<n/2)
			{
				sa++;
				t+=a[i].a;
			}
			else if(a[i].b>=a[i].c&&sb<n/2)
			{
				sb++;
				t+=a[i].b;
			}
			else if(a[i].c>=a[i].b&&sc<n/2)
			{
				sc++;
				t+=a[i].c;
			}
		}
		sc=0,sb=0,sa=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c&&sa<n/2)
			{
				sa++;
				ans+=a[i].a;
			}
			else if(a[i].b>=a[i].c&&sb<n/2)
			{
				sb++;
				ans+=a[i].b;
			}
			else if(a[i].c>=a[i].b&&sc<n/2)
			{ 
				sc++;
				ans+=a[i].c;
			}
		}
		ans=max(ans,t);
		cout<<ans<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s,ans=0,maxx;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	if(n==1||n==2)
	{
		cout<<"0";
		return 0;
	}
	if(n==3)
	{
		s=a[1]+a[2]+a[3];
		if(s>2*a[3])cout<<"1";
		else cout<<"0";
		return 0;
	}
	if(n==4)
	{
		for(int i=1;i<=3;i++)
		{
			s=a[1]+a[2]+a[3]+a[4];
			s-=a[i];
			if(s>2*a[4])ans++;
		}
		s=a[1]+a[2]+a[3];
		if(s>2*a[3])ans++;
	}
	if(n==4)
	{
		int p=0;
		s=0;
		for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
		for(int x=1;i<=2;i++)
		for(int y=1;j<=2;j++)
		{
			maxx=0;
			if(i==1)
			{
				p++;
				s+=a[1];
				if(1>maxx)maxx=1;
			}
			if(j==1)
			{
				p++;
				s+=a[2];
				if(2>maxx)maxx=2;
			}
			if(x==1)
			{
				p++;
				s+=a[3];
				if(3>maxx)maxx=3;
			}
			if(y==1)
			{
				p++;
				s+=a[4];
				if(4>maxx)maxx=4;
			}
			if(p>=3)
			{
				if(s>a[maxx]*2)ans++;
			}
		}
	}
	if(n==5)
	{
		s=a[1]+a[2]+a[3];
		if(s>2*a[3])ans++;
		s=a[1]+a[2]+a[4];
		if(s>2*a[4])ans++;
		s=a[1]+a[2]+a[5];
		if(s>2*a[5])ans++;
		s=a[1]+a[3]+a[4];
		if(s>2*a[4])ans++;
		s=a[1]+a[3]+a[5];
		if(s>2*a[5])ans++;
		s=a[1]+a[4]+a[5];
		if(s>2*a[5])ans++;
		s=a[2]+a[3]+a[4];
		if(s>2*a[4])ans++;
		s=a[2]+a[3]+a[5];
		if(s>2*a[5])ans++;
		s=a[2]+a[4]+a[5];
		if(s>2*a[5])ans++;
		s=a[3]+a[4]+a[5];
		if(s>2*a[5])ans++;
		s=a[1]+a[2]+a[3]+a[4];
		if(s>2*a[4])ans++;
		s=a[1]+a[2]+a[3]+a[5];
		if(s>2*a[5])ans++;
		s=a[1]+a[2]+a[5]+a[4];
		if(s>2*a[5])ans++;
		s=a[1]+a[5]+a[3]+a[4];
		if(s>2*a[5])ans++;
		s=a[2]+a[5]+a[3]+a[4];
		if(s>2*a[5])ans++;
		s=a[1]+a[2]+a[3]+a[4]+a[5];
		if(s>2*a[5])ans++;
	}
	if(n>=6)ans=1;
	cout<<ans%998244353;
}

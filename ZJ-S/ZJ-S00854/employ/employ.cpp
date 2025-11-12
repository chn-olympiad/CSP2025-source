#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,a[500],b[500],ans1=0;
string xx;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>xx;
	int sss=0,ssss=1;
	for(int i=0;i<n;i++)
	{
		b[i]=xx[i];
		if(ssss==1&&b[i]==0)
		{
			sss++;
		}
		else
			ssss=0;
		if(a[i]==1)
			ans1++;
	}
	if(ssss==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]=min(a[i],n);
		if(a[i]>=sss)
			ssss++;
	}
	if(ans1<m||ssss<m)
	{
		cout<<0;
		return 0;
	}
	if(n==m)
	{
		if(ans1!=n)
		{
			cout<<0;
			return 0;
		}
		long long ans=1;
		sort(a,a+n);
		for(int i=0;i<n;i++)
		{
			ans=ans*(a[i]-i)%998244353;
		}
		return 0;
	}
	if(m==1)
	{
		long long ans2=1;
		for(int i=1;i<=n;i++)
		{
			ans2=(ans2*n)%998244353;
		}
		long long ans=1;
		sort(a,a+n);
		for(int i=n-1;i>=0;i++)
		{
			ans=(ans*(a[i]-i)%998244353)%998244353;
		}
		ans2=(ans2+998244353-ans)%998244353;
		cout<<ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
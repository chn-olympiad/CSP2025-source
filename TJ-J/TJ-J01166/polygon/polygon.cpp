#include <bits/stdc++.h>
using namespace std;
int MOD=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,maxx=0,num=0,ss=1,ff=1,v=0;
	cin>>n;
	int a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
		if(a[i]==1)
		{
			num++;
		}
	}
	if(n==1&&n==2)
	{
		cout<<"0";
		return 0;
	}
	if(n==3)
	{
		if(sum>2*maxx)
		{
			cout<<"1";
			return 0;
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	if(n==num)
	{
		for(int i=3;i<=n;i++)
		{
			ss=1,ff=1;
			for(int j=1;j<=i;j++)
			{
				ss*=(n-j+1);
				ff*=j;
				ss=ss%MOD;
				ff=ff%MOD;
			}
			v+=ss/ff;
		}
		cout<<v;
		return 0;
	}
	return 0;
}

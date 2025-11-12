#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool f=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
	}
	else if(f==0)
	{
		long long cnt=0;
		for(int i=3;i<=n;i++)
		{
			int t=i;
			long long tmp1=1,tmp2=1;
			for(int j=n;t>=1;t--,j--)
			{
				tmp1*=j;
				tmp2*=t;
			}
			cnt+=tmp1/tmp2;
		}
		cout<<cnt%998244353;
	}
	else
	{
		int cnt=0;
		for(int i=3;i<=n;i++)
		{
			int sum=a[i];
			for(int j=1;j<i;j++)
			{
				sum+=a[j];
				for(int k=j+1;k<i;k++)
				{
					sum+=a[k];
					if(2*a[i]<sum)cnt++;
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}

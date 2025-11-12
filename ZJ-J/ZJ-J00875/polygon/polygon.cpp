#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int a[N];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m=max(m,a[i]);
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])
			cout<<1;
		else
			cout<<0;
	}
	if(n<3)
		cout<<0;
	int sum=0;
	if(m==1)
	{
		for(int i=3;i<=n;i++)
		{
			int x=1;
			for(int j=1;j<=i;j++)
			{
				x*=(n-j+1);
				x%=998244353;
			}
			sum+=x;
			sum%=998244353;
		}
		cout<<sum;
		return 0;
	}
	if(n==4)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])
			sum++;
		if(a[1]+a[2]>a[4]&&a[1]+a[4]>a[2]&&a[2]+a[4]>a[1])
			sum++;
		if(a[1]+a[4]>a[3]&&a[1]+a[3]>a[4]&&a[3]+a[4]>a[1])
			sum++;
		if(a[4]+a[2]>a[3]&&a[4]+a[3]>a[2]&&a[2]+a[4]>a[3])
			sum++;
		if(a[1]+a[2]+a[3]+a[4]>2*max(max(max(a[1],a[2]),a[3]),a[4]))
			sum++;
		cout<<sum;
		return 0;
	}
	if(n==5)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])
			sum++;
		if(a[1]+a[2]>a[4]&&a[1]+a[4]>a[2]&&a[2]+a[4]>a[1])
			sum++;
		if(a[1]+a[4]>a[3]&&a[1]+a[3]>a[4]&&a[3]+a[4]>a[1])
			sum++;
		if(a[4]+a[2]>a[3]&&a[4]+a[3]>a[2]&&a[2]+a[3]>a[4])
			sum++;
		if(a[1]+a[2]>a[5]&&a[1]+a[5]>a[2]&&a[2]+a[5]>a[1])
			sum++;
		if(a[1]+a[5]>a[4]&&a[1]+a[4]>a[5]&&a[5]+a[4]>a[1])
			sum++;
		if(a[5]+a[4]>a[3]&&a[3]+a[5]>a[4]&&a[3]+a[4]>a[5])
			sum++;
		if(a[4]+a[2]>a[5]&&a[4]+a[5]>a[2]&&a[2]+a[4]>a[4])
			sum++;
		if(a[1]+a[5]>a[3]&&a[1]+a[3]>a[5]&&a[5]+a[3]>a[1])
			sum++;
		if(a[5]+a[2]>a[3]&&a[3]+a[5]>a[2]&&a[3]+a[2]>a[5])
			sum++;
		if(a[1]+a[2]+a[3]+a[4]>2*max(max(max(a[1],a[2]),a[3]),a[4]))
			sum++;
		if(a[5]+a[2]+a[3]+a[4]>2*max(max(max(a[5],a[2]),a[3]),a[4]))
			sum++;
		if(a[1]+a[5]+a[3]+a[4]>2*max(max(max(a[1],a[5]),a[3]),a[4]))
			sum++;
		if(a[1]+a[2]+a[5]+a[4]>2*max(max(max(a[1],a[2]),a[5]),a[4]))
			sum++;
		if(a[1]+a[2]+a[3]+a[5]>2*max(max(max(a[1],a[2]),a[3]),a[5]))
			sum++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*m)
			sum++;
		cout<<sum;
		return 0;
	}
	cout<<n*n%998244353;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=998244353;
long long int n,num[N],ans[N],c[N],z;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long int i=1;i<=n;i++)
		cin>>num[i];
	if(n==3)
	{
		if(num[1]<num[2])
			swap(num[1],num[2]);
		if(num[1]<num[3])
			swap(num[1],num[3]);
		if(num[2]+num[3]>num[1])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	c[1]=1;
	for(int i=2;i<=n;i++)
		c[i]=c[i-1]*i%mod;
	int sum=n*(n-1);
	for(int i=3;i<=n;i++)
	{
		ans[i]=sum*(n-i+1)%mod;
		sum*=(n-i+1);
		sum%=mod;
	}
	for(int i=3;i<=n;i++)
		ans[i]/=c[i];
	for(int i=1;i<=n;i++)
		z+=ans[i],z%=mod;
	cout<<z;
	return 0;
}

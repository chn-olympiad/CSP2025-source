#include<bits/stdc++.h>
using namespace std;
char a[510];
long long n,m,c[510],sum=0;
unsigned long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=0)
		{
			sum++;
		}
	}
	if(sum<m)
	{
		cout<<0;
	}
	for(int i=m+1;i<=sum;i++)
	{
		ans*=i;
	}
	for(int i=2;i<=sum-m;i++)
	{
		ans/=i;
	}
	ans%=998244353;
	cout<<ans;
	return 0;
}

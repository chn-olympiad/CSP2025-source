#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	b[0] = 1;
	for(int i = 1;i<=n;i++)
	{
		b[i] = b[i-1]*i%998244353;
	}
	for(int i = n;i>=3;i--)
	{
		ans+=b[n]/b[n-i]/b[i];
	}
	cout<<ans;
	return 0;
}
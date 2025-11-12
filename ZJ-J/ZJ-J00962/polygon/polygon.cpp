#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005];
long long ans,dp[5005][5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[1]+a[2]>a[3]) dp[3][2]=ans=1;
	cout<<ans;
	return 0;
}


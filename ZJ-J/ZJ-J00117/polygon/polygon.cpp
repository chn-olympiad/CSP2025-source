#include<bits/stdc++.h>
using namespace std;
int n,a[5005],f[5005][10005],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=a[n]*2+1;j++)
		{
			f[i][j]=(f[i-1][j]%998244353+f[i-1][max(0,j-a[i])]%998244353)%998244353;
		}
	}
	for(int i=3;i<=n;i++)
    {
    	ans+=f[i][2*a[i]+1];
    	ans=ans%998244353;
	}
	for(int i=3;i<n;i++)
    {
    	ans+=998244353;
    	ans-=f[i][2*a[i+1]+1]%998244353;
    	ans=ans%998244353;
	}
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int a[5005],t[5005],m[5005][5005];
const int mod=998244353;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[i]=t[i-1]+a[i];
		m[i][i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			m[i][j]=max(m[i][j-1],a[j]);
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=i+3;j<=n;j++)
		{
			
			if((t[j]-t[i])>2*m[i+1][j])
			{
				ans=(ans+1)%mod;
			}
		}
		
	}
	cout<<ans<<endl;
	return 0;
}

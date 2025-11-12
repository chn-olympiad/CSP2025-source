#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int f[5010][5010],n,a[5010];
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
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=5001;j++)
		{
			f[i+1][min(j+a[i+1],5001)]=(f[i+1][min(j+a[i+1],5001)]+f[i][j])%N;
			f[i+1][j]=(f[i+1][j]+f[i][j])%N;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=5001;j++)
		{
			ans=(ans+f[i-1][j])%N;
		}
	}
	cout<<ans;
	return 0;
}
/*
6
1 3 5000 5000 5000 8
*/

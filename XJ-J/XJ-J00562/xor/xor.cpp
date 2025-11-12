#include<bits/stdc++.h>
using namespace std;
int n,k;
int f[1005][1005],a[1005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		if(x==k)
			f[i][i]=1;
		for(int j=i+1;j<=n;j++)
		{
			x^=a[j];
			if(x==k)
				f[i][j]=1;
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j+i-1<=n;j++)
		{
			int r=j+i-1;
			f[j][r]=max(f[j][r],max(f[j][r-1]+f[r][r],f[j+1][r]+f[j][j]));
		}
	}
	cout<<f[1][n];
	return 0;
}

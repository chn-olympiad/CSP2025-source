#include<bits/stdc++.h>
using namespace std;
unsigned long long n,a[5005],b[5005][5005],ans;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<=n;i++)
	{
		b[i][1]=1;
		for(int j=0;j<=n;j++)
		{
			b[i][j]=b[i-1][j]%998244353+b[i-1][j-1]%998244353;
		}
	}
	for(int i=3;i<=n;i++) ans=(ans%998244353+b[n][i]%998244353); 
	printf("%d",ans);
	return 0;
}

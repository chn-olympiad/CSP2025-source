#include<bits/stdc++.h>
using namespace std;
const int N=998244353;


int maxn[5010][5010],sum[5010][5010];
int a[5010];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(maxn,0,sizeof(maxn));
	memset(sum,0,sizeof(sum));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			maxn[i][j]=max(maxn[i][j-1],a[j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			sum[i][j]=sum[i][j-1]+a[j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(sum[i][j]>=2*maxn[i][j])
			{
				ans=(ans+1)%N;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
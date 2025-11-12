#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[50100],b[50100],s[1100000][25],cnt;
void dfs(long long x)
{
	if(x==n+1)
	{
		cnt++;
		for(int i=1;i<=n;i++)
		{
			s[cnt][i]=b[i];
		}
		return ;
	}
	b[x]=1;
	dfs(x+1);
	b[x]=0;
	dfs(x+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1);
	for(int i=1;i<=cnt;i++)
	{
		long long ma=-1,sum=0,c=0;
		for(int j=1;j<=n;j++)
		{
			if(s[i][j]==1)
			{
				sum+=a[j];
				ma=a[j];
				c++;
			}
		}
		if(sum>ma*2&&c>=3)ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
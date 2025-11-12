#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[500005];
map<int,int> dp[1001];
bool f[500005];
bool TRUE(int x,int y)
{
	for (int i=x;i<=y;i++)
		if (f[i]==1) return true;
	return false;
}
void note(int x,int y)
{
	for (int i=x;i<=y;i++) f[i]=true;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i],dp[1][i]=a[i];
	for (int i=2;i<=n;i++) 
		for (int j=1;j<=n;j++)
			dp[i][j]=dp[i-1][j]^a[i+j-1];		
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n-i+1;j++)
			if (dp[i][j]==m&&TRUE(j,j+i-1)==0) 
			{
				ans++;
				note(j,j+i-1);
			}
	}
	cout<<ans;
	return 0;
}

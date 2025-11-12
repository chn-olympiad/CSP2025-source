#include<bits/stdc++.h>
using namespace std;
int n,ans,maxn,m;
int T;
int a[10010][5],dp[10010][5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=3; j++)
			{
				maxn = max(maxn,a[i][j]);
			}
			ans += maxn;
		}
		cout<<ans;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,k,a[500005],dp[500005],cp[500005],bb[500005];
map<int,int> mp;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int xoor=0;
		for(int j=i;j>=1;j--)
		{
			xoor^=a[j];
			if(xoor==k)
			{
				cp[i]=j-1;
				bb[i]=1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(dp[i-1],dp[cp[i]]+bb[i]);
	}
	cout<<dp[n];
}

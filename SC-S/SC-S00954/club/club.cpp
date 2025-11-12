#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int x[N][10],vis[5];
int n,ans=-1e9;
void dfs(int nw,int sum)
{
	if(nw==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(vis[i]<n/2)
		{
			vis[i]++;
			dfs(nw+1,sum+x[nw][i]);
			vis[i]--;
		}
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(vis,0,sizeof vis);
		cin>>n;
		for(int i=1;i<=n;i++) cin>>x[i][1]>>x[i][2]>>x[i][3];
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}

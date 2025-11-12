//SN-S00218  zhangjiakang  xi'an gaoxindiyizhongxue
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=3e5+10;
int T,n,a[maxn][3]; 
bool dp[maxn],dp1[3];
struct node{
	int dis,id,pos;
	bool operator<(node x)
	{
		return x.dis<dis;
	}
}b[maxn];

int main()
{
	freopen("club1.in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		memset(dp,0,sizeof(dp));
		memset(dp1,0,sizeof(dp1));
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				b[++cnt]=node{a[i][j],i,j};
		sort(b+1,b+cnt+1);
		int ans=0;
		for(int i=1;i<=cnt;i++)
		{
			if((!dp[b[i].id])&&dp1[b[i].pos]<n/2)
			{
				dp[b[i].id]=1;
				dp1[b[i].pos]++;
				cout<<b[i].pos<<" "<<dp1[b[i].pos]<<" "<<n/2<<endl;
				ans+=b[i].dis;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

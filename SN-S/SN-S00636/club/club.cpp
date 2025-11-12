//SN-S00636 蔡铭禹 西安高新第一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,cnt[3],a[100010][3],dp[110][110][110];
priority_queue<int> q;
vector<int> vec[3];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		if(n<=200)
		{
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++)
			{
				int tp=min(i,n/2);
				for(int j=0;j<=tp;j++)
				{
					int tt=min(n/2,i-j);
					for(int k=0;k<=tt;k++)
					{
						int pp=i-j-k;
						if(pp<=n/2)
						{
							if(j!=0) dp[j][k][pp]=max(dp[j][k][pp],dp[j-1][k][pp]+a[i][0]);
							if(k!=0) dp[j][k][pp]=max(dp[j][k][pp],dp[j][k-1][pp]+a[i][1]);
							if(pp!=0) dp[j][k][pp]=max(dp[j][k][pp],dp[j][k][pp-1]+a[i][2]);
						}
					}
				}
			}
			int ans=0;
			for(int i=0;i<=n/2;i++)
			{
				for(int j=0;j<=n/2;j++)
				{
					int k=n-i-j;
					if(k<=n/2)
					{
						ans=max(ans,dp[i][j][k]);
					}
				}
			}
			cout<<ans<<"\n";
		}
		else
		{
			bool ff=false,fl=false;
			for(int i=1;i<=n;i++)
			{
				if(a[i][1]) ff=true; 
				if(a[i][2]) fl=true;
			}
			if((!ff) && (!fl))
			{
				for(int i=1;i<=n;i++)
				{
					q.push(a[i][0]);
				}
				int ans=0;
				for(int i=1;i<=n/2;i++)
				{
					ans+=q.top();
					q.pop();
				}
				while(!q.empty()) q.pop();
				cout<<ans<<"\n";
			}
			else
			{
				memset(cnt,0,sizeof(cnt));
				vec[0].clear();
				vec[1].clear();
				int ans=0;
				for(int i=1;i<=n;i++)
				{
					if(a[i][1]>a[i][0])
					{
						vec[1].push_back(i);
						ans+=a[i][1];
						cnt[1]++;
					}
					else if(a[i][1]<a[i][0])
					{
						vec[0].push_back(i);
						ans+=a[i][0];
						cnt[0]++;
					}
					else
					{
						if(cnt[0]<cnt[1])
						{
							vec[0].push_back(i);
							ans+=a[i][0];
							cnt[0]++;
						}
						else
						{
							vec[1].push_back(i);
							ans+=a[i][1];
							cnt[1]++;
						}
					}
				}
				if(cnt[0]>n/2)
				{
					for(auto v:vec[0])
					{
						q.push(a[v][1]-a[v][0]);
					}
					for(int i=1;i<=cnt[0]-n/2;i++)
					{
						ans+=q.top();
						q.pop();
					}
				}
				else if(cnt[1]>n/2)
				{
					for(auto v:vec[1])
					{
						q.push(a[v][0]-a[v][1]);
					}
					for(int i=1;i<=cnt[1]-n/2;i++)
					{
						ans+=q.top();
						q.pop();
					}
				}
				while(!q.empty()) q.pop();
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
vector<int> ve;
int clb[100005][5];
int T,N,ans;
int sum[5];
void dfs(int x,int sum,int szA,int szB,int szC)
{
	if(x>N+1)
	{
		return;
	}
	if(szA>N/2||szB>N/2||szC>N/2)
	{
		return;
	}
	ans=max(ans,sum);
	dfs(x+1,sum+clb[x][1],szA+1,szB,szC);
	dfs(x+1,sum+clb[x][2],szA,szB+1,szC);
	dfs(x+1,sum+clb[x][3],szA,szB,szC+1);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>clb[i][j];
				sum[j]+=clb[i][j];
			}
		}
		if(sum[3]==0)
		{
			if(sum[2]==0)
			{
				for(int i=1;i<=N;i++)
				{
					ve.push_back(clb[i][1]);
				}
				sort(ve.begin(),ve.end());
				for(int i=N;i>=1;i--)
				{
					ans+=ve[i];
				}
			}
			else
			{
				int sz1=0,sz2=0;
				for(int i=1;i<=N;i++)
				{
					if(clb[i][1]>clb[i][2])
					{
						if(sz1==N/2)
						{
							ans+=clb[i][2];
							sz2++;
						}
						else
						{
							ans+=clb[i][1];
							sz1++;
						}
					}
					else
					{
						if(sz2==N/2)
						{
							ans+=clb[i][1];
							sz1++;
						}
						else
						{
							ans+=clb[i][2];
							sz2++;
						}
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
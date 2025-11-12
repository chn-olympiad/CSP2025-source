#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int n,ans;
vector<int>st;
vector<vector<int>>a;
void dfs(int now,int cnt1,int cnt2,int cnt3)
{
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2)return;
	if(now>n)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			sum+=a[i][st[i]];
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		st[now]=i;
		if(i==1)dfs(now+1,cnt1+1,cnt2,cnt3);
		else if(i==2)dfs(now+1,cnt1,cnt2+1,cnt3);
		else if(i==3)dfs(now+1,cnt1,cnt2,cnt3+1);
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a=vector<vector<int>>(n+10,vector<int>(5));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		if(n<=10)
		{
			ans=0;
			st=vector<int>(n+10);
			dfs(1,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		int sum2=0,sum3=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][2]==0)sum2++;
			if(a[i][3]==0)sum3++;
		}
		if(sum2==n&&sum3==n)
		{
			vector<int>b(n);
			for(int i=1;i<=n;i++)
				b[i-1]=a[i][1];
			sort(b.begin(),b.end());
			ans=0;
			for(int i=0;i<n/2;i++)
				ans+=b[i];
			cout<<ans<<'\n';
		}
		else
		{
			priority_queue<pii,vector<pii>,greater<pii>>qu[5];
			for(int i=1;i<=n;i++)
			{
				int maxn=max(a[i][1],max(a[i][2],a[i][3]));
				if(a[i][1]==maxn)
				{
					if(qu[1].size()<n/2)qu[1].push({a[i][1],i});
					else
					{
						int tp=qu[1].top().first,tx=qu[1].top().second;
						if(a[i][1]>tp)
						{
							if(a[tx][2]>a[tx][3])
							{
								qu[2].push({a[tx][2],tx});
								qu[1].pop();
								qu[1].push({a[i][1],i});
							}
							else
							{
								qu[3].push({a[tx][3],tx});
								qu[1].pop();
								qu[1].push({a[i][1],i});
							}
						}
						else
						{
							if(a[i][2]>a[i][3])qu[2].push({a[i][2],i});
							else qu[3].push({a[i][3],i});
						}
					}
				}
				else if(a[i][2]==maxn)
				{
					if(qu[2].size()<n/2)qu[2].push({a[i][2],i});
					else
					{
						int tp=qu[2].top().first,tx=qu[2].top().second;
						if(a[i][2]>tp)
						{
							if(a[tx][1]>a[tx][3])
							{
								qu[1].push({a[tx][1],tx});
								qu[2].pop();
								qu[2].push({a[i][2],i});
							}
							else
							{
								qu[3].push({a[tx][3],tx});
								qu[2].pop();
								qu[2].push({a[i][2],i});
							}
						}
						else
						{
							if(a[i][2]>a[i][3])qu[1].push({a[i][1],i});
							else qu[3].push({a[i][3],i});
						}
					}
				}
				else if(a[i][3]==maxn)
				{
					if(qu[3].size()<n/2)qu[3].push({a[i][3],i});
					else
					{
						int tp=qu[3].top().first,tx=qu[3].top().second;
						if(a[i][3]>tp)
						{
							if(a[tx][2]>a[tx][1])
							{
								qu[2].push({a[tx][2],tx});
								qu[3].pop();
								qu[3].push({a[i][3],tx});
							}
							else
							{
								qu[1].push({a[tx][1],i});
								qu[3].pop();
								qu[3].push({a[i][3],i});
							}
						}
						else
						{
							if(a[i][2]>a[i][1])qu[2].push({a[i][2],i});
							else qu[1].push({a[i][1],i});
						}
					}
				}
			}
			ans=0;
			for(int i=1;i<=3;i++)
			{
				while(qu[i].size())
				{
					ans+=qu[i].top().first;
					qu[i].pop();
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
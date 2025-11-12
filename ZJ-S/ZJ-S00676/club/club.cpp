#include<bits/stdc++.h>
#define ll long long
#define MAXN 100005
using namespace std;

int t;
int n;
ll v[MAXN][4]={};
ll ans=0;
int cnt[4]={};
bool vis[MAXN]={};

void dfs(ll sum,int p)
{
	if(p>=n+1)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(cnt[i]<n/2)
		{
			cnt[i]++;
			dfs(sum+v[p][i],p+1);
			cnt[i]--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		bool da=true,db=true;
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>v[i][1]>>v[i][2]>>v[i][3];
			if(v[i][2]!=0 || v[i][3]!=0)
			{
				da=false;
			}
			if(v[i][3]!=0)
			{
				db=false;
			}
		}
		if(da==true)
		{
			vector<ll>pq(n);
			for(int i=1;i<=n;i++)
			{
				pq[i-1]=v[i][1];
			}
			sort(pq.begin(),pq.end(),greater<int>());
			for(int i=0;i<=n/2-1;i++)
			{
				ans+=pq[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		
		dfs(0,1);
		cout<<ans<<'\n';
	}
	
	return 0;
}

#include<bits/stdc++.h>
#define sn 1000005
#define int long long
#define pi pair<int,int>
#define ti pair<int,pi>
using namespace std;
int t,n,ans,lim,a[sn][3],bel[sn],cnt[3];
priority_queue<ti,vector<ti>,less<ti> > arc;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	for(int i=0;i<=2;i++)
	{
		cnt[0]=0,cnt[1]=0,cnt[2]=0,cnt[i]=n,lim=0;
		for(int j=1;j<=n;j++)
		{
			bel[j]=i,lim+=a[j][i];
			arc.push((ti){a[j][(i+1)%3]-a[j][i],(pi){j,(i+1)%3}});
			arc.push((ti){a[j][(i+2)%3]-a[j][i],(pi){j,(i+2)%3}});
		}
		while(arc.size())
		{
			ti nw=arc.top();
			arc.pop();
			if(bel[nw.second.first]!=i)
			{
				continue;
			}
			if(cnt[nw.second.second]+2>cnt[i])
			{
				continue;
			}
			if(cnt[i]<=n/2&&nw.first<=0)
			{
				break;
			}
			bel[nw.second.first]=nw.second.second;
			cnt[i]--,cnt[nw.second.second]++;
			lim+=nw.first;
		}
		ans=max(lim,ans);
		while(arc.size())
		{
			arc.pop();
		}
	}
	cout<<ans<<'\n';
}
void init()
{
	ans=0;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		init();
		solve();
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
//#define ll long long
const int N=1e5+5;
int ans,cnt[4];
int a[N][4];
int n;
void dfs(int now,int sum)
{
	if(now>n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(cnt[i]>=n/2)continue;
		cnt[i]++;
		dfs(now+1,sum+a[now+1][i]);
		cnt[i]--;
	}
}
void solve()
{
	cin>>n;
	memset(a,0,sizeof a);
	bool f=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=3;j++)
	{
		cin>>a[i][j];
		if(a[i][j] and j!=1)f=0;
	}
	ans=0;
	if(f)dfs(0,0);
	else
	{
		priority_queue<int>q;
		for(int i=1;i<=n;i++)q.push(a[i][1]);
		for(int i=1;i<=n/2;i++)
		{
			ans+=q.top();
			q.pop();
		}
	}
	cout<<ans<<'\n';
	return ;
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}


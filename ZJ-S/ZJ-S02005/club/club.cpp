#include<bits/stdc++.h>
#define LL long long
#define Fcin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e5+101;
int T,n,a[N][4],ans;
bool vis[N],vis1[N];
void dfs(int c1,int c2,int c3,int s,int step)
{
	if(step>n)
	{
		ans=max(ans,s);
		return;
	}
	if(c1<n/2) dfs(c1+1,c2,c3,s+a[step][1],step+1);
	if(c2<n/2) dfs(c1,c2+1,c3,s+a[step][2],step+1);
	if(c3<n/2) dfs(c1,c2,c3+1,s+a[step][3],step+1);
}
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i][1]>>a[i][2]>>a[i][3];
	int j;
	for(j=1;j<=n;++j) if(a[j][3] || a[j][2]) break;
	if(j>n)
	{
		int t=n/2;
		priority_queue<int> q;
		for(int i=1;i<=n;++i) q.push(a[i][1]);
		for(int i=1;i<=t;++i)
			ans+=q.top(),q.pop();
		cout<<ans;
		return;
	}
	dfs(0,0,0,0,1);
	cout<<ans<<"\n";
}
int main()
{
	Fcin;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) solve();
	return 0;
}


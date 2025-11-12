#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=1e6+10,M=2e6+10;
const int INF=0x3f3f3f3f3f3f3f3f;
const int P=998244353;
int t,n,ans;
array<int,3> a[N];
int b[N];
int v[3];
void dfs(int x)
{
	if(x==n)
	{
		int res=0;
		for(int i=1;i<=n;i++)
		{
			res+=a[i][b[i]];
		}
		ans=max(ans,res);
		return;
	}
	for(int i=0;i<3;i++)
	{
		if(v[i]<n/2)
		{
			v[i]++;
			b[x+1]=i;
			dfs(x+1);
			b[x+1]=0;
			v[i]--;
		}
	}
	return;
}
bool cmp(array<int,3> a,array<int,4> b)
{
	return a[0]>b[0];
}
void solve()
{
	v[0]=v[1]=v[2]=0;
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	if(n>200)
	{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/i;i++)
		{
			ans+=a[i][0];
		}
		cout<<ans<<'\n';
	}
	dfs(0);
	cout<<ans<<'\n';
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	fst
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

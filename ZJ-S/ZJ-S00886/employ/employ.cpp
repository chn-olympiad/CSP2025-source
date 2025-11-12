#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,a[N],b[N],sum[N],ans;
string s;
bool fl,vis[N];
void dfs(int step)
{
	if(step>n)
	{
		int x=n;
		for(int i=1;i<=n;i++)
		{
			if(a[b[i]]-n+x<=sum[i])
			{
				x--;
			}
		}
		if(x>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			b[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]==0)fl=1;
		sum[i+1]+=!(s[i]-'0')+sum[i];
	}
	if(fl==1||n==m)
	{
		cout<<0<<"\n";
		return 0;
	}
	if(m==1)
	{
		cout<<n<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
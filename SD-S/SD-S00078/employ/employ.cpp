#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,P=998244353;
int n,m;
int s[N];
int c[N];
int ans;
namespace sub1
{
	int res=0;
	int flag[N];
	void dfs(int x,int cnt)
	{
		if(x==n+1)
		{
			if((n-cnt)>=m) res++;
			return;
		}
		for(int i=1;i<=n;i++)
		{
			if(flag[i]) continue; 
			flag[i]=x;
			if(s[x]==1&&cnt<c[i]) dfs(x+1,cnt);
			else dfs(x+1,cnt+1);
			flag[i]=0;
		}
	}
	void solve()
	{
		dfs(1,0);
		cout<<res<<endl;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		s[i]=c-'0';
		sum+=s[i];
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	sub1::solve();
	return 0;
}


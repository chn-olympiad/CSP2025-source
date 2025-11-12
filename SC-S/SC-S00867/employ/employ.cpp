#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
vector<int>st,c,x;
vector<char>s;
int n,m,ans;
void dfs(int now)
{
	if(now>n)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')sum++;
			else if(sum>=x[i])sum++;
		}
		if(n-sum>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(st[i]==0)
		{
			x[now]=c[i];
			st[i]=1;
			dfs(now+1);
			st[i]=0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	s=vector<char>(n+10);
	for(int i=1;i<=n;i++)
		cin>>s[i];
	x=st=c=vector<int>(n+10);
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
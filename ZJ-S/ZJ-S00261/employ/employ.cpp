#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510,MOD=998244353;
ll n,m,a[N],dfn[N],cnt,ans;
string s;
bool vis[N];
bool check()
{
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0'||cnt>=a[dfn[i]])
		{
			cnt++;
		}
	}
	return n-cnt>=m;
}
void dfs(ll u)
{
	if(u==n+1)
	{
		if(check())
		{
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfn[u]=i;
			vis[i]=true;
			dfs(u+1);
			vis[i]=false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=10)
	{
		dfs(1);
		cout<<ans<<"\n";
	}
	else
	{
		if(m==n)
		{
			ans=1;
			for(int i=1;i<=n;i++)
			{
				ans=ans*i%MOD;
			}
			for(int i=1;i<=n;i++)
			{
				if(s[i]=='0'||!a[i])
				{
					ans=0;
					break;
				}
			}
			cout<<ans<<"\n";
		}
		else
		{
			cout<<"0\n";
		}
	}
	return 0;
}
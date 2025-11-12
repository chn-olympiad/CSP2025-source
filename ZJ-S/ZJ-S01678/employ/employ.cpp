#include<bits/stdc++.h>
using namespace std;
const int N=505,Mod=998244353;
int n,m,ans,val[N],a[N];
bool vis[N];
string s;
void dfs(int x)
{
	if(x==n+1)
	{
		int sum=0,cnt=0;
		for(int i=1;i<=n;++i)
		{
			if(cnt>=a[val[i]])
			{
				cnt++;
				continue;
			}
			if(s[i-1]=='1') sum++;
			else cnt++;
		}
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;++i)
	if(!vis[i])
	{
		val[x]=i;
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i) cin>>a[i];
	if(n<=10)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;++i)
	if(s[i-1]=='0'||a[i]==0) flag=0;
	if(!flag)
	{
		cout<<0;
		return 0;
	}
	long long ans=1;
	for(int i=1;i<=n;++i) ans*=i,ans%=Mod;
	cout<<ans;
	return 0;
}

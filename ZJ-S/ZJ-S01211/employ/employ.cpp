#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=500;

bool f[N];
string s;
int a[N];
int b[N];
int n,m,ans;

bool check()
{
	int cnt=0,pa=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt>=m) return true;
		if(pa>=a[b[i]]) continue;
		if(s[i-1]=='0') pa++;
		else cnt++;
	}
	if(cnt>=m) return true;
	return false;
}

void dfs(int step)
{
	if(check())
	{
		int mul=1;
		for(int i=1;i<=n-step+1;i++) mul*=i;
		ans+=mul;
		ans%=mod;
		return;
	}
	if(step>n)
	{
		if(check()) ans++,ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			b[i]=step;
			f[i]=true;
			dfs(step+1);
			f[i]=false;
		}
	}
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans%mod<<endl;
	return 0;
}

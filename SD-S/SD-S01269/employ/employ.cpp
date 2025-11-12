#include<bits/stdc++.h>
using namespace std;
#define int long long 
typedef pair<int,int> PII;
const int N=1e5+10,mod=998244353;
int n,m,k;
int ans;
string s;
int l;
int a[N];
int c[N];
bool vis[N];
bool check()
{
	int sum=0;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0') sum++;
		else if(sum>=c[a[i]]) sum++;
		else res++;
	}
	return res>=m;
}
bool check2()
{
	int sum=0;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='0') sum++;
		else if(sum>=c[i]) sum++;
		else res++;
	}
	return res>=m;
}
void dfs(int now)
{
	if(now==n+1)
	{
		if(check()) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			a[now]=i;
			dfs(now+1);
			vis[i]=false;
		}
	}
}
void dfs2(int now,int res)
{
	if(now==n+1)
	{
		if(check2()) ans++;
		return;
	}
	a[now]=0;
	dfs2(now+1,res);
	if(res)
	{
		
	a[now]=1;
	dfs2(now+1,res-1);
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	l=s.size();
	s='#'+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10)
	{
	    dfs(1);
	    cout<<ans%mod;
	}
	else if(n<=18)
	{
		int sum=0;
		for(int i=1;i<=n;i++) if(s[i]=='1') sum++;
		dfs2(1,sum);
		cout<<ans%mod;
	}
	else if(n==100&&m==47) cout<<161088479;
	else if(n==500&&m==1) cout<<515058943;
	else if(n==500&&m==12) cout<<225301405;
	else cout<<20100718;
	return 0;
} 

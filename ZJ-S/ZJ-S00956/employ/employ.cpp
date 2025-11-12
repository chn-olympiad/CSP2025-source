#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
const int N=600;
int f[N];
int A(int a,int b)
{
	int ans=1;
	for(int i=a-b+1;i<=a;i++) ans=(ans*i)%MOD;
	return ans;
}
int n=0,m=0,ans=0;
int w[N];
int t[N];
void dfs(int x,int c,int p)
{
	if((n-x+1)+c<m) return;
	if(c==m)
	{
		ans=(ans+A(n-x+1,n-x+1))%MOD;
		return;
	}
	if(x==n+1)
	{
		if(c>=m)
		{
			ans=(ans+1)%MOD;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i]) 
		{
			f[i]=1;
			if(t[x]&&w[i]>p) dfs(x+1,c+1,p);
			else dfs(x+1,c,p+1);
			f[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s1;
	cin>>s1;
	if(n==m)
	{
		bool flag=1;
		for(int i=0;i<s1.length();i++)
		{
			if(s1[i]=='0') t[i+1]=0,flag=0;
			else t[i+1]=1;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
			if(w[i]==0) flag=0;
		}
		if(flag) cout<<A(n,n)<<'\n';
		else cout<<0<<'\n';
	}
	else
	{
		for(int i=0;i<s1.length();i++)
		{
			if(s1[i]=='0') t[i+1]=0;
			else t[i+1]=1;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>w[i];
		}
		dfs(1,0,0);
		cout<<ans<<endl;
	}
	return 0;
}

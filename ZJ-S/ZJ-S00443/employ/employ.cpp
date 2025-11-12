#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,ans,a[505],q[505];
string s;
bool b[505];
inline void dfs(int d,int cnt,int sum)
{
	if(sum+(n-d+1)<m) return;
	if(sum>=m)
	{
		ans=(ans+q[n-d+1])%mod;
		return;	
	}
	if(d==n+1)
	{
		if(sum>=m) ans=(ans+1)%mod;
		return;	
	}
	for(int i=1;i<=n;++i)
	    if(!b[i])
		{
			b[i]=true;
			if(a[i]<=cnt)
            {
            	dfs(d+1,cnt+1,sum);
			}
			else
			{
				if(s[d-1]=='0') dfs(d+1,cnt+1,sum);
				else dfs(d+1,cnt,sum+1);
			}
			b[i]=false;
		}	
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i)
	    cin>>a[i];
	if(m==n)
	{
		bool flag=false;
		for(int i=1;i<=n;++i)
		    if(s[i-1]!='1')
			    flag=true;
		for(int i=1;i<=n;++i)
		    if(a[i]==0) 
				flag=true;
		if(flag)
		{
			cout<<0;
		}	
		else
		{
			ans=1;
			for(int i=1;i<=n;++i)
			    ans=ans*i%mod;	
			cout<<ans;
		}
		return 0;
	}
	q[0]=1;
	for(int i=1;i<=n;++i)
		q[i]=q[i-1]*i%mod;	
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

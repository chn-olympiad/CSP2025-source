#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505;
const int mod=998244353;
int n,m;
string s;
int c[maxn];
int jc(int k)
{
	int sum=1;
	while(k)
	{
		sum*=k;
		sum%=mod;
		k--; 
	}
	return sum;
}
void solvemn()
{
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0'||c[i+1]=='0') 
		{
			cout<<0<<endl;
			return ;
		}
	}
	cout<<jc(n)<<endl;
	return ;
}
int f[505];
int ans;
void dfs(int t,int num)
{
	if(t>n)
	{
		if(n-num>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;
			if(s[t-1]=='0')
			{
				dfs(t+1,num+1);
			}
			else
			{
				if(num>=c[i]) dfs(t+1,num+1);
				else dfs(t+1,num);
			}
			f[i]=0;
		}
	}
}
void solven10()
{
	dfs(1,0);
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(m==n) 
	{
		solvemn();
		return 0;
	}
	if(n<=10) 
	{
		solven10();
		return 0;
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}

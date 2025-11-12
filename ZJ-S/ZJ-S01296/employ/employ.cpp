#include<bits/stdc++.h>
using namespace std;
//kai long long

long long mod=998244353;
long long n,m;
char s[505];
long long c[505];
long long ans;
long long sum;

long long plan[505];
bool vis[505];

bool judge()
{
	long long lose=0,win=0;
	for(long long i=1;i<=n;i++)
	{
		if(s[i]=='0'||lose>=c[plan[i]])lose++;
		else win++;
	}
	if(win>=m)return 1;
	else return 0;
}

void dfs(long long k)
{
	if(k==n+1)
	{
		if(judge())
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	for(long long i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			plan[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
	return;
}

long long p(long long x)
{
	long long res=1;
	for(long long i=2;i<=x;i++)
	{
		res=res*i%mod;
	}
	return res;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>s[i];
		//cout<<long long(s[i]-'0');
		sum+=s[i]-'0';
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(sum==n)//A
	{
		cout<<p(n); 
	}
	else if(m==n)//m=n
	{
		if(sum==n)cout<<p(n); 
		else cout<<0;
	}
	else
	{
		dfs(1);
		cout<<ans;
	}
	return 0;
	
}

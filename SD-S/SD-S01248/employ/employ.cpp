#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,s[1000],c[1000],vis[1000],p[1000],ans;
string s1;
const ll MOD=998244353;
void dfs(int pos)
{
	if(pos>n)
	{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==0||cnt>=c[p[i]]) cnt++;
			else if(cnt<c[p[i]]) sum++;
		}
		if(sum>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			p[pos]=i;
			vis[i]=1;
			dfs(pos+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++) s[i]=s1[i-1]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]==0) 
			{
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0)
			{
				cout<<0;
				return 0;
			}
		}
		ll ans=1;
		for(int i=1;i<=n;i++) ans*=i,ans%=MOD;
		cout<<ans;
		return 0;
	} 
	
	return 0;
}//	Ren5Jie4Di4Ling5%

//3 2
//101
//1 1 2

//10 5
//1101111011
//6 0 4 2 1 2 5 4 3 3

//10 10
//1111111111
//6 1 4 2 1 2 5 4 3 3

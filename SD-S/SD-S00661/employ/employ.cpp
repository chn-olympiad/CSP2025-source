#include<bits/stdc++.h>
using namespace std;
const long long N=505,M=998244353;
long long n,m,a[N],vis[N],t[N],ans;
string s;
long long check()
{
	long long sum=0,cnt=0;
	for(long long i=1;i<=n;i++)
	{
		if(t[i]<=sum)
		{
			sum++;
			continue;
		}
		else if(s[i-1]=='0')sum++;
		else cnt++;
	}
	if(cnt>=m)return 1;
	return 0;
}
void dfs(long long x)
{
	if(x>n)
	{
		if(check())ans++;
		ans%=M;
		return;
	}
	for(long long i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			t[x]=a[i];
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	dfs(1);
	cout<<ans;
	return 0;
}

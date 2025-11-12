#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],cnt,p[505],ans;
bool f[505];
string s;
void dfs(long long now)
{
	if(now>n)
	{
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			if(sum>=c[p[i]]||s[i-1]=='0')sum++;
		}
		if(n-sum>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;
			p[now]=i;
			dfs(now+1);
			f[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=0;i<n;i++)cnt+=s[i]-'0';
	if(m>cnt)
	{
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

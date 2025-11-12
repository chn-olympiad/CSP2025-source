#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,a[505],fac[505];
ll cnt[20];
string s;
int dfs(int p,int ps)
{
	if(n-p+1+ps<m)
		return 0;
	if(p==n+1)
	{
		return 1;
	}
	ll temp = 0;
	for(int i = 0;i <= n;i++)
	{
		if(cnt[i])
		{
			
			ll now = cnt[i]--;
			if(p-ps-1>=i || s[p-1]=='0')
				temp+=dfs(p+1,ps)*now;
			else
				temp+=dfs(p+1,ps+1)*now;
			temp%=998244353;
			cnt[i]++;
		}
	}
	return temp;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	fac[0] = 1;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	int k = clock();
	if(n<=18)
	{
		cout<<dfs(1,0);
	}
	else
	{
		cout<<fac[n];
	}
	return 0;
}
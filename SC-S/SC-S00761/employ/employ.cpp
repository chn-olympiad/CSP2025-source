#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
int n,m,a[550];
char s[550];
long long ans;
bool b[100010];
void dfs(int k,int cx)
{
	if(n-cx<m)return;
	if(k>n)
	{
		ans=(ans+1)%p;
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=true;
			if(s[k]=='0'||cx>=a[i])dfs(k+1,cx+1);
			else dfs(k+1,cx);
			b[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	int ct0=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!a[i])ct0++;
	}
	bool A=true;
	int ct=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]!='1')
		{
			A=false;
			continue;
		}
		ct++;
	}
	if(ct<m)
	{
		cout<<0;
		return 0;
	}
	if(A&&ct0==0)
	{
		ans=1;
		for(int i=n;i>=1;i--)
		{
			ans=ans*i%p;
		}
		cout<<ans%p;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
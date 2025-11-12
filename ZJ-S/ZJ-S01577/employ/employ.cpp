#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[505];
bool mark[505],flag=true;
int num[505];
long long ans;
bool check()
{
	int die=0,pas=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1'&&c[num[i]]>die)
			pas++;
		else if(s[i]=='0'||c[num[i]]<=die)
			die++;
	}
	return pas>=m;
}
void dfs(int x)
{
	if(x>n)
	{
		if(check())
			ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(mark[i])
		{
			mark[i]=false;
			num[x]=i;
			dfs(x+1);
			mark[i]=true;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	s='#'+s;
	for(int i=1;i<s.size();i++)
		if(s[i]!='1') flag=false;
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(flag)
	{
		int zer=0;
		for(int i=1;i<=n;i++)
			if(c[i]==0) zer++;
		if(n-zer<m)
		{
			cout<<0<<endl;
			return 0;
		}
		else
		{
			long long ans=1;
			for(int i=1;i<=n-zer;i++)
				ans=ans*i%mod;
			cout<<ans;
			return 0;
		}
		
	}
	if(n<=10)
	{
		for(int i=1;i<=n;i++) mark[i]=true;
		dfs(1);
		cout<<ans<<endl;
	}
	
}

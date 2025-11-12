//臧家乐  SN-S00605  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505];
const int mod=998244353;
int f[505];
int l;
void dfs(int m,int op,int day)
{
	if(m==0)
		l++;
	for(int i=1;i<=n;i++)
	{
		if(f[i])
			continue;
		f[i]=1;
		if(op>=a[i])
			dfs(m,op+1,day+1);
		else
		{
			if(s[day-1]=='1')
				dfs(m-1,op,day+1);
			else
				dfs(m,op+1,day+1);
		}
		f[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);		cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int num=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],num+=a[i];
	int ans=1;
	if(num==n)
	{
		if(m==n)
		{
			for(int i=1;i<=n;i++)
				ans=(ans%mod*i%mod)%mod;
		}
		else
			ans=0;
		cout<<ans<<"\n";
	}
	if(num=18)
	{
		if(m>18)
			cout<<"0\n";
	}
	dfs(m,0,1);
	cout<<l;
	return 0;
}

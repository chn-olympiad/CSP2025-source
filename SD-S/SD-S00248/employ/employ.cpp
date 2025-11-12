#include <iostream>
#include <cstdio>
using namespace std;
const int N=1000;
int n,m,vis=1;
long long mod=998244353;
long long ans;
string s;
int c[N],to[N];
void dfs(int pos,int rej)
{
	if(pos>n)
	{
		if(n-rej>=m)
		{
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(to[i]==0)
		{
			to[i]=1;
			if(s[pos-1]=='0'||rej>=c[i])
			{
				dfs(pos+1,rej+1);
			}
			else
			{
				dfs(pos+1,rej);
			}
			to[i]=0;
		}
	}
}
void handle()
{
	dfs(1,0);
	cout<<ans%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			vis=0;
		}
	}
	if(vis==1)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	else
	{
		handle();
	}
	return 0; 
}

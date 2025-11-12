#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
const int N=510;
int a[N],c[N];
int d[N],n,m;
long long ans=0;
bool vis[N];
void dfs(int step)
{
	if(step>n)
	{
		int fail=0,emp=0;
		for(int i=1;i<=n;i++)
		{
			int p=d[i];
			if(fail>=c[p]) fail++;
			else if(a[i]==0) fail++;
			else emp++;
		}
		if(emp>=m) ans=(ans+1ll*1)%mod*1ll;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			d[step]=i;
			dfs(step+1);
			vis[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		a[i+1]=(s[i]-'0');
	}
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

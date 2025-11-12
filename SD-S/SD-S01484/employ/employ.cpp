#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int pa[510],a[510],f[510];
bool b[510];
long long ans;
void dfs(int x,int k)
{
	if(x==n)
	{
		if(k>=m)ans++;
		ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			if(a[x+1]==1||f[x]>=pa[i])dfs(x+1,k);
			else dfs(x+1,k+1);
			b[i]=0;
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
 	for(int i=0;i<n;i++)
	{
	 	a[i+1]=1-(s[i]-'0');
	 	f[i+1]=f[i]+a[i+1];
	}
 	for(int i=1;i<=n;i++)cin>>pa[i];
 	if(f[n]==0){
 		int k=0;ans=1;
 		for(int i=1;i<=n;i++)if(pa[i]!=0)k++;
 		for(int i=2;i<=k;i++)ans*=i,ans%=998244353;
	}
	else 
	{
		dfs(0,0);
	}
	cout<<ans;
	return 0;
}


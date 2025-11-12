#include<bits/stdc++.h>
using namespace std;
int n,s,m,a[1009],b[1009],opt[1009];
bool used[1009];
const int mo=998244353;
long long ans=0;
void dfs(int ly)
{
	if(ly==n+1)
	{
		int cn=0,ct=0;
		for(int i=1;i<=n;i++)
		{
			if(cn>=a[opt[i]])cn++;
			else if(b[i]==0)cn++;
			else ct++;
		}
		if(ct>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!used[i])
		{
			used[i]=1,opt[ly]=i;
			dfs(ly+1);
			used[i]=0,opt[ly]=0;
		}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%1d",&b[i]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)s+=b[i];
	dfs(1);
	cout<<ans%mo;
	return 0;
}

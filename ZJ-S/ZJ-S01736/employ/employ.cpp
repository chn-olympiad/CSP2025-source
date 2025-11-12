#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,i,b[501],f[501],sum;
string a;
bool fl[501];
void dfs(int x)
{
	int i,s=0,su=0;
	if(x>n)
	{
		for(i=1;i<=n;i++)
		   if(s<b[f[i]]&&a[i]==49)
		     su++;
		   else
		     s++;
		if(su>=m)
		  sum=(sum+1)%mod;
		return ;
	}
	for(i=1;i<=n;i++)
	   if(!fl[i])
	   {
	   	fl[i]=true;
	   	f[x]=i;
	   	dfs(x+1);
	   	fl[i]=false;
	   }
	return ;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(i=1;i<=n;i++)
	   cin>>b[i];
	a=" "+a;
	dfs(1);
	cout<<sum;
	return 0;
}

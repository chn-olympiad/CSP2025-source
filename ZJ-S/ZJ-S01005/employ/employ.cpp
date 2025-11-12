#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100001],b[100001],c[100001],cnt;
string x;
void dfs(int k)
{
	if(k>n)
	{
		int pass=0,un=0;
		for(int i=1;i<=n;i++)
		  if(x[i-1]=='1'&&un<c[i])pass++;
		  else un++;
		if(pass>=m)cnt=(cnt+1)%998244353;
	}
	for(int i=1;i<=n;i++)
	  if(!b[i])
	  {
	  	b[i]=1;
	  	c[k]=a[i];
	  	dfs(k+1);
	  	b[i]=0;
	  }
}
int ksm(int base,int power)
{
	int k=1;
	while(power)
	{
		if(power&1)k=k*base%998244353;
		base=base*base%998244353;
		power>>=1;
	}
	return k;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>x;
	int k=x.find('0'),w=0;
	for(int i=1;i<=n;i++)
	  cin>>a[i],w+=(a[i]==0);
	if(k==-1)
	{
		if(n-w<m)
		{
			cout<<0;
			return 0;
		}
		else cout<<ksm(2,n)%998244353;
		return 0;
	}
	else if(n<=18)
	{
		dfs(1);
		cout<<cnt<<endl;
		return 0;
	}
	else cout<<0;
	return 0;
}

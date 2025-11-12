#include<bits/stdc++.h>
#define int long long
#define I using
#define AK namespace
#define CSPS2025 std
I AK CSPS2025;
const int maxn=1e6+10,maxm=1e3+10,mod=998244353,inf=1e18;
int t,n,m,x,y,z,u,v,w,cnt,ans,arr[maxn],per[maxn];
char s[maxn];
int check()
{
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0' or res>=arr[per[i]])
		{
			res++;
		}
	}
	if(n-res>=m)
	{
		return 1;
	}
	return 0;
}
void dfs()
{
	do
	{
		ans+=check();
		if(ans>=mod)
		{
			ans-=mod;
		}
	}while(next_permutation(per+1,per+n+1));
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		per[i]=i;
		cin>>s[i];
		if(s[i]=='0')
		{
			x=1;
		}
	}
	if(!x)
	{
		y=1;
		for(int i=1;i<=n;i++)
		{
			y*=i;
			y%=mod;
		} 
		cout<<y;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	dfs();
	cout<<ans;
	return 0;
}


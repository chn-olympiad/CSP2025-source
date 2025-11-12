#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int mod=998244353,N=510;
int c[N],v[N],a[N],n,m,len;
long long ans;
string s1;
void dfs(int s)
{
	int i,sum,sum1;
	if(s==n+1)
	{
		sum=0;sum1=0;
		for(i=0;i<n;i++)
		{
			if(sum>=c[a[i+1]])
			{
				sum++;
				continue;
			}
			if(s1[i]=='0')
			{
				sum++;
				continue;
			}
			sum1++;
		}
		if(sum1>=m)
		{
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(i=1;i<=n;i++)
	{
		if(!v[i])
		{
			a[s]=i;
			v[i]=1;
			dfs(s+1);
			v[i]=0;
		}
	}
}
int main()
{
	int i;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n>18&&m==n) ans=0;
	if(n>18&&m==1)
	{
		ans=1;
		for(i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
	}
	if(n<=18) dfs(1);
	cout<<ans;
	return 0;
}

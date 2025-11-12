#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505],ans,b[505],c[505],s0;
string s;
int pd()
{
	int s2=0,s1=0;
	for(int i=1;i<=n;i++)
		if(s1<c[i])
		{
			if(s[i-1]=='1')
				s2++;
			else
				s1++;
		}
		else
			s1++;
	if(s2>=m)
		return 1;
	return 0;
}
void dfs(int x)
{
	if(x==n)
	{
		if(pd())
			ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(b[i]==0)
		{
			b[i]=1;
			c[x+1]=a[i];
			dfs(x+1);
			b[i]=0;
		}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)
			s0++;	
	}
	if(n-s0<m)
	{
		cout<<0;
		return 0;
	}
	dfs(0);
	printf("%d",ans%mod);
	return 0;
}

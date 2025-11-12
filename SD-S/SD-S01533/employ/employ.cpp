#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
long long read()
{
	char str;
	long long f=1;
	str=getchar();
	while(str<'0'||str>'9')
	{
		str=getchar();
		if(str=='-')
		{
			f=-1;
		}
	}
	long long s=0;
	while(str>='0'&&str<='9')
	{
		s=s*10+str-'0';
		str=getchar();
	}
	return f*s;
}
int n,m;
int a[1000];
char str[1000];
int fs[1000];
bool b[1000];
long long ans=0;
void f(int x)
{
	if(x==n+1)
	{
		int s=0;
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='0'||s>=a[fs[i]])
			{
				s++;
			}
		}
		if(n-s>=m)
		{
			ans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			fs[x]=i;
			f(x+1);
			b[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",str+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	f(1);
	printf("%lld",ans%mod);
	return 0;
}


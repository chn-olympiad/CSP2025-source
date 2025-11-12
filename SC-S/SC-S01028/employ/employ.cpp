#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define mod 1000000007
#define pii pair<int,int>
using namespace std;

inline int read()
{
	int x=0,f=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?-x:x;
}
int n,m;
char s[maxn];
int c[maxn];
int a[maxn],ans=0,sum=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	cin>>(s+1);
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
	}
	for(int i=1;i<=n;i++) a[i]=i;
	if(n<=10)
	{
		while(1)
		{
			int now=0;
			sum=0;
			for(int i=1;i<=n;i++)
			{
//			cout<<now<<' '<<a[i]<<'\n';
				if(now>=c[a[i]])
				{
					now++;
					continue;
				}
				if(s[i]=='0')
				{
					now++;
				}
				else
				{
					sum++;
				}
			}
			if(sum>=m)
			{
//			for(int i=1;i<=n;i++) cout<<a[i]<<' ';
//			cout<<'\n';
				ans++;
			}
			if(!next_permutation(a+1,a+n+1)) break;
		}
		cout<<ans;	
	}
	else
	{
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==0)
			{
				cout<<0<<'\n';
				return 0;
			}
		}
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++)
		{
			if(c[i]<1)
			{
				cout<<0<<'\n';
				return 0;
			}
		}
		ll ans=1;
		for(int i=1;i<=n;i++) ans=ans*i,ans=ans%998244353;
		cout<<ans<<'\n';
	}
}
/*
3 2
101
1 1 2
*/
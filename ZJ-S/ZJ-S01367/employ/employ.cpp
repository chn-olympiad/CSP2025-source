#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s*w;
}
inline void print(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10)print(x/10);
	putchar(x%10+48);
}
const int mod=998244353;
inline void exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	int tmp=x;
	x=y;
	y=tmp-(a/b)*y;
}
inline int Inv(int a)
{
	int x,y;
	exgcd(a,mod,x,y);
	x%=mod;
	x+=mod;
	x%=mod;
	return x;
}
int fac[1000010],inv[1000010],n,m;
string s;
int b[1000010],c[1000010],p[1000010];
/*
Genshin Impact
I love you Genshin
*/
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	cout<<inv(10)<<'\n';
	fac[0]=1;
	for(int i=1;i<=1000000;i++)fac[i]=fac[i-1]*i%mod;
	inv[1000000]=Inv(fac[1000000]);
	for(int i=999999;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
//	cout<<inv[1]<<' '<<inv[2]<<'\n';
	n=read();
	m=read();
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		b[i]=(s[i]-48);
//		cout<<b[i]<<' ';
//		c[i]=read();
		p[i]=i;
	}
//	puts("");
	for(int i=1;i<=n;i++)c[i]=read();
	int cnt=0;
//	puts("");
	do
	{
		int num=0,tmp=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0)
			{
				num++;
				continue;
			}
			if(num>=c[p[i]])
			{
				num++;
			}
		}
		if(n-num>=m)
		{
//			for(int i=1;i<=n;i++)
//			{
//				cout<<p[i]<<' '<<c[p[i]]<<' '<<b[i]<<'\n';
//			}
//			puts("");
			cnt++;
		}
	}
	while(next_permutation(p+1,p+n+1));
	print(cnt);
}

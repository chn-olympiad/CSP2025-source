#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
LL read()
{
	char c=getchar();
	LL f=1,x=0;
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}
void print(LL x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
const LL M=5e6+5,N=2e5+5;
LL n,q,len[N],w[N][2];
uLL pw[M],h[N][2],H[M];
bool flag=true;
int check(string s)
{
	int cnt1=0,cnt2=0,p=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a') cnt1++;
		if(s[i]=='b')
		{
			cnt2++;
			p=i;
		}
	}
	if(cnt1+cnt2<s.size()||cnt2!=1) return 0;
	return p+1;
}
void solve()
{
	while(q--)
	{
		LL ans=0;
		string s,t;
		cin>>s>>t;
		int l=check(s),r=check(t);
		int o=s.size();
		s=' '+s;
		t=' '+t;
		if(!l||!r)
		{
			putchar('0');
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			int x=l-w[i][0]+1;
			int y=r-w[i][1]+1;
			if(x>=1&&y>=1&&x==y&&x+len[i]-1<=o) ans++;
		}
		print(ans);
		putchar('\n');
	}
}
int main()
{
//	freopen("replace4.in","r",stdin);
//	freopen("cdo.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=5e6;i++) pw[i]=pw[i-1]*131;
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
	{
		string s,t;
		cin>>s>>t;
		int l=check(s),r=check(t);
		w[i][0]=l,w[i][1]=r;
		if(!l) flag=false;
		if(!r) flag=false;
		len[i]=s.size();
		s=' '+s;
		t=' '+t;
		for(int j=1;j<=len[i];j++)
		{
			h[i][0]+=(s[j]-'a')*pw[j];
			h[i][1]+=(t[j]-'a')*pw[j];
		}
	}
	if(flag)
	{
		solve();
		return 0;
	}
	while(q--)
	{
		LL ans=0;
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size())
		{
			putchar('0');
			putchar('\n');
			continue;
		}
		int o=s.size();
		s=' '+s;
		t=' '+t;
		uLL v=0;
		for(int i=1;i<=o;i++)
		{
			H[i]=H[i-1]+(s[i]-'a')*pw[i];
			v+=(t[i]-'a')*pw[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j+len[i]-1<=o;j++)
			{
				uLL x=H[j+len[i]-1]-H[j-1];
				uLL y=h[i][0]*pw[j-1];
				if(x==y)
				{
					uLL p=H[o]-x+h[i][1]*pw[j-1];
					if(p==v) ans++;
				}
			}
		}
		print(ans);
		putchar('\n');
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
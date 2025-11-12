#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define gc() getchar()
#define pc(x) putchar(x)
#define look_time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<'\n'

const int P=998244353;
const int mod=1e9+7;
const int Bit=127;

inline int read()
{
	int x=0,f=1;char c=gc();
	while(!isdigit(c)) {if(c=='-') {f=-f;}c=gc();}
	while(isdigit(c)) {x=x*10+c-'0';c=gc();}
	return x*f;
}

inline pair<int,int> rd()
{
	int x=0,cnt=0;;char c=gc();
	while(c<'a'||c>'z') {c=gc();}
	while(c>='a'&&c<='z') {x=(x*Bit+c)%mod;c=gc();cnt++;}
	return {x,cnt};
}
	
inline void write(int x)
{
	if(x<0) {pc('-');x=-x;}
	if(x<10) {pc(x+'0');}
	else {write(x/10);pc(x%10+'0');}
	return ;
}

inline void print(int x)
{
	write(x);pc('\n');
	return ;
}

int Time;

int n,q;
int s[200010][2];
int l[200010][2];

int p[200010];

void init()
{
	p[0]=1;
	for(int i=1;i<=200000;i++) 
	{
		p[i]=p[i-1]*Bit%mod;
	}
	
	
	
}

void solve()
{
	int ans=0;
	pair<int,int> t1=rd(),t2=rd();
	int x1=t1.first,x2=t2.first;
	int l1=t1.second;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=l1-l[i][0];j++)
		{
			if(((x1+(s[i][1]-s[i][0])*p[j]%mod)+mod)%mod==x2)
			{
				ans++;
			}
		}
	}
	print(ans);
	return ;
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Time=clock();
	n=read(),q=read();
	for(int i=1;i<=n;i++) 
	{
		pair<int,int> s1=rd(),s2=rd();
		s[i][0]=s1.first;
		l[i][0]=s1.second;
		s[i][1]=s2.first;
		l[i][1]=s2.second;
	}
	init();
	for(int i=1;i<=q;i++)
	{
		solve();
	}
	
	return 0;
}

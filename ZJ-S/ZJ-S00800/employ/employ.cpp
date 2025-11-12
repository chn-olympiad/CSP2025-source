#include <bits/stdc++.h>

using namespace std;

#define int long long
#define gc() getchar()
#define pc(x) putchar(x)
#define look_time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<'\n'
const int mod=998244353;

inline int read()
{
	int x=0,f=1;char c=gc();
	while(!isdigit(c)) {if(c=='-') {f=-f;}c=gc();}
	while(isdigit(c)) {x=x*10+c-'0';c=gc();}
	return x*f;
}

inline int rd()
{
	char c=gc();
	while(!isdigit(c)) {c=gc();}
	return c-'0';
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
int n,m;
bool flag;
int ans;

int a[210];
int c[210];
int s[210];
bool vis[2000];

bool check()
{
	int sum=0;
	int cnt=0;
	for(int i=1;i<=n;i++) 
	{
		if(s[i]&&cnt<c[a[i]]) {sum++;}
		else {cnt++;}
	}
	return sum>=m;
}

void dfs(int x)
{
	if(x==n+1) {if(check()) {ans++;}return ;}
	
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) 
		{
			a[x]=i;vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
	return ;
}

void solve1()
{
	for(int i=1;i<=n;i++) {c[i]=read();}
	dfs(1);
	print(ans);
	return ;
}

int dp[510][510];//前i个人，走j个的方案数
int p[510];

void init()
{
	p[0]=1;
	for(int i=1;i<=500;i++) {p[i]=p[i-1]*i%mod;}
	return ;
}

void solve3()
{
	for(int i=1;i<=n;i++) {c[i]=read();if(c[i]==0) {print(0);return ;}}
	for(int i=1;i<=n;i++) {if(s[i]==0) {print(0);return ;}}
	int ans=1;
	for(int i=1;i<=n;i++) {ans=ans*i%mod;}
	print(ans);
	return ;
}

int sum;

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	Time=clock();
	n=read(),m=read();
	init();
	for(int i=1;i<=n;i++)
	{
		s[i]=rd();sum+=s[i];
		if(s[i]!=1) {flag=1;}
	}
	if(sum<m) {print(0);return 0;}
	if(n<=18) 
	{
		solve1();
		return 0;
	}
	if(m==1)
	{
		print(0);
		return 0;
	}
	if(m==n) 
	{
		solve3();
		return 0;
	}
	return 0;
}

//12pts

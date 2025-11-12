#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define gc() getchar()
#define pc(x) putchar(x)
#define look_time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<'\n'

inline int read()
{
	int x=0,f=1;char c=gc();
	while(!isdigit(c)) {if(c=='-') {f=-f;}c=gc();}
	while(isdigit(c)) {x=x*10+c-'0';c=gc();}
	return x*f;
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
int n,m,k;

struct node {int u,v,w;}S[1000010];
bool cmp(node X,node Y) {return X.w<Y.w;}
int c[20];
int t[10010][11];

struct que {};

int f[10010];

int find(int x)
{
	if(f[x]==x) {return x;}
	return f[x]=find(f[x]);
}

void solve1()
{
	for(int i=1;i<=n;i++) {f[i]=i;}
	int ans=0;
	for(int i=1;i<=m;i++) 
	{
		int fu=find(S[i].u),fv=find(S[i].v);
		if(fu!=fv)
		{
			f[fu]=fv;
			ans+=S[i].w;
		}
	}
	print(ans);
	return ;
}


node P[100010];

int solve(int OP)
{
	int ans=0;
	int cnt=0;
	for(int s=1;s<=k;s++)
	{
		if(OP&(1<<(s-1))) 
		{
			ans+=c[s];
			for(int i=1;i<=n;i++)
			{
				P[++cnt]={n+s,i,t[i][s]};
			}
		}
	}	
	sort(P+1,P+cnt+1,cmp);
	for(int i=1;i<=n+k;i++) {f[i]=i;}
	for(int i=1,j=1;i<=m+1&&j<=cnt+1;) 
	{
		int fu,fv,w;
		if(i>m)
		{
			fu=find(P[j].u);fv=find(P[j].v);w=P[j].w;
			j++;
		}
		else if(j>cnt||S[i].w<=P[j].w)
		{
			fu=find(S[i].u);fv=find(S[i].v);w=S[i].w;
			i++;
		}
		else
		{
			fu=find(P[j].u);fv=find(P[j].v);w=P[j].w;
			j++;
		}
		
		if(fu!=fv)
		{
			f[fu]=fv;
			ans+=w;
		}
	}
	return ans;
}
	
	

void solve2()
{
	int ans=LONG_LONG_MAX;
	for(int op=0;op<(1<<k);op++) 
	{
		int x=solve(op);
		if(ans>x) {ans=x;}
	}
	print(ans);	
	return ;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Time=clock();
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		S[i].u=read(),S[i].v=read(),S[i].w=read();
	}
	sort(S+1,S+m+1,cmp);
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++) {t[j][i]=read();}
	}
	if(k==0) {solve1();return 0;}
	solve2();
	return 0;
}

//16pts-48pts?

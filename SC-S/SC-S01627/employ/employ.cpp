#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod=998244353;
inline int read()
{
	int x=0,f=0;
	char c=getchar();
	while(!isdigit(c))
	{
		f|=c=='-';
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f?(-x):x;
}
int n,m;
char xgd[1000];
int a[1000];
int hys[1000];
int book[1000];
int qwq;
void solve()
{
	int de=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(xgd[i]=='0')de++;
		else
		{
			if(de>=a[hys[i+1]])de++;
			else 
			ans++;
		}
	}
	if(ans>=m)
	qwq++;
}
void dfs(int step)
{
	if(step>n)
	{
		solve();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(book[i]==0)
		{
			book[i]=1;
			hys[step]=i;
			dfs(step+1);
			book[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",xgd);
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
//	if(m==1)
//	{
//		int ans=0;
//		for(int i=0;i<n;i++)
//		{
//			if(xgd[i]=='1')
//			{
//				for(int i=1;i<=)
//			}
//		}
//	}
	if(n==m)
	{
		printf("0");
		return 0;
	}
	dfs(1);
	printf("%lld",qwq);
	return 0;
}
/*
3 2
101
1 1 2


10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
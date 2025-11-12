#include<bits/stdc++.h>
using namespace std;
int T,n,ans,sum;
int QianZuiSumA[100005],QianZuiSumB[100005],QianZuiSumC[100005];
bool flagA,flagB,flagC;
struct nd
{
	int a,b,c;
}s[100005];
bool cmpABC(const nd& A,const nd& B)
{
	return A.a!=B.a?(A.a>B.a):(A.b!=B.b?A.b>B.b:A.c>B.c);
}
bool cmpACB(const nd& A,const nd& B)
{
	return A.a!=B.a?(A.a>B.a):(A.c!=B.c?A.c>B.c:A.b>B.b);
}
bool cmpBAC(const nd& A,const nd& B)
{
	return A.b!=B.b?(A.b>B.b):(A.a!=B.a?A.a>B.a:A.c>B.c);
}
bool cmpBCA(const nd& A,const nd& B)
{
	return A.b!=B.b?(A.b>B.b):(A.c!=B.c?A.c>B.c:A.a>B.a);
}
bool cmpCAB(const nd& A,const nd& B)
{
	return A.c!=B.c?(A.c>B.c):(A.a!=B.a?A.a>B.a:A.b>B.b);
}
bool cmpCBA(const nd& A,const nd& B)
{
	return A.c!=B.c?(A.c>B.c):(A.b!=B.b?A.b>B.b:A.a>B.a);
}
void dfs(int now,int a,int b,int c,int v)
{
	if(v+QianZuiSumA[n]-QianZuiSumA[now-1]
	+QianZuiSumB[n]-QianZuiSumB[now-1]
	+QianZuiSumC[n]-QianZuiSumC[now-1]<=ans) return;
	if(now>n)
	{
		ans=v;
		return;
	}
	if(a<n/2&&a) dfs(now+1,a+1,b,c,v+s[now].a);
	if(b<n/2&&b) dfs(now+1,a,b+1,c,v+s[now].b);
	if(c<n/2&&c) dfs(now+1,a,b,c+1,v+s[now].c);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		flagA=true,flagB=true,flagC=true;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			if(s[i].b) flagA=false;
			if(s[i].c) flagA=flagB=false;
			QianZuiSumA[i]=QianZuiSumA[i-1]+s[i].a;
			QianZuiSumB[i]=QianZuiSumB[i-1]+s[i].b;
			QianZuiSumC[i]=QianZuiSumC[i-1]+s[i].c;
		}
		if(flagA)
		{
			sort(s+1,s+n+1,cmpABC);
			for(int i=1;i<=n/2;i++) ans+=s[i].a;
			printf("%d\n",ans);
			continue;
		}
//		if(n<=30)
		{
			dfs(1,0,0,0,0);
			printf("%d\n",ans);
		}
		if(flagB)
		{
			sum=0;
			
		}
	}
	return 0;
}

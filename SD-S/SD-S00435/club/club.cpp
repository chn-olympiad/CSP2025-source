#include<bits/stdc++.h>
#define FOR(i,j,k) for(int i=(j);i<=(k);++i)
#define NFOR(i,j,k) for(int i=(j);i>=(k);--i)
#define fst first
#define sec second
#define pb push_back
#define mkp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3fll;
int read()
{
	int s=0,w=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1,c=getchar();}
	while(c>='0'&&c<='9') {s=(s<<1)+(s<<3)+c-'0';c=getchar();}
	return s*w;
}
void file(string s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int n;
int a[100005][5];
int ans;

namespace pnt1
{
	const int N=205;
	int dp[N][N>>1][N>>1];
	void sov1()
	{
		FOR(i,1,n) FOR(j,0,(n>>1)) FOR(p,0,(n>>1))
		{
			int q=i-j-p;
			if(q<=n/2) dp[i][j][p]=0;
		}
		FOR(i,1,n) FOR(j,0,(n>>1)) FOR(p,0,(n>>1))
		{
			int q=i-j-p;
			if(q>n/2) continue;
			if(j!=0) dp[i][j][p]=max(dp[i][j][p],dp[i-1][j-1][p]+a[i][1]);
			if(p!=0) dp[i][j][p]=max(dp[i][j][p],dp[i-1][j][p-1]+a[i][2]);
			if(q!=0) dp[i][j][p]=max(dp[i][j][p],dp[i-1][j][p]+a[i][3]);
		}
		FOR(i,0,n/2) FOR(j,0,n/2)
		{
			int k=n-i-j;
			if(k<=n/2) ans=max(ans,dp[n][i][j]);
		} 
		printf("%d\n",ans);
	}
}

namespace pnta
{
	const int N=1e5+5;
	
	priority_queue <int> q;
	
	void grdy()
	{
		while(!q.empty()) q.pop();
		FOR(i,1,n) q.push(a[i][1]);
		FOR(i,1,n/2)
		{
			ans+=q.top();
			q.pop();
		}
		printf("%d\n",ans);
	}
}

namespace pntb
{
	const int N=200+5;
	int dp[N][N>>1];
	
	void sov2()
	{
		FOR(i,1,n) FOR(j,0,n/2) 
		{
			dp[i][j]=0;
		}
		FOR(i,1,n) FOR(j,0,n/2)
		{
			int k=i-j;
			if(k>n/2) continue;
			if(j!=0) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i][1]);
			if(k!=0) dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i][2]);
		}
		ans=dp[n][n/2];
		/*FOR(i,1,n) FOR(j,0,n/2)
		{
			printf("%d%c",dp[i][j],j==n/2?'\n':' '); 
		}*/
	}
}

namespace pntt
{
	const int N=1e5+5;
	void sov3()
	{
		puts("0");
	}
}

void sov()
{
	n=read();ans=0;
	bool flg1=1,flg2=0;
	FOR(i,1,n) FOR(j,1,3) a[i][j]=read();
	FOR(i,1,n)
	{
		if(a[i][2]!=0) flg1=0;
		if(a[i][3]!=0) flg1=0,flg2=0;
	}
	if(n<=200) pnt1::sov1();
	else if(flg1) pnta::grdy();
	else if(flg2) pntb::sov2();
	else pntt::sov3();
}

int main()
{
	file("club");
	int _=read();
	while(_--) sov();
	return 0; 
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
/*
1
10
4 5 0 
10 9 0
5 9 0 
9 6 0
0 0 0
5 0 0
0 5 0
0 0 0
0 0 0

*/

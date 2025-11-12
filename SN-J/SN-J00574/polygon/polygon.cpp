//SN-J00574  lizhiying  辅轮中学

#include <bits/stdc++.h>
#define LL long long
#define DB double
#define LB long double
#define mid ((l+r)>>1)
#define tp top()
#define pp pop()
#define si size()
#define modd1 998244353
#define modd2 1000000007
#define eps1 (-1e9)
#define eps2 (-1e18)
#define modd modd1
//#define eps 

#define maxn 5005




using namespace std;

int add (int x,int y) { return (0LL+x+y+modd+modd)%modd; }
int mul (int x,int y) { return (1LL*x*y)%modd; }
void ADD (int &x,int y) { x=add(x,y); }
void MUL (int &x,int y) { x=mul(x,y); }
/*
int sum[],inv[]; void Init ()
{
	int p=;
	sum[0]=1; for (int i=1;i<=p;i++) sum[i]=mul(sum[i-1],i);
	inv[1]=1; for (int i=2;i<=p;i++) inv[i]=mul(inv[modd%i],modd-modd/i);
	inv[0]=1; for (int i=1;i<=p;i++) MUL(inv[i],inv[i-1]);
}
*/


int n,a[maxn],Max,dp[maxn],ans;







void work ()
{
	cin>>n; for (int i=1;i<=n;i++) cin>>a[i],Max=max(Max,a[i]);
	sort(a+1,a+n+1); dp[0]=1,Max++;
	for (int i=1;i<=n;i++)
	{
		for (int j=a[i]+1;j<=Max;j++) ADD(ans,dp[j]);
		for (int j=Max;j>=0;j--) ADD(dp[min(Max,j+a[i])],dp[j]);
	} cout<<ans;
}

int main ()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
//	freopen (".txt","r",stdin);
//	freopen (".txt","w",stdout);
//	int T; cin>>T; while (T--)
		work(); return 0;
}
//polygon
//乌萨奇 ~  到 ~
//啊 我爱学习
//啊 我爱上学
//啊 我爱考试
//我最爱上学啦

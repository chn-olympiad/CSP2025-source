//SN-J00574  lizhiying  ¸¨ÂÖÖÐÑ§

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
//#define modd 
//#define eps 

#define maxn 500005
#define maxm ((1<<20)+10)




using namespace std;
/*
int add (int x,int y) { return (0LL+x+y+modd+modd)%modd; }
int mul (int x,int y) { return (1LL*x*y)%modd; }
void ADD (int &x,int y) { x=add(x,y); }
void MUL (int &x,int y) { x=mul(x,y); }

int sum[],inv[]; void Init ()
{
	int p=;
	sum[0]=1; for (int i=1;i<=p;i++) sum[i]=mul(sum[i-1],i);
	inv[1]=1; for (int i=2;i<=p;i++) inv[i]=mul(inv[modd%i],modd-modd/i);
	inv[0]=1; for (int i=1;i<=p;i++) MUL(inv[i],inv[i-1]);
}
*/


int n,k,a[maxn],sum[maxn];
int dp[maxn],vis[maxm];






void work ()
{
	cin>>n>>k; for (int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i];
	for (int i=0;i<maxm;i++) vis[i]=n+1; vis[k]=0;
	for (int i=1;i<=n;i++)
	{
		if (vis[sum[i]]<i) dp[i]=dp[vis[sum[i]]]+1;
		vis[sum[i]^k]=i,dp[i]=max(dp[i-1],dp[i]);
	} cout<<dp[n];
}

int main ()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
//	freopen (".txt","r",stdin);
//	freopen (".txt","w",stdout);
	//int T; cin>>T; while (T--)
		work(); return 0;
}
//xor
//µÆÁý¿ã

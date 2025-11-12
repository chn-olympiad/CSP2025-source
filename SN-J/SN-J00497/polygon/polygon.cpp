//SN-J00497 李中易 西安辅轮中学
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int modd=998244353,maxn=5010;

ll n,a[maxn],dp[maxn][maxn],tp[maxn][maxn],maxx,ans;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+1+n);maxx=a[n];
	tp[0][0]=1;
	for(int i=0;i<=maxx;i++)  dp[0][i]=2;
	for(int i=1;i<=n;i++)  for(int j=0;j<=maxx;j++)
	{
		tp[i][j]=tp[i-1][j];
		if(j>=a[i])  tp[i][j]=(tp[i-1][j]+tp[i-1][j-a[i]])%modd;
		dp[i][j]=tp[i][j];
		if(j>0)  dp[i][j]=(dp[i][j-1]+tp[i][j])%modd;
	}
	ans=1;for(int i=1;i<=n;i++)  ans=(ans*2)%modd;
	for(int i=1;i<=n;i++)  ans=(ans-dp[i-1][a[i]]+modd)%modd;
	cout<<ans;
	return 0;
}


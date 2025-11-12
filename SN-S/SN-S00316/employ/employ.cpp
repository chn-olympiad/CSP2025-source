//李中易 SN-S00316 西安辅轮中学
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=510,modd=998244353;

int n,m,c[maxn];
ll dp[1<<18][maxn],ans;
string s;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;s="$"+s;
	for(int i=1;i<=n;i++)  cin>>c[i];
	dp[0][0]=1;
	for(int i=0;i<(1<<n);i++)
	{
		int zong=0;
		for(int k=1;k<=n;k++)  if((i&(1<<(k-1)))!=0)  zong++;
		for(int j=0;j<=n;j++)  for(int k=1;k<=n;k++)
		{
			if((i&(1<<(k-1)))!=0)  continue;
			int l=(i|(1<<(k-1)));
			if(c[k]<=zong-j&&s[zong+1]=='1')  dp[l][j+1]+=dp[i][j];
			else  dp[l][j]+=dp[i][j];
			dp[l][j+1]%=modd;dp[l][j]%=modd;
		}
	}
	for(int i=m;i<=n;i++)  ans=(ans+dp[(1<<n)-1][i])%modd;
	cout<<ans;
	return 0;
} 

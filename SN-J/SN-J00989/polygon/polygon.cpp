#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5005;
const int mod=998244353;

int n;
int l[MAXN],maxl;

int dp[MAXN][MAXN<<1]; //  前 i 个的和大于 j 的方案数 

inline int get(int i,int j)
{
//	if(j<0) return 0;
	return dp[i][max(j,0ll)];
}
void Max(int &a,int b)
{
	if(b>a) a=b;
}
void Add(int &a,int b)
{
	a=((a%mod+b%mod)%mod+mod)%mod;
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++) cin>>l[i],maxl=max(maxl,l[i]);
	maxl=maxl+100;
	sort(l+1,l+n+1);

	dp[0][0]=1;
	int num=2;
	for(int i=1;i<=n;i++) dp[i][0]=num,num=(num*2)%mod;
//	for(int i=0;i<=l[1];i++) dp[1][i]=1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=maxl;j++)
		{
			dp[i][j]=(get(i-1,j)+get(i-1,j-l[i]))%mod;
//			cout<<dp[0][i][j]<<" ";
		}
//		cout<<endl; 
	}
	
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<=maxl;j++) printf("%3lld ",dp[i][j]);
//		cout<<endl;
//	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<" "<<dp[i-1][l[i]+1]<<endl;
		Add(ans,dp[i-1][l[i]+1]);
	}
	cout<<ans<<endl;
//	cout<<dp[0][n][2]<<endl;
	
	return 0;
}

/*

5
1 2 3 4 5

5
2 2 3 8 10
*/

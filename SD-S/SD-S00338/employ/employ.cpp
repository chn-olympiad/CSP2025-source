#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505];
bool bj[505];
int dp[300000][20];
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char a;
		cin>>a;
		if(a=='1') bj[i]=1;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dp[0][0]=1;
	for(int i=0;i<(1<<n)-1;i++)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
			if((1<<j)&i) cnt++;
	//	cout<<i<<":\n";
		for(int j=0;j<=cnt;j++)
		{//cout<<dp[i][j]<<" "; 
			for(int k=1;k<=n;k++)
				if(!((1<<(k-1))&i))
				{
					int op;
					if(c[k]<=j) op=j+1;
					else 
					{
						if(bj[cnt+1]) op=j;
						else op=j+1;
					}
					dp[i|(1<<(k-1))][op]=(dp[i|(1<<(k-1))][op]+dp[i][j])%mod;
				}
			
		}
	//	cout<<"\n";
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		if(n-i>=m) ans=(ans+dp[(1<<n)-1][i])%mod;
	cout<<ans;
	return 0;
}


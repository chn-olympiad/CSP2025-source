#include<bits/stdc++.h>
#define N 20
#define mod 998244353
using namespace std;
void pls(int &a,int b){a=(a+b>=mod?a+b-mod:a+b);}
int n,m,a[N],b[N],dp[2][N][1<<18],ans;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s,s=" "+s,dp[0][0][0]=1;
	for(int i=1;i<=n;i++)	cin>>b[i],a[i]=s[i]-'0';
	int now=0;
	for(int i=0;i<n;i++){
		now^=1;
		for(int j=0;j<=i;j++){
			for(int s=0;s<(1<<n);s++)	dp[now][j][s]=0;
		}
		for(int j=0;j<=i;j++){
			for(int s=0;s<(1<<n);s++){
				for(int t=1;t<=n;t++){
					if((s>>t-1)&1)	continue;
					int tmp=s|(1<<t-1);
					pls(dp[now][j+(!a[i+1]||j>=b[t])][tmp],dp[now^1][j][s]);
				}
			}
		}
	}
	for(int i=0;i<m;i++)	pls(ans,dp[now][i][(1<<n)-1]);
	cout<<ans;
	return 0;
}

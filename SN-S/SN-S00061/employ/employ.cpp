#include<bits/stdc++.h>
using namespace std;
const int N=505,p=998244353;
int n,m,fl,num,c[N],dp[1<<18][20],ans;string st;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>st;
	for(int i=0;i<n;i++) cin>>c[i],num+=(c[i]>0);
	dp[0][0]=1;
	for(int s=1;s<(1<<n);s++){
		int now=0;
		for(int j=0;j<n;j++){if(s&(1<<j)) now++;}
		for(int j=0;j<n;j++) if(s&(1<<j)) for(int i=0;i<=n;i++){
			if(c[j]<=i||st[now-1]=='0') dp[s][i+1]=(dp[s][i+1]+dp[s^(1<<j)][i])%p;
			else dp[s][i]=(dp[s][i]+dp[s^(1<<j)][i])%p;
		}
	}for(int i=n-m;i;i--) ans=(ans+dp[(1<<n)-1][i])%p;
	return cout<<ans,0;
}

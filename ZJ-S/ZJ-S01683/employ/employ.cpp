#include<bits/stdc++.h>
#define N 505
using namespace std;
const int mod=998244353;
int n,m;
int s[N];
int c[N];
int dp[20][(1<<18)+5][20];
int ans=0;
int main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<n);j++){
			int sum=0;
			for(int k=0;k<n;k++){
				int op=(j>>k)&1;
				sum+=op;
			}
			if(sum!=i-1) continue;
			for(int k=0;k<=i-1;k++){
				for(int p=0;p<n;p++){
					if((j>>p)&1) continue;
					if(s[i]==0 or i-1-k>=c[p+1])(dp[i][j|(1<<p)][k]+=dp[i-1][j][k])%=mod;
					else if(s[i]==1 and i-1-k<c[p+1])(dp[i][j|(1<<p)][k+1]+=dp[i-1][j][k])%=mod;
				}
			}
		}
	}
	for(int i=m;i<=n;i++){
		(ans+=dp[n][(1<<n)-1][i])%=mod;
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
long long a[100010][3],dp[210][110][110];
void solve(){
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		for(long long _=0;_<3;_++){		
			cin>>a[i][_];
		}
	}
	if(n<=200){
		for(long long i=0;i<=n;i++){
			for(long long j=0;j<=n/2;j++){
				for(long long k=0;k<=n/2;k++){
					dp[i][j][k]=-1e9;
				}
			}
		}
		dp[0][0][0]=0;
		for(long long i=1;i<=n;i++){
			for(long long j=0;j<=n/2;j++){
				for(long long k=0;k<=n/2;k++){
					long long l=i-j-k;
					if(l>n/2||l<0){
						continue;
					}
					if(j>0){
						dp[i][j][k]=max(dp[i-1][j-1][k]+a[i][0],dp[i][j][k]);
					}
					if(k>0){
						dp[i][j][k]=max(dp[i-1][j][k-1]+a[i][1],dp[i][j][k]);
					}
					if(l>0){
						dp[i][j][k]=max(dp[i-1][j][k]+a[i][2],dp[i][j][k]);
					}
				}
			}
		}
		long long ans=0;
		for(long long i=0;i<=n/2;i++){
			for(long long j=0;j<=n/2;j++){
				long long k=n-i-j;
				if(k>n/2)continue;
				ans=max(ans,dp[n][i][j]);
			}
		}
		cout<<ans;
	}
	else{
		long long ans=0;
		for(long long i=1;i<=n;i++){
			ans+=a[i][0];
		}
		cout<<ans;
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	fre("club");
	long long T;
	cin>>T;
	while(T--){
		solve();
	}
}
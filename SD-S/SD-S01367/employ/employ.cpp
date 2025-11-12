#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long dp[1<<19][20];
int n,m;
string s;
int c[20];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==n){
		for(auto i:s){
			if(i=='0'){
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		long long ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<n);j++){
			if(__builtin_popcount(j)!=i) continue;
			for(int k=0;k<=i;k++){
				for(int now=1;now<=n;now++){
					if(j&(1<<now-1)) continue;
					dp[j|(1<<now-1)][k+((c[now]>i-k)&&(s[i]=='1'))]=(dp[j|(1<<now-1)][k+((c[now]>i-k)&&(s[i]=='1'))]+dp[j][k])%mod;
				}
			}
		}
	}
	long long ans=0;
	for(int i=m;i<=n;i++) (ans+=dp[(1<<n)-1][i])%=mod;
	cout<<ans%mod;
}

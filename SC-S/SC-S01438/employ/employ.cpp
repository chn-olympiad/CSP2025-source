#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c[510],dp[(1<<20)][20];string s;
const int mod=998244353;
inline int popcount(int x){
	int ans=0;
	while(x)x-=(x&-x),ans++;
	return ans; 
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;cin>>s;
	for(int i = 1;i<=n;i++)cin>>c[i];
	if(m!=n){
		dp[0][0]=1;
		for(int i = 1;i<=n;i++){
			for(int id = 0;id<(1<<n);id++){
				if(popcount(id)!=i)continue;
				for(int j = 0;j<i;j++){
					for(int k = 1;k<=n;k++){
						if(id&(1<<(k-1))){
							if(j<c[k]&&s[i-1]=='1')dp[id][j]+=dp[id^(1<<(k-1))][j];
							else dp[id][j+1]+=dp[id^(1<<(k-1))][j];
						}
					}
				}
			}
		}
		int ans=0;
		for(int i = m;i<=n;i++)ans+=dp[(1<<n)-1][n-i],ans%=mod;
		cout<<ans<<"\n"; 
	}
	else{
		int sum=0;
		for(int i = 1;i<=n;i++)sum+=(s[i-1]=='1');
		for(int i = 1;i<=n;i++)sum+=(c[i]>0);
		int ans=(sum==2*n);
		for(int i = 1;i<=n;i++)ans*=i,ans%=mod;
		cout<<ans<<"\n";
	}
}
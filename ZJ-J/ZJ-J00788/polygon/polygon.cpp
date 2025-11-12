#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
int n,a[5010];
int dp[10010],pre[10010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	pre[0]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=10001;j++){
			if(j<=10000) dp[j]=pre[j-a[i]];
			else{
				dp[j]=0;
				for(int k=j-a[i];k<=j;k++){
					dp[j]=(dp[j]+pre[k])%MOD;
				}
			}
			if(2*a[i]<j) ans=(ans+dp[j])%MOD;
		}
		for(int j=a[i];j<=10001;j++){
			pre[j]=(pre[j]+dp[j])%MOD;
		}
	}
	cout<<ans;
	return 0;
}
// 9:40

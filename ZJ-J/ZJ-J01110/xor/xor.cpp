#include<bits/stdc++.h>
using namespace std;
const int Maxn=500005;
int n;
long long k;
int a[Maxn];
long long f[Maxn];
int dp[Maxn];
int ans=0;
bool special_b=1;
map<long long,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i]=(f[i-1]^a[i]);
		if(a[i]>1) special_b=0;
	}
	if(ans>1000 && special_b){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(a[i]==1 && a[i+1]==1){
					ans++;
					i++;
				}
			} 
		}
		cout<<ans;
		return 0;
	}
	else if(n<=1000){
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				dp[j]=max(dp[j],dp[j-1]);
				if((f[i]^f[j-1])==k){
					dp[i]=max(dp[i],dp[j-1]+1);
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,dp[i]);
		}
		cout<<ans;
		return 0;
	}
	else{
		ans=0;
		int t=0;
		for(int i=n;i>=1;i--){
			t=(t^a[i]);
			mp[t]++;
			ans=max(ans,mp[t^k]);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

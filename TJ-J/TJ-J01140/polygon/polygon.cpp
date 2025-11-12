#include<bits/stdc++.h>
using namespace std;
#define MOD 998244353 
int n,a[5005],dp[5005][5005],ans,m;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	if(m==1){
		ans=1;
		int sum=0;
		int f=n;
		while(n--){
			ans=(ans*2)%MOD;
			if(n!=f){
				sum*=n;
			}
		}
		sum+=n;
		sum++;
		ans=(ans+MOD)-sum;
		ans%=MOD;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){	
			for(int p=j+1;p<=n;p++){
				int ll=a[i]+a[j]+a[p];
				//cout<<a[i]<<" "<<a[j]<<" "<<a[p]<<endl; 
				if(ll>a[p]*2){
					dp[a[p]][3]++;
				}
			}
		}
	}
	for(int i=4;i<=n;i++){
		for(int j=4;j<=n;j++){
			dp[a[i]][j]=(dp[a[i]][j-1]+dp[a[i-1]][j]+1)%MOD;
		}
	}
//	for(int i=4;i<=n;i++){
//		for(int j=4;j<=n;j++){
//			cout<<dp[a[i]][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<dp[a[n]][n]<<endl;
	return 0;
}

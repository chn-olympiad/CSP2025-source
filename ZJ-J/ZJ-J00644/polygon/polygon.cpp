#include<bits/stdc++.h>
using namespace std;
int a[5010];
long long dp[1000010];
long long mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long sum=0;
	long long pq=a[1];
	dp[0]=1;
	for(int p=2;p<=n;p++){
		for(int i=pq;i>=a[p-1];i--){
			if(dp[i-a[p-1]]){
				dp[i]+=dp[i-a[p-1]];
				dp[i]%=mod;
			}
		}
		for(int i=pq;i>a[p];i--){
		    if(dp[i]){
		    	sum+=dp[i];
		    	sum%=mod;
			}
		}
		pq+=a[p];
    }
    cout<<sum;
	return 0;
}
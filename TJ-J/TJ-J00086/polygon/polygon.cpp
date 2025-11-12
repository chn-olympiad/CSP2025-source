#include<bits/stdc++.h>
#define LANH using
#define AK namespace
#define CSPJ std
LANH AK CSPJ;
typedef long long ll;
int n;
int a[5009];
ll mod=998244353;
ll dp[5009];
int maxn;
ll sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	maxn=a[n];
	dp[0]=1;
	for(int i=1;i<=n;i++){
		if(i>=3){
			for(int j=a[i]+1;j<=maxn+1;j++){
				sum+=dp[j];
				sum%=mod;
			}
		}
		for(int j=maxn+1;j>=0;j--){
			dp[min(maxn+1,j+a[i])]+=dp[j];
			dp[min(maxn+1,j+a[i])]%=mod;
		}
	}
	cout<<sum;
	return 0;
}


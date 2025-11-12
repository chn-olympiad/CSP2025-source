#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[600000],l[600000];
int dp[600000];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[i]=a[i]^l[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=l[j]^l[i-1];
			if(x==k){
				dp[j]=max(dp[j],dp[i-1]+1);
			}
		}
	}
	cout<<dp[n];
}

#include<bits/stdc++.h>
using namespace std;
int n,k,tmp[200005],dp[200005],a[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tmp[i]=tmp[i-1]^a[i];
		dp[i]=dp[i-1];
		for(int j=l;j<i;j++){
			if((tmp[i]^tmp[j])==k){
				dp[i]++,tmp[i]=0,l=i;
				break;
			}
		}
	}
	cout<<dp[n];
}

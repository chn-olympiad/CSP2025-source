#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[500005],ans,r;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];dp[i]=k;
	}
	for(int i=1;i<=n;i++){
		for(int j=r+1;j<=i;j++){
			dp[j]^=a[i];
			if(dp[j]==0){
				r=i,ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,inf=INT_MAX;
int n,m,ans,a[N],b[N],dp[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		a[i]=a[i-1]^b[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]==m){
			dp[i]=dp[i-1]+1;
		}
		else{
			dp[i]=dp[i-1];
			for(int j=1;j<=i;j++){
				int tmp=a[i]^a[j-1];
				if(tmp==m){
					dp[i]=max(dp[i],dp[j-1]+1);
				}
				else{
					dp[i]=max(dp[i],dp[j-1]);
				}
			}
		}
	}
	cout<<dp[n];
	return 0;
}
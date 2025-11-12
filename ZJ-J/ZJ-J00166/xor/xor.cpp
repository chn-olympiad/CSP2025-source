#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500005;
ll b[N],a[N],dp[N],cur[N];
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) b[i]=a[i];
		else b[i]=(b[i-1]^a[i]);
	}
	if(a[1]==k){
		dp[1]=1;
		cur[1]=1;
	}
	for(ll i=2;i<=n;i++){
		ll m=cur[i-1];
		dp[i]=dp[i-1];
		cur[i]=cur[i-1];
		if(a[i]==k){
			dp[i]++;
			cur[i]=i;
		}
		else{
			for(ll j=m+1;j<i;j++){
			    if((b[i]^b[j-1])==k){
			    	dp[i]++;
			    	cur[i]=i;
			    	break;
				}
	    	}
		}
	}
	cout<<dp[n];
	return 0;
}

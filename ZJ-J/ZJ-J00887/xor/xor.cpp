#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,k,a[N],dp[N],mid,maxx=0;
int huo(int l,int r){
	if(l==r){
		return a[l];
	}
	mid=(l+r)>>1;
	return huo(l,mid)^huo(mid+1,r);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(huo(j,i)==k){	
				dp[i]=max(dp[i],dp[j-1]+1);
			}else{
				dp[i]=max(dp[i],dp[i-1]);
			}
		}
	}
	cout<<dp[n];
	return 0;
}
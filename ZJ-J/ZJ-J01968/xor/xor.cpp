#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10,M=(1<<21)+10;
ll n,a[N],s[N],k;
ll xorr[M];
ll dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	xorr[0]=1;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(ll i=1;i<=n;i++){
		dp[i]=max(dp[i],xorr[s[i]^k]);
		dp[i]=max(dp[i],dp[i-1]);
		xorr[s[i]]=max(xorr[s[i]],dp[i]+1);
	}
	cout<<dp[n];
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,a[500001],dp[500001],k,w=0;
bool f(int x1){
	long long s=a[x1];
	if(s==k){
		return true;
	}
	for(int i=x1-1;i>=w+1;i--){
		s=s^a[i];
		if(s==k){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(f(i)){
			dp[i]++;
			w=i;
		}
	}
	cout<<dp[n];
	return 0;
}
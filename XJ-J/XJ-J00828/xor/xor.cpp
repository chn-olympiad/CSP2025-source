#include <iostream>
using namespace std;
const int N = 500005;

int n, dp[N];
long long k, a[N], sum[N];
int def(int x){
	for(int i=x-1; i>=0; i--){
		if((sum[x]^sum[i])==k)return i;
	}
	return -1;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=n; i++)sum[i]=sum[i-1]^a[i];
	for(int i=1; i<=n; i++){
		int k=def(i);
		if(k==-1)dp[i]=dp[i-1];
		else dp[i]=max(dp[i-1], dp[k]+1);
	}
	cout << dp[n];
	return 0;
}

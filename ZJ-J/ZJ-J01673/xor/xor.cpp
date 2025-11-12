#include <bits/stdc++.h>
using namespace std;
long long arr[500010];
int xi[500010];
map<long long,int>mp;
int dp[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	mp[0]=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		arr[i]=(arr[i]^arr[i-1]);
		if(!mp.count((k^arr[i]))){
			xi[i]=-1;
		}else{
			xi[i]=mp[(k^arr[i])];
		}
		mp[arr[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(xi[i]==-1){
			dp[i]=dp[i-1];
		}else{
			dp[i]=max(dp[i-1],dp[xi[i]]+1);
		}
	}
	cout<<dp[n];
	return 0;
}
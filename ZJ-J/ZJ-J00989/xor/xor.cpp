#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int sum[500005];
int dp[500005][2];
map<int,int>id;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	id[0]=0;
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		if(id.find(sum[i]^k)!=id.end()){
			dp[i][1]=1+dp[id[sum[i]^k]+1][0];
		}
		id[sum[i]]=i;
	}
	cout<<max(dp[n][0],dp[n][1]);
	return 0;
}


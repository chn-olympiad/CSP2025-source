#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1050000;
int n,k,a,x[N],dp[N];
vector<int>num[M];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k),num[0].push_back(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a),x[i]=a^x[i-1],dp[i]=dp[i-1];
		for(int j=0;j<num[k^x[i]].size();j++)
			dp[i]=max(dp[i],dp[num[k^x[i]][j]]+1);
		num[x[i]].push_back(i);
	}
	printf("%d",dp[n]);
	return 0;
}
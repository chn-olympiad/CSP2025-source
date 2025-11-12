//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
int id[1100000];
int dp[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<(1<<20);i++){
		id[i]=-1;
	}
	int x,s=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		s=s^x;
		if(id[s^k]!=-1){
			dp[i]=max(dp[i],dp[id[s^k]]+1);
		}
		id[s]=i;
		dp[i]=max(dp[i],dp[i-1]);
	}
	printf("%d",dp[n]);
	return 0;
}
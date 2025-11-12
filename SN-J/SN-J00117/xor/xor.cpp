//SN-J00117 ΑυκΕ³½ 
#include<bits/stdc++.h>
using namespace std;
const int MAXN=500000;
int n,k;
int a[MAXN+5];
int lst[MAXN+5];
int sum[MAXN+5];
int dp[MAXN+5];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	int l=n,r=n,sum=0;
	while(l<=r && r>=1){
		if(l<1){
			lst[r]=n+2;
			sum=0;
			r--;
			l=r;
			continue;
		}
		sum=sum^a[l];
		if(sum==k){
			lst[r]=l;
			sum=0;
			r--;
			l=r;
		}else{
			l--;
		}
	}
	dp[n+1]=-1;
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1],dp[lst[i]-1]+1);
	}
	printf("%d",dp[n]);
	return 0;
}


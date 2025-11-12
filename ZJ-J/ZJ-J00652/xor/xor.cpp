#include<bits/stdc++.h>
using namespace std;
int n,k,a[1010],dp[1010][1010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		dp[i][i]=a[i];
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			dp[i][j]=dp[i][j-1]^a[j];
	int l=1,cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=l;j<=i;j++)
			if(dp[j][i]==k){
				cnt++,l=i+1;
				break;
			}
	printf("%d",cnt);
	return 0;
}

#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,k,a[500005],dp[500005];
bool x;
bool check(int l,int r){
	int s=a[l];
	for(int i=l+1;i<=r;i++){
		s^=a[i];
	}
	return s==k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dp[1]=(a[1]==k);
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			x=check(j+1,i);
			if(x+dp[j]>dp[i]){
				dp[i]=x+dp[j];
			}
		}
	}
	printf("%d",dp[n]);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

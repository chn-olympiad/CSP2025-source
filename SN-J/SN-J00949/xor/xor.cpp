#include<iostream>
#include<map>
using namespace std;
int n,k,a[500001],dp[500001];
map<int,int> dpv;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k),dpv[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),a[i]^=a[i-1];
		if(dpv.count(k^a[i]))dp[i]=max(dp[i-1],1+dp[dpv[k^a[i]]]);
		else dp[i]=dp[i-1];
		dpv[a[i]]=i;
	}printf("%d",dp[n]);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int g[MAXN],dp[MAXN],pre;
int n,k,ans;
int a[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	g[1]=a[1];
	for(int i=2;i<=n;i++)g[i]=g[i-1]^a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==k){dp[i]=dp[i-1]+1;pre=i;continue;}
		bool flag=0;
		for(int j=pre+1;j<i;j++){
			if((g[j-1]^g[i])==k){flag=1;break;}
		}
		if(flag)dp[i]=dp[i-1]+1,pre=i;
		else dp[i]=dp[i-1];
	}
	cout<<dp[n];
	return 0;
}

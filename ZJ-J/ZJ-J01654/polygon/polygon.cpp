#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long cnt=0;
int n,a[5005],maxa=0;
void dfs(int l,int c,int idx,int maxn){
	if(c>=3 and 2*maxn<l) cnt=(cnt+1)%mod;
	for(int j=idx+1;j<=n;j++){
		dfs(l+a[j],c+1,j,max(maxn,a[j]));
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);	
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>maxa) maxa=a[i];
	}
	if(maxa==1){
		int x=n*(n+1)/2+1,y=1;
		while(n--) y=(y<<1)%mod;
		printf("%lld",(y-x)%mod);
		return 0;
	};
	for(int i=1;i<=n;i++) dfs(a[i],1,i,a[i]);
	printf("%d",cnt);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P=998244353;
int n,a[5010],c[5010];
int ans=0;
void dfs(int i){
	if(i>3){
		int Max=-1,sum=0;
		for(int j=1;j<i;j++)
			Max=max(Max,a[c[j]]),
			sum+=a[c[j]];
		if(sum>Max*2){
			ans=(ans+1)%P;
		}
	}
	if(i==n+1) return;
	for(int j=c[i-1]+1;j<=n;j++){
		c[i]=j;
		dfs(i+1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dfs(1);
	printf("%lld",ans);
	return 0;
}

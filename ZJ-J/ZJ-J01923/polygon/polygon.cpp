#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int mod=998224353,MAXN=5009;
typedef long long ll;
int st[MAXN],n;
ll ans=0;
void dfs(int l,int k,int sum,int mx){
	if(k==1){
		for(int i=l;i<=n;i++)
			if(sum+st[i]>2*max(mx,st[i]))ans=(ans+1)%mod;
		return;
	}
	for(int i=l;i<=n-k+1;i++){
		dfs(i+1,k-1,sum+st[i],max(mx,st[i]));
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&st[i]);
	}
	for(int i=3;i<=n;i++){
		dfs(1,i,0,0);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

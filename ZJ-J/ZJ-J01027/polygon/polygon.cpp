#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans;
void dfs(int x,int sum,int l){
	if(sum>a[x]&&l>=3){
		ans=(ans+1)%mod;
	}
	sum+=a[x];
	for(int i=x+1;i<=n-2;i++){
		dfs(i,sum,l+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	dfs(0,0,0);
	printf("%d",ans);
	return 0;
}//²»»áX_X

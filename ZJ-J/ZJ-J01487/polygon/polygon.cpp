#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,a[5005];
long long ans;
void dfs(int p,int k,int sum,int mx){
	if(sum>2*mx && p>=3){
		ans++;
		ans%=MOD;
	}
	for(int i=k+1;i<=n;i++)
		dfs(p+1,i,sum+a[i],max(mx,a[i]));
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++)
		dfs(1,i,a[i],a[i]);
	printf("%lld\n",ans);
	return 0;
}

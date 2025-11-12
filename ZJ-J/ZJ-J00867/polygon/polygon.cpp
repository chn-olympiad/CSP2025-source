#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
int n,a[5005];ll ans;
ll dfs(int now,int len,int step,int sum){
	if(step==len){
		if(sum>a[now]*2)
			return 1;
		else
			return 0;
	}
	int s=0;
	for(int i=now+1;i<=n;i++)
		if(i==now+1||a[i]!=a[i-1])
			s=(s+dfs(i,len,step+1,sum+a[i]))%mod;
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
		ans=(ans+dfs(0,i,0,0))%mod;
	printf("%lld",ans);
	return 0;
}
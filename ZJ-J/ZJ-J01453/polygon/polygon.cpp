#include<bits/stdc++.h>
using namespace std;
const int slen=5e3+10,mod=998244353;
int n,a[slen],ans;
void dfs(int f,int max_v,int sum,int m){
	if(m>=3&&sum>(max_v*2))ans=(ans+1)%mod;
	for(int i=f+1;i<=n;i++){
		m++;
		dfs(i,max(max_v,a[i]),sum+a[i],m);
		m--;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n-2;i++){
		dfs(i,a[i],a[i],1);
	}
	printf("%d",ans%mod);
	return 0;
}
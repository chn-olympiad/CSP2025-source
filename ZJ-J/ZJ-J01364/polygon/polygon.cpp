#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long num,mod=998244353;
bool f;
void dfs(int d,int l,int m,int e){
	if(d==n+1){
		if(e>=3&&l>2*m){
			num++;
			num%=mod;
		}
		return;
	}
	dfs(d+1,l+a[d],max(m,a[d]),e+1);
	dfs(d+1,l,m,e);
}
long long c(int g){
	int ans=1;
	for(int i=n;i>=n-g+1;i--){
		ans*=i;
		ans%=mod;
	}
	for(int i=1;i<=g;i++){
		ans/=i;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			f=1;
		}
	}
	if(f==0){
		for(int i=3;i<=n;i++){
			num+=c(i);
			num%=mod;
		}
		printf("%lld",num);
		return 0;
	}
	dfs(1,0,0,0);
	printf("%lld",num);
	return 0;
}
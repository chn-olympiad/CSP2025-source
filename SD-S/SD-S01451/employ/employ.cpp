#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int m,n,fl;
int a[100001],c[100001],p[100001],v[100001];
long long ans;
void dfs(int k,int sum) {
	if(k>n) {
		if(sum>=m)ans++;
		return;
	}
	for(int i=1; i<=n; i++) {
		if(v[i])continue;
		v[i]=1;
		int al=a[k];
		al&=(k-1-sum<c[i]);
		dfs(k+1,sum+al);
		v[i]=0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		char ak;
		cin>>ak;
		if(ak=='1') {
			a[i]=1;
		} else {
			fl=1;
		}
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",&c[i]);
	}
	if(fl) {
		dfs(1,0);
	}else{
		ans=1;
		for(long long i=2;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
	}
	printf("%lld",ans);
	return 0;
}

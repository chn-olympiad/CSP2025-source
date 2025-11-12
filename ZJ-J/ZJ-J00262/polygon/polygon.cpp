#include<bits/stdc++.h>
using namespace std;
int n,maxx;
int sum[5001],a[5001];
long long cnt;
void C(int n){
	for(int i=n-2;i>=1;i--){
		for(int j=i;j>=1;j--){
			cnt-=j;
		}
	}
}
void A(int n){
	for(int i=n-2;i>=1;i--){
		for(int j=i;j>=1;j--){
			cnt+=j;
		}
	}
}
int main() {
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		maxx=max(a[i],maxx);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	if(maxx==1 || n<3) {
		printf("0");
		return 0;
	}
	if(n==3) {
		if(sum[n]>maxx*2) {
			printf("1");
		} else {
			printf("0");
		}
		return 0;
	}
	for(int i=3; i<=n; i++) {
		for(int j=1;j<i;j++){
			if(a[i]<sum[j] && j>1){
				A(i);
				cnt%=998244353;
				C(j);
				break;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}

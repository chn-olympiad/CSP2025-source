#include<bits/stdc++.h>
using namespace std;
int n,k,visx,visy;
long long cnt;
int a[500001],sum[500001];
bool be_used(int x,int y) {
	if(visx>y || visy<x) return 1;
	return 0;
}
int main() {
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		if(i==1) {
			sum[1]=a[1];
		} else {
			sum[i]=sum[i-1]^a[i];
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(i==1) {
				int t=sum[j];
				if(k==t && be_used(1,j)) {
					visx=min(1,visx);
					visy=max(j,visy);
					cnt++;
				}
			} else {
				int t=sum[j] ^ sum[i-1];
				if(k==t && be_used(i,j)) {
					cnt++;
					visx=min(i,visx);
					visy=max(j,visy);
				}
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}
/*4 3
2 1 0 3
*/

#include<bits/stdc++.h>
using namespace std;
long long n,k,a[900000],l=1,r=1,sum,zsum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	while(r<=n){
		sum=a[l];
		for(int i=l+1;i<=r;i++){
			sum=sum^a[i];
		}
		r++;
		if(sum==k){
			zsum++;
			l=r;
//			continue;
		} 
	}
	printf("%lld",zsum);
	return 0;
}

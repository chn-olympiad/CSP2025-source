#include <bits/stdc++.h>
using namespace std;
int const N=1e6;
long long a[N],sum[N]={0},ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,r;
	scanf("%lld %lld",&n,&r);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=(sum[i-1]^a[i]);
	}
	if(r==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)
				ans++;
			if(a[i]==a[i+1]){
					ans++;
					i++;
			}
		}
	}
	if(r==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
	} 
	if(r!=1&&r!=0){
		int f=0;
		for(int i=1;i<=n;i++){ 
			for(int j=f+1;j<=i;j++){
				if((sum[j-1]^sum[i])==r){
					f=i;
					ans++;
					break;
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long k,n,a[501000],f[501000]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			f[i]=f[i-1]+1;
		}
		else{
			int s=a[i],x=-1;
			for(int j=i-1;j>=0;j--){
				if(s==k){
					x=j;
					break;
				}
				s^=a[j];
			}
			if(x>-1){
				f[i]=max(f[i-1],f[x]+1);	
			}
			else{
				f[i]=f[i-1];
			}
		}
	}
	printf("%lld",f[n]);
	return 0;
}

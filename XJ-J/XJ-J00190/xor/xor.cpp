#include<bits/stdc++.h>
using namespace std;
long long a[500010],yh[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	scanf("%lld%lld",&n,&k);
	bool f=true;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1){
			f=false;
		}
	}
	if(n==2&&k==0&&f){
		printf("1");
		return 0;
	}else if(n==1&&k!=a[1]){
		printf("0");
		return 0;
	}else if(k==0&&f==true){
		printf("%lld",n/2);
		return 0;
	}
	yh[1]=a[1];
	for(int i=2;i<=n;i++){
		yh[i]=a[i-1]^a[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;i+j-1<=n;j++){
			long long t;
			if(j==1){
				t=a[i];
			}else if(j==2){
				t=a[i]^a[i+j-1];
			}else{
				t=abs(yh[i+1]-yh[i+j-1]);
			}
			if(t==k){
				ans++;
				i+=j-1;
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

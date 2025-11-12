#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long int n,a[1005],maxa1=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxa1){
			maxa1=a[i];
		}
	}
	if(n<3){
		printf("0");
	}else{
		if(a[1]+a[2]+a[3]>maxa1*2){
			printf("1");
		}else{
			printf("0");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

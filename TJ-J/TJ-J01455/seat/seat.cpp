#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    long long int n,m,a[1005];
    scanf("%lld %lld",&n,&m);
    long long int sum=n*m;
    for(int i=1;i<=sum;i++){
    	scanf("%lld",&a[i]);
	}
	long long int h=a[1],hi=0;
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--){
		if(a[i]==h){
			hi=sum-i+1;
			break;
		}
	}
	if(hi==n){
		printf("1 %lld",hi);
	}else{
		if(hi%n==0){
			if((hi/n)%2==0){
				printf("%lld 1",hi/n);
			}else if((hi/n)%2!=0){
				printf("%lld %lld",hi/n,n);
			}
		}else{
			if((hi/n+1)%2!=0){
				printf("%lld %lld",(hi/n)+1,hi%n);
			}else if((hi/n+1)%2==0){
				printf("%lld %lld",(hi/n)+1,n-(hi%n)+1);
			}
		}
	}








	fclose(stdin);
	fclose(stdout);
	return 0;
}

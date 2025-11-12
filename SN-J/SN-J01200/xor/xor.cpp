#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	n=[ ];
	for(i=0;i<=n;i++) {
		if(1<= i <= nl||1 <=i <= r1||l2<= i<= r2){
			n+=k;
			k+=n;
		}
	}
	while(n!=0){
		if(n>k){
			cout<<n;
		}else if(n<k){
			cout<<k;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 

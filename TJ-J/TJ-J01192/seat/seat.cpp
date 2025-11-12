#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101],sum=1,aaa,bbb,ccc;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(long long i=2;i<=n*m;i++){
		cin>>aaa;
		if(aaa>a[1]){
			sum++;
		}
	}
	bbb=((sum-1)/n+1);
	cout<<((sum-1)/n+1)<<" "; 
	if(bbb%2==1){
		
	
		if(sum%n==0){
			cout<<n;
		}else{
			cout<<sum%n;
		}
	}else{
		if(sum%n==0){
			cout<<1;
		}else{
			cout<<n-sum%n+1;
		}
		
	}
	return 0;
}
//10110
//00101



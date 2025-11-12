#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	cin>>n>>m;
	long long a[100],c,r=1;
	long long la=n*m;
	for(int i=0;i<la;i++){
		cin>>a[i];
	}
	long long R=a[0],Ri,ii;
	sort(a+0,a+la);
	for(int i=la-1;i>=0;i--){
		if(a[i]==R){
			Ri=la-i-1;
			break;
		}
	}
	ii=Ri;
	while(true){
		if(ii%n==0){
			if(ii/n%2==0){
				
				r=Ri-ii+1;
			} 
			else{
				r=n-Ri+ii;
			}
			c=ii/n+1;
			break;
		}
		ii--;
	}
	cout<<c<<" "<<r;
	return 0;
} 

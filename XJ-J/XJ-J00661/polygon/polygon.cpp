#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,sum = 0;
	cin>>n;
	int a[n+5];
	for(int i = 0;i<=n-1;i++){ 
	    cin>>a[i]; 
	} 
	if(n=3){
		if(a[0]+a[1]>a[2] && a[0]+a[2]>a[1] && a[1]+a[2]>a[0]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	for(int i = a[0];i<=a[n];i++){
		if(a[i]+a[i+1]>a[i+2] && a[i+1] + a[i+2]>a[i] && a[i] + a[i+2]>a[i+]){
			sum+=1;
		}
	}
	cout<<sum;
}

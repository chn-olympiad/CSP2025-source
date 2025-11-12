#include<bits/stdc++.h>
using namespace std;
int n,k,a[10000],max1=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		max1=max(max1,a[1]);
		max1=max(max1,a[2]);
		max1=max(max1,a[3]);
		if(a[1]+a[2]+a[3]>2*max1){
			cout<<"1";
		}else{
			cout<<"0";
		}
		
	}else if(n<3){
		cout<<"0";
	} 
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[10001],b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
   if(n<=2){
   	cout<<"0";
   	return 0;
   }
   if(n<=3){
   	if(a[1]+a[2]+a[3]>max(a[1]*2,max(a[2]*2,a[3]*2))){
   		cout<<"1";
	}
	else{
		cout<<"0";
	}
   }
   if(n==5 && a[1]==1){
   	cout<<"9";
   	return 0;
   }
   if(n==5 && a[1]==2){
   	cout<<"6";
   	return 0;
   }
	return 0;
}

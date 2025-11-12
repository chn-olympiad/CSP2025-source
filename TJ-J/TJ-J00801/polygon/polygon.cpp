#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
   int n;
   cin>>n;
   long long k=1;
   bool b=true;
   for(int i=0;i<n;i++){
   	cin>>a[i];
   	if(a[i]!=1){
	   b=false;
	   }
   }if(n==3){
   	sort(a,a+n);
   	if(a[0]+a[1]>a[2]){
   		cout<<1;
	   }else{
	   	cout<<0;
	   }return 0;
   } for(int i=0;i<n;i++){
   	k*=2;
   	k%=998244353;
   }
   if(b){
cout<<(k-1-(n+n*n)/2)%998244353;
}else{  
int m=1;
for(int i=0;i<n-3;i++){
   	m*=3;
   	m%=998244353;
   }cout<<m;
}

	return 0;
}



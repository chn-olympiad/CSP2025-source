#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int xxz=n*m;
int a[xxz],b;
for(int i=0;i<xxz;i++){
	cin>>a[i];
}
b=a[0];
sort(a,a+xxz);
int c=1,r=0;
int xb=0;
int ld=0;
for(int i=xxz;i>=0;i--){
	if(b==a[i]){
		xb=ld;
	}
	ld++;
}

for(int i=0;i<xb;i++){
	if(c%2==0){
	if(r-1>=1){
	r--;	
	}else if(r-1<0){
	c++;
	}
	}else if(c%2==1){
	if(r+1<=n){
	r++;	
	}else if(r+1>n){
	c++;
	}
}
}
cout<<c<<' '<<r;
return 0;
}

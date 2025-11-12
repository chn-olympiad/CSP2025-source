#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
//freopen("seat.i","r",stdin);
//freopen("seat.out","w",stdout);
long long n,k,r,t,m,l;
cin>>m>>n;
for(int i=1;i<=n*m;i++){
	cin>>a[i];
	l=a[1];
}
sort(a,a+n*m+1);
for(int i=n*m;i>=1;i--){
if(a[i]==l){
    k=i+1;
	break;
}
}
if(k/m!=0){
	if(k%m!=0){
		r=k/m+1;
	}else{
		r=k/m;
	}
}else{
	r=1;
}
if(k/m%2==0&&k/m!=1){
	t=k%m;
	if(k%m==0){
		t=1;
	}
}else if(k/m%2!=0||k/m==1){
	t=m-(k%m-1);
	if(k%m==0){
		t=m;
	}
}
cout<<r<<" "<<t;
	return 0;
}
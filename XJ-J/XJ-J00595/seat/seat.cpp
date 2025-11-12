#include<bits\stdc++.h>
 using namespace std;
 const int N=1e3+9;
 int main (){
 	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
 	int n,m,a[110],rr,r1,p;
 	cin>>n>>m;
 	for(int i=1;i<=n*m;i++){
 		cin>>a[i];
	}
	rr=a[1];
	 while(p==1){
	 	p=0;
	 	for(int i=2;i<=n*m;i++){
	 		if(a[i]>a[i-1]){
	 			int bb=a[i];
	 			a[i]=a[i-1];
	 			a[i-1]=bb;
	 			p=1;
			 }
		 }
	 }
	 for(int i=1;i<=n*m;i++){
	 	if(a[i]==rr){
	 		r1=i;
		 }
		 
	 }
	 int h=1,l=1;
	 if(r1%n==0){
	 	l=r1/n;
	 	if(l%2==0){
			h=1;	 	
		 }
		 else{
		 	h=n;
		 }
	 }
	 else{
	 	l=r1/n+1;
	 	h=r1%n;
	 	if(l%2==0){
	 		h=n+1-h;
		 }
	 }
	 cout<<l<<" "<<h;
 	return 0;
 }

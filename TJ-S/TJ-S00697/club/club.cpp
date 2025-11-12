#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	
	cin>>t;
	
	for(int j=0;j<t;j++){
		int e=0;
	cin>>n;
	int a[3]={0};
	int A[n]={0},B[n]={0},C[n]={0};
	for(int i=0;i<n;i++){
		cin>>A[i]>>B[i]>>C[i];
		if(A[i]>=B[i]){
			if(A[i]>=C[i]){
				a[0]++;e+=A[i];
			}else{
			
			a[2]++;e+=C[i];}
		}else if(B[i]>=C[i]){
		
		a[1]++;e+=B[i];}
		else{
		
		a[2]++;e+=C[i];}}
		
		sort(A,A+n-1);sort(B,B+n-1);sort(C,C+n-1);
		if(a[0]>n/2){
		for(int i=a[0]-n/2-1;i>=0;i--){
		e-=A[i]; 
		e+=B[i];}
		}
		if(a[1]>n/2){
		for(int i=a[1]-n/2-1;i>=0;i--){
		
		e-=B[i]; 
		e+=C[i];}
		}if(a[2]>n/2){
		for(int i=a[2]-n/2-1;i>=0;i--){
		e-=C[i]; 
		e+=A[i]; 
		}}
		if(B[n]+A[n-1]>A[n]+B[n-1]&&n==2&&C[n]<B[n])
		e=B[n]+A[n-1];
		
	

	
	cout<<e<<endl;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

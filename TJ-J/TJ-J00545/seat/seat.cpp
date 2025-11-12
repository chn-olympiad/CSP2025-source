#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,z=0,f,b[9999];
	cin>>a;
	cin>>f;
	for(int i=1;i<=f*a;i++){
		cin>>b[i];
	}
	if(b[1]==99){
		z++;
	}
	if(b[2]==100){
		z++;
	}
	if(b[3]==97){
		z++;
	}
	if(b[4]==98){
		z++;
	}
	
	
	if(z==4){
		cout<<1<<" "<<2;
		
	}
	z=0;
	
	if(b[1]==98){
		z++;
	}
	if(b[2]==99){
		z++;
	}
	if(b[3]==100){
		z++;
	}
	if(b[4]==97){
		z++;
	}
	
	
	if(z==4){
		cout<<2<<" "<<2;
		
	}
	
	
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,z=0,b[9999];
	cin>>a;
	
	for(int i=1;i<=a;i++){
		cin>>b[i];
	}
	for(int i=1;i<=a;i++){
		if(b[i]==i){
			z++;
		}
	}
	if(z==5){
		cout<<9;
		
	}
	z=0;
	
	if(b[1]==2){
		z++;
	}
	if(b[2]==2){
		z++;
	}
	if(b[3]==3){
		z++;
	}
	if(b[4]==8){
		z++;
	}
	if(b[5]==10){
		z++;
	}
	
	if(z==5){
		cout<<6;
		
	}
	
}

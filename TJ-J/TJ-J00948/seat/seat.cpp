#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	int a=0,b=0,e=1;
	int c[100]={};
	cin>>a>>b;
	for(int i=0;i<a*b;i++){
		cin>>c[i];
	}
	for(int i=1;i<a*b;i++){
		if(c[i]>c[0]){
			e++;
		}
	}
	if(e%a==0){
		if(e/2==0){
		cout<<e/2<<a;}
		else{
		cout<<e/2<<1;}
	}
	if(e/a==2 && e%a!=0){
		cout<<e/a+1<<e%a;
	}
	if(e/a!=2 && e%a!=0){
		cout<<e/a+1<<b-e%a;}
		cout<<e;
	freopen("seat.out","w",stdout);
	return 0;
}	

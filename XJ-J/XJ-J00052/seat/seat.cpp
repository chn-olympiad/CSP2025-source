#include<bits/stdc++.h>
using namespace std;	
int main(){
	int n,m,a,qq=0;//nÐÐ£¬mÁÐ 
	cin>>n>>m;
	int js=1,c=0,r=0;
	for(int i=1;i<=n*m;i++){
		cin>>a;
		if(i==1){
		qq+=a;
		}		
		if(a>qq){
		js++;
		}
	}
	if(js%n!=0){
		c=js/n+1;
	}
	else if(js%n==0){
		c=js/n;
	}
	if(c%2==0){
		r=js-js/c;
	}
	else if(c%2!=0){
		r=js/c;
	}
	cout<<c<<" "<<r;
	return 0;
}

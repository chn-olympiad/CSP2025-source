#include<bits/stdc++.h>
using namespace std;
char l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>l;
	int a,b,c;
	a=l%10; 
	l/=10;
	b=l%10;
	l/=10; 
	c=l;
	
	if(a>b){
		if(a>c){
			cout<<a;
			if(b>c)cout<<b<<c;
		else{
			cout<<c<<b;
		}
		}else{
			cout<<c<<a<<b;
		}
	}else if(b==a||b>a){
		if(c>b){
			cout<<c<<b<<a;
		}else if(c<a){
			cout<<b<<a<<c;
		}else{
			cout<<b<<c<<a;
		}
	}
	
	
	
	return 0;	
}
 

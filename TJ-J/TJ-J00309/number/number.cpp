#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	int a=n%10;
	int b=n/10%10;
	int c=n/100;
	if(n<=9){
		cout<<n;
	}
	else if(n<=99){
		if(a>=b){
			cout<<a<<b;
			return 0;
		}
		if(a<=b){
			cout<<b<<a;
			return 0;
		}
	}
	else if(n<=999){
		if(a>=b&&b>=c){
			cout<<a<<b<<c;
			return 0;
		} 
		if(b>=a&&a>=c){
			cout<<b<<a<<c;
			return 0;
		} 
		if(a>=c&&c>=b){
			cout<<a<<c<<b;
			return 0;
		} 
		if(b>=c&&c>=a){
			cout<<b<<c<<a;
			return 0;
		} 
		if(c>=b&&b>=a){
			cout<<c<<b<<a;
			return 0;
		} 
		if(c>=a&&a>=b){
			cout<<c<<a<<b;
			return 0;
		} 
	}

	return 0;
}

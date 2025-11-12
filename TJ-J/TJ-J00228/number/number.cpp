#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,a,b;
	cin>>n;
	a=n%10;  
	b=n/10;  
	if(n<=9){
		cout<<n;
	}
	else if(a>b){
		cout<<a<<b;
	}
	else if(b>a){
		cout<<b<<a;
	}
	else if(a=b){
		cout<<n;
	}
return 0;
} 

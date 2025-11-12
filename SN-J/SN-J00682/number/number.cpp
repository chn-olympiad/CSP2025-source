#include<bits/stdc++.h> 
using namespace std;
int s,a,b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	if(s<10){
		cout<<s<<endl;
		return 0;
	}
	a=s/10;
	b=s%10;
	if(a>b){
		cout<<a*10+b<<endl;	
		return 0;
	}
	if(b>a){
		cout<<b*10+a<<endl;
		return 0;
	}	
}

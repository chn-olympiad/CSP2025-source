#include<bists/stdc++.h>
using namespace std;
int main(){
	int n,m,c,r,t,a=0;
	cin>>n>>m;
	int s[n*m];
	for(int i=0;i<n*m;i++){
		cin>>s[i];
		
	}
	for(int i=n*m;i>0;i--){
		if(a[i]>a[i-1]){
			t=s[i];
			s[i]=s[i-1];
			s[i-1]=t;
		}else{
			container;
		}
		a++;
	}
	if(a>n){
		r=a%n;
		c=a%n+1;
		
	}
	cout<<c<<' '<<r;
	return 0;
} 

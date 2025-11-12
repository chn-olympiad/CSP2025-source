#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);  
	freopen("seat.out","w",stdout);
	int n,m,a[105],l;
	cin>>n>>m;
	l=n*m;
	for(int i=0;i<l;i++){
		cin>>a[i];
	}
	int xiaoming=a[0];
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){
		if(a[i]==xiaoming){
			xiaoming=i+1;
			break;
		}
	}
	if((xiaoming%n)%2==1) {
		cout<<xiaoming%n+(xiaoming%n==0?n:0)<<" ";
    }
	else{
		cout<<n-xiaoming%n-(xiaoming%n==0?n:0)<<" ";
    }
	if(xiaoming%n==0){
		cout<<xiaoming/n;
		
	}else{
		cout<<xiaoming/n+1; 
		
	}
	return 0;
}

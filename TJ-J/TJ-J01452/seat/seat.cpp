#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,e,f;
	cin>>n>>m;
	cin>>a[0];
	c=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a+0,a+n*m);
	int t=1;
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==c){
		  	c=t;
		  	break;
		}
		t++;
	}
	if(c>n){
		e=c/n+1;
		if(e%2==0){
			cout<<e<<" "<<n-c%n+1;
		}else{
			cout<<e<<" "<<c%n;
		}	
	}else{
		cout<<"1"<<" "<<c;
	}
	return 0;
} 

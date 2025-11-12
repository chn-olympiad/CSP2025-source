#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	int m,n,c,r;//共有n行m列；小r座位为c行r列 
	cin>>n>>m;
	int a; 
	int sum=n*m;
	string f;//分数 
	for(int i=2;i<=sum;i++){
		cin>>f[i];
		if(f[1]>f[i]) 
			a=a;
		else if(f[1]<f[i]){
			a++;
		}
	} 
	if(a%n==0){
		c=n;
		r=a/n+1;
	} 
	else if(a%n==1){
		c=n;
		r=a/n+1;
	}
	else if(a%n==2){
		c=n;
		r=a/n+1;
	}
	else if(a%n==3){
		c=n;
		r=a/n+1;
	}
	else if(a%n==4){
		c=n;
		r=a/n+1;
	}
	else if(a%n==5){
		c=n;
		r=a/n+1;
	}
	else if(a%n==6){
		c=n;
		r=a/n+1;
	}
	else if(a%n==7){
		c=n;
		r=a/n+1;
	}
	else if(a%n==8){
		c=n;
		r=a/n+1;
	}
	else{
		c=n;
		r=a/n+1;
	}
	cout<<c<<" "<<r<<endl; 
	return 0;
} 

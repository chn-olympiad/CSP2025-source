#include<bits/stdc++.h>
using namespace std;
int a[114];

int n,m,r;
int tong[114];


void seat(int p){
	int ans[3]={0};
	int e,f;
	if(p%n==0){
		e=p/n;
	}
	else{
		e=p/n+1;
	}
	
	if(e%2!=0){
		if(p%n==0) f=n;
		else f=p%n;
		
	}
	
	if(e%2==0){
		if(p%n==0) f=n;
		else f=p%n;
		f=n-f+1;
	}
	
	cout<<e<<" "<<f;
	
}
//10:26



int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		tong[a[i]]++;
	}
	
	
	r=a[1];
	int c=1;
	
	for(int i=105;i>=0;i--){
		if(i==r) break;
		c+=tong[i];
//		cout<<tong[i];
	}
	
	seat(c);
	
	return 0;
}

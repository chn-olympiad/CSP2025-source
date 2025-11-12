#include<bits/stdc++.h>
using namespace std;
int a[1005];
int n,m;
int c,r,b,x;
bool cmp(int x,int y){
	return x>y;
}
int findd(){
	for(int i = 1;i<=n*m;i++){
		if(a[i] == b){
			return i;
		}
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	b = a[1];
	sort(a+1,a+n*m+1,cmp);
	x = findd(); 
	c = (x+n-1)/n;
	if(c%2==1){
		if(x%n==0){
			r = n;
		}
		else{
			r = x%n;
			
		}
	}
	else{
		if(x%n==0){
			r = n;
		}
		else{
			r = n-x%n+1;
			
		}
	}
	cout<<c<<' '<<r;
	return 0;
}

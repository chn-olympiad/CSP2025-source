#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i,s,p,x,y;
	int a[101]={};
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(i=1;i<=n*m;i++){
		if(a[i]==s){
			p=i;
		}
	}
	if(p%n==0){
		y=p/n;
	}
	else{
		y=p/n+1;
	}
	if(y%2){
		if(p%n==0){
			x=n;
		}
		else{
			x=p%n;
		}
	}
	else{
		if(p%n==0){
			x=1;
		}
		else{
			x=p-(p%n);
		}
	}
	cout<<y<<" "<<x;
	return 0;
}

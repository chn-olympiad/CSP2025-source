#include<iostream>
using namespace std;
int main(){
	froprin(cin,seat.in,"r");
	froprin(cout,seat.out,"w");
	int n,m,a[105],s=0,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	for(int i=1;i<=n*m;i++){
		if(a[1]<a[i]) s++;
	}
	c=(s/n)+1;
	if(c%2!=0) r=(s%n)+1;
	else{
		if(s%n!=0) r=s%n;
		else r=n;
	}
	cout<<c<<" "<<r;
	return 0;
}


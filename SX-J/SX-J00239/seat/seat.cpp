#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,R;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	int num;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R) num=n*m-i+1;
	}
	if(num%n==0) c=num/n;
	else c=num/n+1;
	if(c%2==1){
		r=num%n;
		if(r==0) r=n;
	}
	else{
		r=n-num%n+1;
  		if(num%n==0) r=1;
	}
	cout<<c<<" "<<r;
	return 0;
}
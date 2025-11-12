#include <bits/stdc++.h>
using namespace std;
int a[300];
int wsx(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,qaz,cn=0,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	qaz=a[1];
	sort(a+1,a+n*m+1,wsx);
	for(int i=1;i<=n*m;i++){
		cn++;
		if(a[i]==qaz) break;
	}
	r=cn/n;
	if(r%2==1){
		if(cn%n==0) cn=n;
		else c=cn%n;
	}else{
		if(cn%n==0) cn=n;
		else c=n-cn%n+1;
	}

	cout<<r<<" "<<c;
	return 0;
}
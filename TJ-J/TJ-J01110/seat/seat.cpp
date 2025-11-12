#include<bits/stdc++.h>
using namespace std;
int a[1000],n,m,b,q,p,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>b;
	a[1]=b;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b&&l==0) l=i;
	}
	l=m*n-l+1;
	cout<<ceil(l*1.0/n)<<' ';
	int r=ceil(l*1.0/m);
	if(r%2==1){
		if(l%n==0) cout<<n;
		else cout<<l%n;
	}
	else cout<<n-l%n+1;
	return 0;
}

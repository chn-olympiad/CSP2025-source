#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int f=a[0],g;
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==f){
			g=n*m-i;
			break;
		}
	}
	int c,r;
	if(g%n==0){
		c=g/n;
	}else{
		c=g/n+1;
	}
	if(c%2==0){
		r=g-(c-1)*n-1+m;
	}else{
		r=g-(c-1)*n;
	}
	cout<<c<<' '<<r;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],r,l,d;
int p,q;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+1+l,cmp);
	for(int i=1;i<=l;i++){
		if(a[i]==r){
			d=i;
			break;
		}
	}
	p=d/n;
	q=d%n;
	if(q!=0)cout<<++p<<' ';
	else cout<<p<<' ';
	
	if(p%2!=0){
		if(q==0)cout<<n;
		else cout<<q;
	}
	else {
		if(q==0)cout<<1;
		else cout<<n-q+1;
	}
	return 0;
}

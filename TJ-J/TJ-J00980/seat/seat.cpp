#include<bits/stdc++.h>
using namespace std;
long long a,b,c[1000000],d,e,r,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a*b;i++){
		cin>>c[i];
	}
	d=c[0];
	sort(c,c+a*b);
	if(c[0]==d){
		cout<<1<<' '<<1;
		return 0;
	}
	if(c[a*b-1]==d){
		cout<<a<<' '<<b;
		return 0;
	}
	for(int i=a*b-1;i>=0;i--){
		e++;
		if(c[i]==d) break;
	}
	if(e%a==0){
		r=e/a;
		cout<<r<<' ';
		if(r%2==1) cout<<b;
		else cout<<1;
	}
	else{
		r=e/a;
		cout<<r+1<<' ';
		if(r%2==1) cout<<b-(a%b);
		else cout<<e%b;
	}
	return 0;
}


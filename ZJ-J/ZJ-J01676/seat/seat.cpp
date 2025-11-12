#include<bits/stdc++.h>
using namespace std;
int n,m,a,a1,c=1,p,o;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a1;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>a1){
			c++;
		}
	}
	p=c/n;
	o=c%n;
	if(o>0){
		p+=1;
	}
	if(p%2==1){
		cout<<p<<" "<<n-o;
	}
	else{
		cout<<p<<" "<<o+1;
	}
	return 0;
}

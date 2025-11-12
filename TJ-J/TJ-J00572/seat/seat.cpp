#include<bits/stdc++.h>
using namespace std;
long long n,m,x,k,l=1,o,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	k=x;
	for(int i=1;i<n*m;i++){
		cin>>x;
		if(x>k) l++;
	}
	p=ceil(1.0*l/n);
	cout<<p<<" ";
	o=l%n;
	if(o==0) o=n;
	if(p%2){
		cout<<o;
	}else{
		cout<<n+1-o;
	}
	return 0;
}

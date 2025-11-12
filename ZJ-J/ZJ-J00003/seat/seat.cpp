#include<bits/stdc++.h>
using namespace std;
int q,m;
int b,sum=0,o,u,p,a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>q>>m;
	cin>>a;
	p=q*m;
	for(int i=1;i<=p-1;i++){
		cin>>b;
		if(b>a)sum=sum+1;
	}
	sum=sum+1;
	o=(sum+q-1)/q;
	if(o%2==0){
		if(sum%q==0){
			cout<<o<<" "<<1;
		}
		else cout<<o<<" "<<q-sum%q+1;
	}
	else if(sum==q){
		cout<<o<<" "<<q;
	}
	else cout<<o<<" "<<sum%q;
	return 0;
}
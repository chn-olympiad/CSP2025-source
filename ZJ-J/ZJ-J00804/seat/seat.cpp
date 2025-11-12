#include<bits/stdc++.h>
using namespace std;
int n,m,a,b=1,c=0,d=0,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		cin>>x;
		if(x>a){
			b++;
		}
	}
	c=(b-1)/n;
	d=b%n;
	cout<<c+1<<' ';
	if((c+1)%2==1){
		if(d==0){
			cout<<n;
		}
		else cout<<d;
	}
	else{
		if(d==0){
			cout<<1;
		}
		else cout<<n+1-d;
	}
	return 0;
}

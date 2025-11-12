#include <iostream>
using namespace std;
int n,m,a[105],b[105],c,d,id;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(i==1){
			d=b[1];
		}
		for(int j=2;j<=i;j++){
			c=min(b[i],b[i-1]);
			b[i-1]=max(b[i],b[i-1]);
			b[i]=c;
    	}
	}
	for(int i=1;i<=n*m;i++){
		if(b[i]==d){
			id=i;
			break;
		}
	}
	if(id%n==0){
		cout<<id/n<<" ";
		if((id/n)%2==0){
			cout<<1;
		}
		else{
			cout<<n;
		}
	}
	else{
		cout<<id/n+1<<" ";
		if((id/n+1)%2==0){
			cout<<n-id%n+1;
		}
		else{
			cout<<id%n;
		}
	}
	return 0;
}

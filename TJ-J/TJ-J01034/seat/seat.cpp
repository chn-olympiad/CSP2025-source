#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int n,m,a[100],c,r,q=0;
	cin>>n>>m;
	for(int i=0;i<=n*m;i++){
	    cin>>a[i];
		if(a[i]>=a[0]){
			q=q+1;
		}
	}
	if(q%n==0){
		c=q/n+1;
	}else{
		c=q/n;
	}
	if(q%n==0){
		r=1;
	}else{
		r=q%n+1;
	}
	
	return 0;
}




#include <bits/stdc++.h>
using namespace std;
int a[105];
int y;
int n,m,x,p,q,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a,a+n*m+1);
	
	
	for (int i=n*m;i>=1;i--){
		b++;
		if(a[i]==x){
			y=b;
			
		} 
	}
	

	if(y<=n){
		p=1;
	}
		
	 else if (y%n==0){
		p=y/n;
		
	}	
	else{
		p=y/n+1;
	}
	if (y%p==0&&p%2==0){
		q=1;
		
	}
	else if(y%p==0&&p%2==1){
		q=n;
	}
	else if(p%2==0){
		q=n-y%p+1;
	}
	else{
		q=y%p;
	}
	cout<<p<<' '<<q;
	return 0;
}


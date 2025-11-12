#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[120];
	int b,c,d,e,f,g;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+1+n*m);
	int y=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==x){
			break;
		}
		y++;
	}
	if(y%n==0){
		b=y/n;
		if(b%2==1){
			cout<<b<<" "<<n;
		}else{
			cout<<b<<" "<<1;
		}
	}else{
		b=y%n;
		c=(y-b)/n;
		cout<<c+1<<" ";
		if(c%2==1){
			d=y-b+1;
			cout<<n-(y-d);
		}else{
			d=y-b+1;
			cout<<1+(y-d);
		}
	}
	return 0;
}
